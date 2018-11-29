#include<iostream>
using namespace std;

#define DECLARE_CLASSNAME(s) static char lpszClassName[]
#define IMPLEMENT_CLASSNAME(s) char s##::lpszClassName[]=(#s)

class CObject {
public:
	virtual char* GetClassName() const {
		return NULL;
	}
};

class CMyClass : public CObject {
public:
	//static char lpszClassName[];
	DECLARE_CLASSNAME(CMyClass);
	virtual char* GetClassName() const {
		return lpszClassName;
	}

};

IMPLEMENT_CLASSNAME(CMyClass);

int main() {
	CObject *p;

	p = new CMyClass;
	cout << p->GetClassName() << endl;
	delete p;

	return 0;
}