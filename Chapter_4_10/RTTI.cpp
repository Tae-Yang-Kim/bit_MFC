//RTTI(Run-time type information)란 왜 사용하는것인가?
//실행시간에 객체의 타입 정보를 얻는 C++의 진보된 방식

//사용자가 클래스의 이름을 입력하면. 클래스의 골격을 대충 만들어주는 코드 자동생성기를 만든다고 가정
//실행중 MyClass를 입력하여 MyClass의 소스 골격을 생성한다고 가정한다면
//1. 실행 시에 "알려지지 않은" 클래스의 이름과 크기를 얻어야함
//2. 실행 시에 "알려지지 않은" 클래스를 동적으로 생성할 수 있어야 한다.

//RTTI example
#include<iostream>
using namespace std;

class CObject {
public:
	virtual char* GetClassName() const {
		return NULL;
	}
};//class CObject

class CMyClass : public CObject {
public:
	static char lpszClassName[]; //클래스 이름은 메모리에 한번만 할당하면 된다.
	virtual char* GetClassName() const {//base클래스인 CObject의 GetClassName을 오버라이드
		return lpszClassName; //정적 멤버 변수를 리턴한다.
	}
};

char CMyClass::lpszClassName[] = "CMyClass";

void main() {
	CObject *p;

	p = new CMyClass; //subtype principle에 의해 하위 클래스를 가리키기 위해 상위 클래스의 포인터를
	//상위 클래스의 포인터를 사용하는 것이 가능하다.
	cout << p->GetClassName() << endl;
	//동적으로 만들어진 객체의 이름은 구할 수 있다.
	delete p;
}//main