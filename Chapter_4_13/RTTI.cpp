#include <stdio.h>

/*
void func(int *pi)
{
	 // pi가 누구를 가리키는가?
}

int i,j;
unsigned k;
func(&i);
func(&j);
func((int *)&k);
*/

class Parent
{
public:
	virtual void PrintMe() { printf("I am Parent\n"); }
};



class Child : public Parent
{
private:

	int num;


public:

	Child(int anum = 1234) : num(anum) { }
	virtual void PrintMe() { printf("I am Child\n"); }
	void PrintNum() { printf("Hello Child=%d\n", num); }
};



void func(Parent *p){
	p->PrintMe();
	((Child *)p)->PrintNum();
}



void main(){

	Parent p;
	Child c(5);

	func(&c);
	func(&p);

}