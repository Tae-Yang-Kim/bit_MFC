#include"stdafx.h"
#include"CView.h"
#include<math.h>

CView app;

BEGIN_MESSAGE_MAP(CView)
{WM_CREATE, &CView::OnCreate},
{WM_PAINT,  &CView::OnDraw},
{WM_DESTROY, &CView::OnDestory},
{WM_SIZE, &CView::OnSize},
{WM_LBUTTONDOWN, &CView::OnLButtonDown},
END_MESSAGE_MAP()

LRESULT CView::OnCreate(WPARAM wParam, LPARAM lParam) {
	return 0L;
}

LRESULT CView::OnDraw(WPARAM wParam, LPARAM lParam) {
	HDC				hdc;
	PAINTSTRUCT	ps;
	RECT			rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "hello, windows", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT CView::OnDestory(WPARAM wParam, LPARAM lParam) {
	PostQuitMessage(0);
	return 0L;
}

LRESULT CView::OnLButtonDown(WPARAM wParam, LPARAM lParam) {
	int i;
	hdc = GetDC(hwnd);

	MoveToEx(hdc, 0, cyClient / 2, NULL);
	LineTo(hdc, cxClient, cyClient / 2);

	for (i = 0; i < NUM; i++) {
		pt[i].x = i * cxClient / NUM;
		pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI * i / NUM)));
	}
	Polyline(hdc, pt, NUM);

	ReleaseDC(hwnd, hdc);	
	return 0L;
}

LRESULT CView::OnSize(WPARAM wParam, LPARAM lParam) {
	cxClient = LOWORD(lParam);
	cyClient = HIWORD(lParam);
	return 0L;
}