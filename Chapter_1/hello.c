

#if 1
#include<windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	static int i = 0;

	switch (iMsg) {
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		i++;
		rect.bottom += i;
		rect.left += i;
		DrawText(hdc, "Hello, Windows", -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		/*hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, i, i);
		i++;
		ReleaseDC(hwnd, hdc);
		Sleep(100);*/
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc; //WndProc 윈도우 자체에서 지정해주는 프록시져
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDI_APPLICATION);
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
		hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	/*while (GetMessage(&msg, NULL, 0, 0)) {
		DispatchMessage(&msg);
	}*///while
	while (1) {
		/*if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				break;
			}

			DispatchMessage(&msg);
		}*/
		if (GetMessage(&msg, NULL, 0, 0)) {
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		static int i = 0;
		char buffer[8];
		wsprintf(buffer, "%d\n", ++i);
		OutputDebugString(buffer);

	}
	return 0;
}//WinMain()
#endif


//윈도우 클래스 생성
#if 0
#include<windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = DefWindowProc; //WndProc 윈도우 자체에서 지정해주는 프록시져
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);
	
	return 0;
}//WinMain()
#endif

//main의 인자값 전달
#if 0
#include<stdio.h>
int main(int argc, char **argv) {
	int i;
	for (i = 0; i < argc; i++)
		printf("argc[%d] = %s\n", i, argv[i]);
}

#endif

//std_call 방식
#if 0
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	MessageBox(NULL, "Hello World", "Hello", MB_OK);
	return 0;
}
#endif

//cdecl_call 방식
#if 0
#include<Windows.h>

int main() {
	MessageBox(NULL, "Hello Wrold", "Hello", MB_OK);
}
#endif

#if 0
#include<stdio.h>

int main() {
	printf("Hello world!");
	return 0;
}
#endif