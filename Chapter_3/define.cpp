//��ũ�� �Լ� �̹��� ������
#if 1
#include<stdio.h>
#include "macro.h"
#include "b.cpp"
//#include "b.cpp"

extern int f(int i);

void main() {
	int i;
	i = f(2);
	PRINT(i);
}

#endif

//��ũ�� �Լ��� ������
#if 0 
#include<stdio.h>
#define MUL_DEFINED
#define MUL(a,b) a*b

void main() {
	printf("%d\n", MUL(2 + 3, 4));
}
#endif
//��ũ�� �Լ��� ����
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