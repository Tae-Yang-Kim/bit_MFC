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
//RTTI 매크로를 선언
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
=======
};//struct CRunTimeClass

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)(); //함수포인터를 이용하여 간접적으로 함수를 호출한다.
}//CRuntimeClass::CreateObject()
//}}struct CRuntimeClass---------------------------------------------

//{{class CObject
class CObject {
	//CObject는 순수 가상 함수를 포함하지 않으므로
	//추상 클래스가 아니다. 하지만 생성자가 protected로 설정되었으므로,
	//CObject 객체를 생성할 수 없다.
public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	//파생 클래스에서 반드시 구현할 필요가 없으므로 순수 가상함수가 아니다.
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
		//struct RuntimeClass의 CreateObject()가 호출되지만
		//IMPLEMENT_DYNCREATE 매크로에 의해 CAlpha의 &OnCreate()가
		//대입되어 있으므로, 결국은 CAlpha의 OnCreate()가 호출되어
		//동적으로 객체를 생성하게 된다.
		//문제를 푸는 열쇠는 바로 '함수 포인터'다.
	printf("CAlpha class = %s\n",
		pObj1->GetRuntimeClass()->m_lpszClassName);

	//Create CBeta
	CRuntimeClass* pRTBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTBeta->CreateObject();
	printf("CBeta class=%s\n",
		pObj2->GetRuntimeClass()->m_lpszClassName);
	//일관된 방법으로 클래스를 만들고 해제하는것에 주목하여라

	delete pObj1;
	delete pObj2;

	return 0;
}//main
>>>>>>> b9436fd608cc93c7a7d2d62588a54e269a567bdf
