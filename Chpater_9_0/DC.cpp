#include "DC.h"
#include "CView.h"

CDC::CDC(CView* p) {
	ps = { NULL,NULL };
	pView = p;
	hdc = GetDC(pView->hwnd);
	::GetClientRect(pView->hwnd, &rect);
}
CDC::~CDC() {
	ReleaseDC(pView->hwnd, hdc);
}
BOOL CDC::MoveToEx(int x, int y, LPPOINT lpPoint) {
	return ::MoveToEx(hdc, x, y, lpPoint);
}

BOOL CDC::LineTo(int x, int y) {
	return ::LineTo(hdc, x, y);
}

BOOL CDC::Polyline(CONST POINT* lppt, int cPoints) {
	return ::Polyline(hdc, lppt, cPoints);
}

