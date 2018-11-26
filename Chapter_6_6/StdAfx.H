#include <windows.h>

#ifndef _stdafx_
#define _stdafx_

//메시지 핸들러를 멤버 함수 포인터 테이블을통해 static으로 선언하며
//메시지 핸들러의 앞과 뒤를 define하여 설정
#define DECLARE_MESSAGE_MAP()           static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name)   MessageMap class_name::messageMap[]={
#define END_MESSAGE_MAP()               {0,NULL}};

//미리 윈도우 프록시저를 선언
//Forward declaration------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam);

#endif _stdafx_