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

//������ Ŭ�������� �����ϴ� �͵��� �� �׷��� �ִ��� ������ �غ���.
