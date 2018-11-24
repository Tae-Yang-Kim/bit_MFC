#if 1
#include<stdio.h>
#include<string.h>
#include<conio.h>
#pragma warning (disable:4996)

class Cstr {
	char *str;
public:
	Cstr(const char *s = " ") {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		printf("constructor\n");
	}
	~Cstr() {
		delete[]str;
		printf("destructor\n");
	}
	void Print() {
		printf("%s\n", str);
	}
};//class CStr

void f(Cstr s) {
	s.Print();
}

void main() {
	Cstr s("Hello");
	f(s);
}
#endif