//RTTI (run time type information) example
#include<stdio.h>
#include<iostream>
using namespace std;

//{{RTTI macros----------------
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name)		static\
		CRuntimeClass class##class_name;
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
					class_name::class##class_name = {\
						(#class_name),\
						sizeof(class_name),\
					class_name::CreateObject};
#define DECLARE_DYNCREATE(class_name) static Object* CreateObject();
#define IMPLEMENT_DYNCREATE(class_name) CObject*\
					class_name::CreateObject() {\
					return new class_name; }
//}}RTTI macros-----------------------------

class CObject;//forward declaration of CObject

//{{struct CRuntimeClass---------------------------------
struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject* (*pfnCreateObject)();

	CObject* CreateObject();
};//struct CRunTImeClass

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)();//함수포인터를 이용하여 간접적으로 함수를 호출
}//CRuntimeClass::CreateObject--------------------

//{{class CObject--------
class CObject {
	//CObject는 순수 가상함수를 포함하지 않으므로
	//추상클래스가 아니다. 하시만 생성자가 protected이므로 CObject 객체를 생성할수는없다
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	//파생 클래스에서 반드시 구현할 필요가 없으므로 순수 가상함수가 아니다
	DECLARE_DYNAMIC(CObject);
	//static CRuntimeClass classCObject;
	virtual ~CObject() {}
protected:
	CObject() { printf("CObject constructor\n"); }
};//class CObject

CRuntimeClass CObject::classCObject = {
	"CObject",sizeof(CObject),NULL
};

//}}class CObject--------------------------------

//{{class CAlpha-----------
class CAlpha : public CObject {
public:
	/*virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCAlpha;
	}
	DECLARE*/
};