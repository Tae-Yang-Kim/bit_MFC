//질문할것
//핸들이란 : 응용프로그램의 위치를 알려주는 역할을 하는 무언가
//
#include <Windows.h> //windows헤더파일 선언

//WndProc정의
//콜백함수 정의 
//wndproc -> Winmain이 아닌 윈도우즈에 의해 호출되는 함수
//Winmain내의 메시지루프는 메시지처리 함수로 전달되지만 WndProc는 메시지가 입력되면 윈도우즈에 호출되어 메시지를 처리
//WndProc의 인수는 모두 4개이며 MSG 구조체의 멤버
//HWND -> 메시지를 받을 윈도우의 핸들
//UINT -> iMsg : 어떤 종류의 메시지인가? WM_MOVE면 윈도우 이동 WM_LBUTTONDOWN 마우스왼쪽클릭
//WPARAM -> iMessage의 부가적인정보 WM이 생겼을 때 키보드의 상태나 어떤 좌표에서 클릭됬는지 등의 데이터값이 넘어감
//LPARAM -> 위와 같음
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC			hdc;
	PAINTSTRUCT ps;
	RECT		rect;

	//메시지 핸들러
	switch (iMsg) {
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		//hdc=get(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "hello, Windows!", -1, &rect, 
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 100, 100);
		ReleaseDC(hwnd, hdc);
		return 0;
	/*case WM_CLOSE:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 100, 100);
		ReleaseDC(hwnd, hdc);
		Sleep(2000);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	*/
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

//Winmain의 함수
//hInstance -> 프로그램의 인스턴스 핸들
//hPrevInstance -> 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들
//lpCmdLine -> 명령행으로 입력된 프로그램 인수이다. 도스의 argv인수에 해당한다.
//mCmdShow -> 프로그램이 실행될 형태 최소화 보통모양등이 전달
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;
	//각종 윈도우 클래스 설정값
	wndclass.cbSize			= sizeof(wndclass);
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
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
	//UpdateWindow(hwnd);

	//PeekMessage를 사용함으로써 윈도우즈로부터 메시지가 않오면 idle로 돌려 CPU점유율을 낮춘다
	//GetMessage를 사용하면 계속 대기하기때문에 CPU점유율이 100%가 된다.
	/*
	while (GetMessage(&msg, NULL, 0, 0)) {
		//TranslateMessage(&msg);
		static int i = 0;
		char buffer[80];
		wsprintf(buffer, "i\n", ++i);
		OutputDebugString(buffer);
		DispatchMessage(&msg);
	}*/
	while (1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)break;
			DispatchMessage(&msg);
		}
		static int i = 0;
		char	buffer[8];
		wsprintf(buffer, "i\n", ++i);
		OutputDebugString(buffer);
	}
	return msg.wParam;
}