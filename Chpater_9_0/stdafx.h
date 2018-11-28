#pragma once
#include <Windows.h>
#define DECLARE_MESSAGE_MAP()  static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(classname) MessageMap classname::messageMap[] = {//setting other space
#define END_MESSAGE_MAP()	{NULL, NULL} };//Sentinel 
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
