<<<<<<< HEAD
//RTTI (run time type information) example
=======
>>>>>>> b9436fd608cc93c7a7d2d62588a54e269a567bdf
#include<stdio.h>
#include<iostream>
using namespace std;

<<<<<<< HEAD
//{{RTTI macros----------------
=======
//RTTI ��ũ�θ� ����
//{{RTTI macros-----------------------------------------------------
>>>>>>> b9436fd608cc93c7a7d2d62588a54e269a567bdf
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name)		static\
		CRuntimeClass class##class_name;
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
<<<<<<< HEAD
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
=======
					class_name::class##class_name={\
						(#class_name),\
						sizeof(class_name),\
					class_name::CreateObject };
#define DECLARE_DYNCREATE(class_name) static CObject* CreateObject();
#define IMPLEMENT_DYNCREATE(class_name) CObject*\
					class_name::CreateObject(){\
				return new class_name;}
//}}RTTI macros------------------------------------------------------

class CObject; //forward declaration of CObject

//{{struct CRuntimeClass---------------------------------------------
>>>>>>> b9436fd608cc93c7a7d2d62588a54e269a567bdf
struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject* (*pfnCreateObject)();

	CObject* CreateObject();
<<<<<<< HEAD
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
=======
};//struct CRunTimeClass

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)(); //�Լ������͸� �̿��Ͽ� ���������� �Լ��� ȣ���Ѵ�.
}//CRuntimeClass::CreateObject()
//}}struct CRuntimeClass---------------------------------------------

//{{class CObject
class CObject {
	//CObject�� ���� ���� �Լ��� �������� �����Ƿ�
	//�߻� Ŭ������ �ƴϴ�. ������ �����ڰ� protected�� �����Ǿ����Ƿ�,
	//CObject ��ü�� ������ �� ����.
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	//�Ļ� Ŭ�������� �ݵ�� ������ �ʿ䰡 �����Ƿ� ���� �����Լ��� �ƴϴ�.
	DECLARE_DYNAMIC(CObject)
	//static CRuntimeClass class CObject;
>>>>>>> b9436fd608cc93c7a7d2d62588a54e269a567bdf
	virtual ~CObject() {}
protected:
	CObject() { printf("CObject constructor\n"); }
};//class CObject

CRuntimeClass CObject::classCObject = {
<<<<<<< HEAD
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
=======
	"CObject", sizeof(CObject),NULL
};
//}}class CObject----------------------------------------------------

//{{class CAlpha-----------------------------------------------------
class CAlpha : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCAlpha;
	}
	DECLARE_DYNAMIC(CAlpha)
	//static CRuntimeClass classCAlpha;
	DECLARE_DYNCREATE(CAlpha)
	//static CObject* CreateObject();

protected:
	CAlpha() { printf("CAlpha constructor\n"); }
};//class CAlpha

IMPLEMENT_DYNAMIC(CAlpha)
//CRuntimeClass CAlpha::classCAlpha={
//	"CAlpha", sizeof(CAlpha), CAlpha::CreateObject
//};

IMPLEMENT_DYNCREATE(CAlpha)
//CObject* CAlpha::CreateObject(){
//	return new CAlpha;
//}
//}}class CAlpha------------------------------------------------------

class CBeta :public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClss() const {
		return &classCBeta;
	}
	DECLARE_DYNAMIC(CBeta)
	//static CRuntime Class classCBeta;
	DECLARE_DYNCREATE(CBeta)
	//static CObject* CreateObject();
protected:
	CBeta() { printf("CBeta constructor\n"); }
};//class CBeta

IMPLEMENT_DYNAMIC(CBeta)
	//CRuntimeClass CBeta::classCBeta ={
	//	"CBeta", sizeof(CBeta), CBeta::CreateObject
	//};
IMPLEMENT_DYNCREATE(CBeta)
	//CObject* CBeta::CreateObject() {
	//	return new CBeta;
	//}
//}}class CBeta--------------------------------------

int main() {
	//Create CAlpha
	CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject* pObj1;
	pObj1 = pRTCAlpha->CreateObject();
		//struct RuntimeClass�� CreateObject()�� ȣ�������
		//IMPLEMENT_DYNCREATE ��ũ�ο� ���� CAlpha�� &OnCreate()��
		//���ԵǾ� �����Ƿ�, �ᱹ�� CAlpha�� OnCreate()�� ȣ��Ǿ�
		//�������� ��ü�� �����ϰ� �ȴ�.
		//������ Ǫ�� ����� �ٷ� '�Լ� ������'��.
	printf("CAlpha class = %s\n",
		pObj1->GetRuntimeClass()->m_lpszClassName);

	//Create CBeta
	CRuntimeClass* pRTBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTBeta->CreateObject();
	printf("CBeta class=%s\n",
		pObj2->GetRuntimeClass()->m_lpszClassName);
	//�ϰ��� ������� Ŭ������ ����� �����ϴ°Ϳ� �ָ��Ͽ���

	delete pObj1;
	delete pObj2;

	return 0;
}//main
>>>>>>> b9436fd608cc93c7a7d2d62588a54e269a567bdf