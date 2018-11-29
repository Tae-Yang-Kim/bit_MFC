#pragma once
#include "CView.h"
class CDC {
private:
	CView* pView;
	PAINTSTRUCT ps;

	RECT rect;
public:
	HDC hdc;
	CDC(CView* pView);
	virtual ~CDC();
	BOOL MoveToEx(int, int, LPPOINT);
	BOOL LineTo(int, int);
	BOOL Polyline(CONST POINT* lppt, int cPoints);
};
