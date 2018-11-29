//RTTI(Run-time type information)�� �� ����ϴ°��ΰ�?
//����ð��� ��ü�� Ÿ�� ������ ��� C++�� ������ ���

//����ڰ� Ŭ������ �̸��� �Է��ϸ�. Ŭ������ ����� ���� ������ִ� �ڵ� �ڵ������⸦ ����ٰ� ����
//������ MyClass�� �Է��Ͽ� MyClass�� �ҽ� ����� �����Ѵٰ� �����Ѵٸ�
//1. ���� �ÿ� "�˷����� ����" Ŭ������ �̸��� ũ�⸦ ������
//2. ���� �ÿ� "�˷����� ����" Ŭ������ �������� ������ �� �־�� �Ѵ�.

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
	static char lpszClassName[]; //Ŭ���� �̸��� �޸𸮿� �ѹ��� �Ҵ��ϸ� �ȴ�.
	virtual char* GetClassName() const {//baseŬ������ CObject�� GetClassName�� �������̵�
		return lpszClassName; //���� ��� ������ �����Ѵ�.
	}
};

char CMyClass::lpszClassName[] = "CMyClass";

void main() {
	CObject *p;

	p = new CMyClass; //subtype principle�� ���� ���� Ŭ������ ����Ű�� ���� ���� Ŭ������ �����͸�
	//���� Ŭ������ �����͸� ����ϴ� ���� �����ϴ�.
	cout << p->GetClassName() << endl;
	//�������� ������� ��ü�� �̸��� ���� �� �ִ�.
	delete p;
}//main