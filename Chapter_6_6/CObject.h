#include <windows.h>
//���� ū Ŭ���� ������ ����� �ɰ�

#ifndef _CObject_
#define _CObject_

class CObject {
protected:
    static char szAppName[]; //���ø����̼� �̸�
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;

public:
	//����Լ� �����͸� ����ϱ� ������ virtual�� �Ƚᵵ ��
    void InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
                      int iCmdShow); //�ʱ�ȭ
    void Run(); //����
    WPARAM ExitInstance(); //����
};//class CObject

#endif