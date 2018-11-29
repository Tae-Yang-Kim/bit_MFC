#pragma once
#include <Windows.h>
class CObject {
protected:
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;
public:
	int cxIcon, cyIcon;
	HICON hIcon;
	HINSTANCE hInst;
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();
};

//각각의 클래스에서 정의하는 것들을 왜 그렇게 넣는지 생각을 해보자.
