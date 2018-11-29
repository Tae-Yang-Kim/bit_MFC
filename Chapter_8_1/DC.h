#pragma once
#include "CView.h"

class CDC {
private:
	CView* pView;
	PAINTSTRUCT ps;
	HDC hdc;
public:
	CDC(CView* pVew);
	virtual ~CDC();
	BOOL MoveToEx(int, int, LPPOINT);
	BOOL LineTo(int, int);
	BOOL Polyline(CONST POINT*, int);
};