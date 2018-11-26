#include<Windows.h>
#include"CView.h"

extern CView app; //�ܺο��� CView Ŭ������ ������

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	int i = 0;
	while (CView::messageMap[i].iMsg != 0) {
		if (iMsg == CView::messageMap[i].iMsg) { 
			fpCViewGlobal = CView::messageMap[i].fp; //����Լ��� �����͸� ����
			(app.*fpCViewGlobal)(wParam, lParam); //�޽����� �´� ����Լ��� ����
			return 0L;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow); //â�� �ʱ�ȭ
	app.Run(); //����
	return app.ExitInstance(); //â�� ����
}