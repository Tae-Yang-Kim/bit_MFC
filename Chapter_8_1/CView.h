#pragma once

#include"stdafx.h"
#include"CObject.h"

class CView;

typedef LRESULT(CView::*CVIewFunPointer)(WPARAM, LPARAM);

typedef struct tagMessageMap {
	UINT iMsg;
	CVIewFunPointer fp;
}MessageMap;

static CVIewFunPointer fpCViewGlobal;

#define NUM 1000
#define TWOPI (2*3.14159)

class CView : public CObject {
public:
	CObject::hwnd;
public:
	PAINTSTRUCT ps;
	POINT pt[NUM];
	HDC hdc;
	int cyClient;
	int cxClient;

	LRESULT OnCreate(WPARAM, LPARAM);
	LRESULT OnDraw(WPARAM, LPARAM);
	LRESULT OnDestory(WPARAM, LPARAM);
	LRESULT OnSize(WPARAM, LPARAM);
	LRESULT OnLButtonDown(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()
};