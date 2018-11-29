//1���� �ߴ� C��§ API�� Ŭ����ȭ �Ͽ� �и��ߴ�.
#include<Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CApp {
	static char szAppName[];
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	//�ʱ�ȭ
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	//GetMessage
	void Run();
	//�����ڵ带 ����
	WPARAM ExitInstance();

	//message Handler
	//�޽��� �ڵ鷯 switch������ �����Ǵ� �ൿ�� �ǹ�
	void OnCreate();
	void OnDraw();
	void OnDestroy();
};

//�ʱ�ȭ�� ����
void CApp::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
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

void CApp::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CApp::ExitInstance() {
	return msg.wParam;
}

char CApp::szAppName[] = "HelloWin";

void CApp::OnCreate() {
}

void CApp::OnDraw(){
	HDC			hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CApp::OnDestroy() {
	PostQuitMessage(0);
}

CApp app;

LRESULT	CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE:
		app.OnCreate();
		return 0;
	case WM_PAINT:
		app.OnDraw();
		return 0;
	case WM_DESTROY:
		app.OnDestroy();
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstane, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();

	return app.ExitInstance();
}