/*MFC의 초기 설계자들은 MFC를 설계하면서 클래스의 동적 생성과 실행 시 타입에 관한 정보가 필요한것을 알았다
왜냐하면 부모클래스의 포인터값을 통해 자식클래스에 접근하는 경우가 많은데 이때 타입에 관한 정보가 필요하기때문에 RTTI가 필요하다
MFC와 RTTI는 몇 개의 매크로와 클래스가 지켜여야 할 규칙을 명시하며 이러한 조건을 만족하도록 클래스를 설계하면 실행시간에
클래스에 관한 정보와 실행시간에 이름이 알려지는 클래스의 동적 생성이 가능하다.
-> 이것을 핵심으로 이루어져 있는것이 CRuntimeClass이다.*/

/*
struct CRuntimeClass{
	char		m_lpszClassName[21]; //클래스의 이름을 의미하는 문자열
	int			m_nObjectSize; //객체의 크기
	CObject*(*pfnCreateObject)();//함수 포인터 -> CObject는 모든 클래스의 부모 //클래스마다 존재해야하는 자기자신을 생성하는 함수의 시작주소
	CObject* CreateObject(); //멤버함수, 세번째 멤버에 설정된 함수포인터를 이용하여 함수를 호출
}//struct CRunTimeClass

CObject* CRuntimeClass::CreateObject(){
	return (*pfnCreateObject)();//함수포인터를 이용하여 간접적으로 함수 호출
}//CRuntimeClass::CreateObject()
*/

/*
1. 클래스는 반드시 CRuntimeClass 타입의 static 멤버를 가져야한다.
2. 1. 에 선언된 static 멤버를 초기화하는 루틴을 구현 파일에 가져야 한다.
3. 클래스는 반드시 CObject*를 리턴하는 static CreateObject() 함수를 선언해야 한다.
4. 3. 에 선언된 static 멤버 함수의 몸체를 구현 파일에 가져야 한다.+
*/

/*
1.  CRuntimeClass는 객체를 생성하기 전, 클래스 레벨에서 접근해야 한다. 그래서 static으로 선언되어야 한다.

2.  초기화 루틴은 클래스 이름, 클래스 크기를 설정하고, CRuntimeClass::pfnCreateObject를 클래스의 정적 멤버 함수 CreateObject로 초기화한다.

3.  CreateObject()의 프로토타입은 반드시 static CObject* CreateObject();이다. 클래스 레벨에서 접근해야 하므로, 반드시 static이어야 한다.

4.  CreateObject()는 자기 자신을 동적으로 생성하고, 생성된 객체의 시작 주소를 리턴한다. CreateObject()의 리턴 값을 받는 코드는 서브타입의
	(subtype principle)를 위반하지 않기 위해 반드시 CObject* 하위 타입이어야 한다. 이것을 동적 생성을 지원하는 클래스가 반드시 CObject를 상속
	받아야하는 이유 이다.
*/

/*
1. DECLARE_DYNAMIC(class_name)
2. IMPLEMENT_DYNAMIC(class_name)
3. DECLARE_DYNCREATE() [1, 3]
4. IMPLEMENT_DYNCREATE() [2, 4]
*/

/*
//CRuntime의 스태틱 멤버를 얻어내기 위해 사용한다
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

//클래스에 CRuntimeClass 타입의 스태틱 멤버를 선언하기 위해 사용
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass\
	class##class_name;

//정적으로 선언된 CRuntimeClass타입의 멤버를 초기화하기 위해 사용
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
	class_name::class##class_name = {\
		(#class_name), \
		sizeof(class_name), \
		class_name::CreateObject }; 

#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* CreateObject();

#define IMPLEMENT_DYNCREATE(class_name) \
	IMPLEMENT_DYNAMIC(class_name) \
	CObject* class_name::CreateObject() {return new class_name;}
*/