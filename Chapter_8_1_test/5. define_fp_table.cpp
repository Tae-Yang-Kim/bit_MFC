#include <windows.h>

//왜 define을 하는가? -> cobject에 상속받을 클래스들은 cview만 있는것이 아니라 여러개가 있는데
//이것을 자동화 하기 위함이다.
#define DECLARE_MESSAGE_MAP()		static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name)	MessageMap\
		class_name::messageMap[] = {
#define END_MESSAGE_MAP()			{0,NULL}};

LRESULT	CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
class CObject {
protected:
	static char szAppName[];
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();

	//이렇게 CObject에는 메시지 핸들러가 필요가 없게 된다
	//따라서 가상함수를 선언해도 되지 않아도 된다.
};

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);
	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}

void CObject::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "HelloWin";

//이제 메시지맵을 만든다
class CView;
typedef void (CView::*CViewFunPointer)();
typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

class CView : public CObject {
public:
	void OnCreate();
	void OnDraw();
	void OnDestroy();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CView)
{WM_CREATE,CView::OnCreate},
{WM_PAINT,CView::OnDraw},
{WM_DESTROY,CView::OnDestroy},
END_MESSAGE_MAP()

void CView::OnCreate() {

}

void CView::OnDraw() {
	HDC		hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	hdc = BeginPaint(hwnd, &ps);

	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CView::OnDestroy() {
	PostQuitMessage(0);
}

CView app;

LRESULT	CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	int i = 0;
	while (0 != CView::messageMap[i].iMsg) {
		if (iMsg == CView::messageMap[i].iMsg) {
			fpCViewGlobal = CView::messageMap[i].fp;
			(app.*fpCViewGlobal)();
			return 0;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam );
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}
