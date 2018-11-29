#pragma once
#include <Windows.h>

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
};