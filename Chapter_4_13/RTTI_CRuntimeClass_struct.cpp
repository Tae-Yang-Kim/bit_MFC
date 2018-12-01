/*MFC�� �ʱ� �����ڵ��� MFC�� �����ϸ鼭 Ŭ������ ���� ������ ���� �� Ÿ�Կ� ���� ������ �ʿ��Ѱ��� �˾Ҵ�
�ֳ��ϸ� �θ�Ŭ������ �����Ͱ��� ���� �ڽ�Ŭ������ �����ϴ� ��찡 ������ �̶� Ÿ�Կ� ���� ������ �ʿ��ϱ⶧���� RTTI�� �ʿ��ϴ�
MFC�� RTTI�� �� ���� ��ũ�ο� Ŭ������ ���ѿ��� �� ��Ģ�� ����ϸ� �̷��� ������ �����ϵ��� Ŭ������ �����ϸ� ����ð���
Ŭ������ ���� ������ ����ð��� �̸��� �˷����� Ŭ������ ���� ������ �����ϴ�.
-> �̰��� �ٽ����� �̷���� �ִ°��� CRuntimeClass�̴�.*/

/*
struct CRuntimeClass{
	char		m_lpszClassName[21]; //Ŭ������ �̸��� �ǹ��ϴ� ���ڿ�
	int			m_nObjectSize; //��ü�� ũ��
	CObject*(*pfnCreateObject)();//�Լ� ������ -> CObject�� ��� Ŭ������ �θ� //Ŭ�������� �����ؾ��ϴ� �ڱ��ڽ��� �����ϴ� �Լ��� �����ּ�
	CObject* CreateObject(); //����Լ�, ����° ����� ������ �Լ������͸� �̿��Ͽ� �Լ��� ȣ��
}//struct CRunTimeClass

CObject* CRuntimeClass::CreateObject(){
	return (*pfnCreateObject)();//�Լ������͸� �̿��Ͽ� ���������� �Լ� ȣ��
}//CRuntimeClass::CreateObject()
*/

/*
1. Ŭ������ �ݵ�� CRuntimeClass Ÿ���� static ����� �������Ѵ�.
2. 1. �� ����� static ����� �ʱ�ȭ�ϴ� ��ƾ�� ���� ���Ͽ� ������ �Ѵ�.
3. Ŭ������ �ݵ�� CObject*�� �����ϴ� static CreateObject() �Լ��� �����ؾ� �Ѵ�.
4. 3. �� ����� static ��� �Լ��� ��ü�� ���� ���Ͽ� ������ �Ѵ�.+
*/

/*
1.  CRuntimeClass�� ��ü�� �����ϱ� ��, Ŭ���� �������� �����ؾ� �Ѵ�. �׷��� static���� ����Ǿ�� �Ѵ�.

2.  �ʱ�ȭ ��ƾ�� Ŭ���� �̸�, Ŭ���� ũ�⸦ �����ϰ�, CRuntimeClass::pfnCreateObject�� Ŭ������ ���� ��� �Լ� CreateObject�� �ʱ�ȭ�Ѵ�.

3.  CreateObject()�� ������Ÿ���� �ݵ�� static CObject* CreateObject();�̴�. Ŭ���� �������� �����ؾ� �ϹǷ�, �ݵ�� static�̾�� �Ѵ�.

4.  CreateObject()�� �ڱ� �ڽ��� �������� �����ϰ�, ������ ��ü�� ���� �ּҸ� �����Ѵ�. CreateObject()�� ���� ���� �޴� �ڵ�� ����Ÿ����
	(subtype principle)�� �������� �ʱ� ���� �ݵ�� CObject* ���� Ÿ���̾�� �Ѵ�. �̰��� ���� ������ �����ϴ� Ŭ������ �ݵ�� CObject�� ���
	�޾ƾ��ϴ� ���� �̴�.
*/

/*
1. DECLARE_DYNAMIC(class_name)
2. IMPLEMENT_DYNAMIC(class_name)
3. DECLARE_DYNCREATE() [1, 3]
4. IMPLEMENT_DYNCREATE() [2, 4]
*/

/*
//CRuntime�� ����ƽ ����� ���� ���� ����Ѵ�
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

//Ŭ������ CRuntimeClass Ÿ���� ����ƽ ����� �����ϱ� ���� ���
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass\
	class##class_name;

//�������� ����� CRuntimeClassŸ���� ����� �ʱ�ȭ�ϱ� ���� ���
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