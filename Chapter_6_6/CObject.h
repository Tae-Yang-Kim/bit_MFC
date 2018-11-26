#include <windows.h>
//가장 큰 클래스 모든것의 상속이 될것

#ifndef _CObject_
#define _CObject_

class CObject {
protected:
    static char szAppName[]; //애플리케이션 이름
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;

public:
	//멤버함수 포인터를 사용하기 때문에 virtual을 안써도 됨
    void InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
                      int iCmdShow); //초기화
    void Run(); //실행
    WPARAM ExitInstance(); //종료
};//class CObject

#endif