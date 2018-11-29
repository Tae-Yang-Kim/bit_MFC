#include<windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject{
protected:
	static char szAppName[];
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	//초기화
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCMdShow);
	//getmessage
	void Run();
	//종료
	WPARAM ExitInstance();

	//메시지 핸들러
	virtual void OnCreate() = 0;
	virtual void OnDraw() = 0;
	virtual void OnDestroy() = 0;
	virtual void OnLButtonDown() = 0;
}; //class CObject;

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

//공통 적인 기능을 미리 CObject에 만들어서 가상함수로 구현한두
//쓸일이 있으면 그것에 오버라이딩하여 구현한다
CObject* pCObject;

class CView : public CObject {
public:
//COject에서 미리 받아놓은 
	void OnCreate();
	void OnDraw();
	void OnDestroy();
	void OnLButtonDown();
};

void CView::OnCreate() {

}

void CView::OnDraw() {
	HDC		hdc;
	PAINTSTRUCT ps;
	RECT	rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CView::OnDestroy() {
	PostQuitMessage(0);
}

void CView::OnLButtonDown() {
	MessageBox(NULL, "MESSAGE", "TITLE", MB_ICONEXCLAMATION | MB_OK);
}

CView app;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE:
		pCObject->OnCreate();
		return 0;
	case WM_PAINT:
		pCObject->OnDraw();
		return 0;
	case WM_DESTROY:
		pCObject->OnDestroy();
		return 0;
	case WM_LBUTTONDOWN:
		pCObject->OnLButtonDown();
		return 0;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	pCObject = &app;
	pCObject->InitInstance(hInstance, szCmdLine, iCmdShow);
	pCObject->Run();
	return pCObject->ExitInstance();
}