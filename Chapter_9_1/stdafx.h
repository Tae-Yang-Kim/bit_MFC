#pragma once
#include <Windows.h>
#define DECLARE_MESSAGE_MAP()  static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(classname) MessageMap classname::messageMap[] = {//setting other space
#define END_MESSAGE_MAP()	{NULL, NULL} };//Sentinel 

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

#define DECLARE_DYNAMIC(class_name) static CRuntimeClass\
	class##class_name;

#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
	class_name::class##class_name={\
		(#class_name),\
		sizeof(class_name),\
		class_name::CreateObject };

#define DECLARE_DYNCREATE(class_name)\
	DECLARE_DYNAMIC(class_name)\
	static CObject* CreateObject();

#define IMPLEMENT_DYNCREATE(class_name)\
	IMPLEMENT_DYNAMIC(class_name)\
	CObject *class_name::CreateObject(){return new class_name;}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject;

struct CRuntimeClass {
	char		m_lpszClassName[21];
	int			m_nObjectSize;
	CObject* (*pfnCreateObject)();

	CObject* CreateObject();
};

class CView;
typedef void(CView::*CViewFunPointer)();
typedef struct tagMessageMap {
	UINT	iMsg;
	CViewFunPointer fp;
}MessageMap;
