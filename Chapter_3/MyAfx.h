#pragma once

#define MYAFX_H
#include<Windows.h>
#define THIS_FILE __FILE__
//DEBUG����϶� �����Ҽ��ִ� ASSERT���� ����
#if defined(_DEBUG)
#define ASSERT(f)\
{\
if(!(f))\
{\
char buffer[80];\
sprintf(buffer, "%s(%d)\n", THIS_FILE, __LINE__); \
MessageBox(NULL, buffer, "ASSERT", MB_OK);\
}\
}
#else
#define ASSERT(f)
#endif//defined(_DEBUF) 