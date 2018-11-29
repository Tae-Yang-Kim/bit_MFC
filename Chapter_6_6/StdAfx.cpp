#include<Windows.h>
#include"CView.h"

extern CView app; //외부에서 CView 클래스를 가져옴

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	int i = 0;
	while (CView::messageMap[i].iMsg != 0) {
		if (iMsg == CView::messageMap[i].iMsg) { 
			fpCViewGlobal = CView::messageMap[i].fp; //멤버함수의 포인터를 지정
			(app.*fpCViewGlobal)(wParam, lParam); //메시지에 맞는 멤버함수를 실행
			return 0L;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow); //창을 초기화
	app.Run(); //실행
	return app.ExitInstance(); //창을 닫음
}