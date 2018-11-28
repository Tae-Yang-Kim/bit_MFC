#include "CPaintDC.h"
CPaintDC::CPaintDC(CView* p) {
	ps = { NULL,NULL };
	pView = p;
	hdc = BeginPaint(pView->hwnd, &ps);
	::GetClientRect(pView->hwnd, &rect);
}
CPaintDC::~CPaintDC() {
	EndPaint(pView->hwnd, &ps);
}
BOOL CPaintDC::Drawtext(const char* text, int pos) {
	return DrawText(hdc, text, -1, &rect, pos);
}
void CPaintDC::GetClientRect() {
	::GetClientRect(pView->hwnd, &rect);
}