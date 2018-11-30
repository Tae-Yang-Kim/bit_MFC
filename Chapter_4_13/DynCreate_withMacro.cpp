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
	return (*pfnCreateObject)();//�Լ������͸� �̿��Ͽ� ���������� �Լ��� ȣ��
}//CRuntimeClass::CreateObject--------------------

//{{class CObject--------
class CObject {
	//CObject�� ���� �����Լ��� �������� �����Ƿ�
	//�߻�Ŭ������ �ƴϴ�. �Ͻø� �����ڰ� protected�̹Ƿ� CObject ��ü�� �����Ҽ��¾���
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	//�Ļ� Ŭ�������� �ݵ�� ������ �ʿ䰡 �����Ƿ� ���� �����Լ��� �ƴϴ�
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