#pragma once
#include "CView.h"

class CPaintDC {
private:
	CView* pView;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
public:
	CPaintDC(CView* pView);
	virtual ~CPaintDC();
	BOOL Drawtext(const char* text, int pos);
	void GetClientRect();
};