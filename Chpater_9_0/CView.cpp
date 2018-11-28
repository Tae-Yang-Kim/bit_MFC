#include "resource.h"
#include <math.h>
#include "DC.h"
#include "CPaintDC.h"
CView app;

BEGIN_MESSAGE_MAP(CView)
{WM_CREATE, &CView::OnCreate},
{WM_PAINT, &CView::OnDraw },
{WM_DESTROY, &CView::OnDestroy},
{WM_SIZE, &CView::OnSize },
{WM_LBUTTONDOWN, &CView::OnLButtonDown},
{WM_COMMAND, &CView::OnCommand},
END_MESSAGE_MAP()

LRESULT CView::OnCreate(WPARAM wParam, LPARAM lParam) { 
	hIcon = ::LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	cxIcon = ::GetSystemMetrics(SM_CXICON);
	cyIcon = ::GetSystemMetrics(SM_CXICON);

	return 0L; }
LRESULT CView::OnDraw(WPARAM wParam, LPARAM lParam) {
	//HDC hdc; PAINTSTRUCT ps; RECT rect; hdc = BeginPaint(hwnd, &ps);
	CPaintDC pdc(this);
	//DrawText(hdc, "Hellow Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	//EndPaint(hwnd, &ps);
	pdc.Drawtext("Hellow Windows", DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	return 0L;
}
LRESULT CView::OnDestroy(WPARAM wParam, LPARAM lParam) {
	PostQuitMessage(0);
	return 0L;
}
LRESULT CView::OnLButtonDown(WPARAM wParam, LPARAM lParam) {
	/*int i;
	hdc = GetDC(hwnd);
	MoveToEx(hdc, 0, cyClient / 2, NULL);
	LineTo(hdc, cxClient, cyClient / 2);
	for (i = 0; i < NUM; i++) {
		pt[i].x = i * cxClient / NUM;
		pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI*i / NUM)));
	}
	Polyline(hdc, pt, NUM);
	ReleaseDC(hwnd, hdc);*/
	int i = 0;
	CDC dc(this);
	dc.MoveToEx(0, cyClient / 2, NULL);
	dc.LineTo(cxClient, cyClient / 2);
	cxIcon = LOWORD(lParam);
	cyIcon = HIWORD(lParam);
	DrawIcon(dc.hdc, cxIcon, cyIcon, hIcon);
	return 0L;
}
LRESULT CView::OnSize(WPARAM wParam, LPARAM lParam) {
	cxClient = LOWORD(lParam);
	cyClient = HIWORD(lParam);
	return 0L;
}

LRESULT CView::OnCommand(WPARAM wParam, LPARAM lParam) {
	HMENU hMenu;

	hMenu = GetMenu(hwnd);
	switch (LOWORD(wParam)) {
	case ID_AAA:
		SendMessage(hwnd, WM_CLOSE, 0, 0L);
		break;
	case ID_BBB:
		SendMessage(hwnd, WM_LBUTTONDOWN, 0, 0L);
		break;
	}
	return 0;
}