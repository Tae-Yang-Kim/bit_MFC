#pragma once
#include "stdafx.h"
#include "CObject.h"

class CView;

typedef LRESULT(CView::*CViewFunPointer)(WPARAM, LPARAM);

typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;
#define NUM 1000
#define TWOPI (2*3.141592)
class CView :public CObject {
public:
	CObject::hwnd;
public:
	PAINTSTRUCT ps;
	POINT pt[NUM];
	HDC hdc;
	int cyClient;
	int cxClient;
	DECLARE_MESSAGE_MAP()
	LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
	LRESULT OnDraw(WPARAM wParam, LPARAM lParam);
	LRESULT OnDestroy(WPARAM wParam, LPARAM lParam);

	LRESULT OnSize(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnCommand(WPARAM wParam, LPARAM lParam);
};
