#pragma once
#include "stdafx.h"
#include "CObject.h"

class CWnd : public CObject{
public:
	DECLARE_DYNCREATE(CWnd)

	HWND m_hwnd;

public:
	HWND GetSafeHwnd();
	BOOL ShowWindow(int nCmdShow);
	BOOL UpdateWindow();

	virtual void PreCreateWindow(CREATESTRUCT& cs);
};