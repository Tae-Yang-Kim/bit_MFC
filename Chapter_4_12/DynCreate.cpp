#include<stdio.h>
#include<iostream>
using namespace std;

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

class CObject;
struct CRuntimeClass {
	char m_lpszClassName[21];
	int m_nObjectSize;
	CObject* (*pfnCreateObject)();

	CObject* CreateObject();
};//struct CRunTimeClass

CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)();
}

class CObject {

public:
	virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
	static CRuntimeClass classCObject;
	virtual ~CObject() {}

protected:
	CObject() { printf("CObject constructor\n"); }
};

CRuntimeClass CObject::classCObject = {
	"CObject", sizeof(CObject),NULL
};

class CAlpha : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCAlpha;
	}
	static CRuntimeClass classCAlpha;
	static CObject* CreateObject();

protected:
	CAlpha() {
		printf("CAlpha constructor\n");
	}
};

CRuntimeClass CAlpha::classCAlpha = {
	"CAlpha", sizeof(CAlpha), CAlpha::CreateObject
};

CObject* CAlpha::CreateObject() {
	return new CAlpha;
}

class CBeta : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCBeta;
	}
	static CRuntimeClass classCBeta;
	static CObject* CreateObject();
protected:
	CBeta() {
		printf("CBeta constructor\n");
	}
};

CRuntimeClass CBeta::classCBeta = {
	"CBeta", sizeof(CBeta), CBeta::CreateObject
};

CObject* CBeta::CreateObject() {
	return new CBeta;
}

void main() {
	CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject* pObj1;

	pObj1 = pRTCAlpha->CreateObject();
	printf("CAlpha class = %s\n",
		pObj1->GetRuntimeClass()->m_lpszClassName);

	CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTCBeta->CreateObject();
	printf("CBeta class=%s\n",
		pObj2->GetRuntimeClass()->m_lpszClassName);

	delete pObj1;
	delete pObj2;
}
