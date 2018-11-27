//�����Ұ�
//�ڵ��̶� : �������α׷��� ��ġ�� �˷��ִ� ������ �ϴ� ����
//
#include <Windows.h> //windows������� ����

//WndProc����
//�ݹ��Լ� ���� 
//wndproc -> Winmain�� �ƴ� ������� ���� ȣ��Ǵ� �Լ�
//Winmain���� �޽��������� �޽���ó�� �Լ��� ���޵����� WndProc�� �޽����� �ԷµǸ� ������� ȣ��Ǿ� �޽����� ó��
//WndProc�� �μ��� ��� 4���̸� MSG ����ü�� ���
//HWND -> �޽����� ���� �������� �ڵ�
//UINT -> iMsg : � ������ �޽����ΰ�? WM_MOVE�� ������ �̵� WM_LBUTTONDOWN ���콺����Ŭ��
//WPARAM -> iMessage�� �ΰ��������� WM�� ������ �� Ű������ ���³� � ��ǥ���� Ŭ������� ���� �����Ͱ��� �Ѿ
//LPARAM -> ���� ����
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC			hdc;
	PAINTSTRUCT ps;
	RECT		rect;

	//�޽��� �ڵ鷯
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

//Winmain�� �Լ�
//hInstance -> ���α׷��� �ν��Ͻ� �ڵ�
//hPrevInstance -> �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ�
//lpCmdLine -> ��������� �Էµ� ���α׷� �μ��̴�. ������ argv�μ��� �ش��Ѵ�.
//mCmdShow -> ���α׷��� ����� ���� �ּ�ȭ ��������� ����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;
	//���� ������ Ŭ���� ������
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

	//PeekMessage�� ��������ν� ��������κ��� �޽����� �ʿ��� idle�� ���� CPU�������� �����
	//GetMessage�� ����ϸ� ��� ����ϱ⶧���� CPU�������� 100%�� �ȴ�.
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