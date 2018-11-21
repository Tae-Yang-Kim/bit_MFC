
//TODO
#if 0
#include<stdio.h>

#define LINE1(x) #x
#define LINE(x) LINE1 (x)
#define TODO(msg) message(__FILE__"(" LINE(__LINE__) "): [TODO] " msg)

void main() {
#pragma TODO("implement main()\n")
	printf("hello\n");
	printf("world\n");
	printf("world""hi");
}
#endif

//#pragma message
#if 0
#include<stdio.h>

int main() {
	printf("hello\n");
#pragma message("between hello and world\n");
	printf("world\n");

	k = 10;
#pragma message("test");
	return 0;
}

#endif

//#if endif 예외처리
#if 0
#include<stdio.h>

/*
TYPE 0 : WIN
	 1 : LINUX
*/

#define TYPE 0
void main() {
	int i = 2, j = 3;
#if(TYPE!=0)
//#error You must define TYPE to 0
#error Hello
#endif
	printf("%d, %d\n", i, j);
}
#endif

//line번호 지정
#if 0
#include<stdio.h>
void main() {
#line 1 "main.cpp"
	int i = 2, j = 3, k = 4;

	printf("%d, %d, %d\n", i, j, k);
	printf("%s, %d\n", __FILE__, __LINE__);
	printf("%d\n", __LINE__);
#line 3897
	printf("%s, %d\n", __FILE__, __LINE__);
}
#endif
//__LINE__ __FILE__
#if 0
#include<stdio.h>

void main() {
	int i = 2, j = 3, k = 4;

	printf("%d, %d, %d\n", i, j, k);
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);
}
#endif

//#ifdef #endif 사용법
#if 0
#include<stdio.h>
#define DEBUG

#ifdef DEBUG
//#undef DEBUG
void f(int i) {
	printf("%d\n", i);
}
#endif

void main() {
	int i = 2, j = 3, k = 4;
	k = i * j * k;
#ifdef DEBUG
	f(k);
#endif
	printf("%d, %d, %d\n", i, j, k);
}

#endif

//매크로 함수 미묘한 문제점
#if 0
#include<stdio.h>
#include "macro.h"
#include "b.cpp"
//#include "b.cpp"

extern int f(int i);

void main() {
	int i;
	i = f(2);
	while (1) {
		PRINT(i);
	}
}

#endif

//매크로 함수의 문제점
#if 0 
#include<stdio.h>
#define MUL_DEFINED
#define MUL(a,b) a*b

void main() {
	printf("%d\n", MUL(2 + 3, 4));
}
#endif
//매크로 함수의 사용법
#if 0
#include<stdio.h>

#define PI 3.141592
#define A B, C
#define begin {
#define end }
#define procedure void

int B = 1, C = 2;

procedure PrintPI()
begin
	printf("%f\n", PI); 
end

void main()
begin
	PrintPI();
	printf("%d, %d\n", A);
end

#endif