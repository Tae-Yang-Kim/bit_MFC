//��ȯ������
#if 1
#include <stdio.h>
typedef unsigned int HANDLE;
class CHandle {
private:
	HANDLE m_handle;
	int m_data;
public:
	CHandle() {
		m_handle = 0;
		m_data = 1;
	}
	HANDLE GetHandle() const {
		printf("GetHandle()\n");
		return m_handle;
}
	int Getint() const {
		return m_data;
	}
	/*operator HANDLE() const {
	   printf("GetHandle()\n");
	   return m_handle;
	}*/
	void FromHandle(HANDLE handle) {
		m_handle = handle;
		//construct etc. emebers from handle
	}
	operator HANDLE()const {//handle type ������
		return m_handle;
	}
	operator int() const {//�Լ��� ȣ���� ��ü�� ��ȭ�� �� ���� ����
		return m_data;
	}
};
void Test(HANDLE handle) {
	printf("handle = %i \n", handle);
}
void test(int handle) {
	printf("handle = %i \n", handle);
}

void main() {
	CHandle handleObject;
	HANDLE handle;
	handle = 2;
	handleObject.FromHandle(handle);
	Test(handleObject.GetHandle());
	Test(handleObject);
	test(handleObject.Getint());


}
#endif

//��ū ���� ������
#if 0
#include<iostream>
#define stringit(x) #x
#define tokencat(x,y) x##y
using namespace std;
void main(void) {
	int i = 1, j = 2, ij = 3;

	cout << stringit(hello) << '\n';
	cout << tokencat(i, j) << '\n';
}
#endif

//switch�� ���� ����Լ� ����
#if 0
#include<stdio.h>
class CStateManager {
private:
	// 0 : idle state
	// 1 : attack state
	// 2 : game over state
	int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();

public:
	CStateManager();
	void SetState(int state);
	void DoIt();
};

void CStateManager::State_Idle() {
	printf("idle\n");
}
void CStateManager::State_Attack() {
	printf("attack\n");
}
void CStateManager::State_GameOver() {
	printf("game over\n");
}
CStateManager::CStateManager() {
	m_iState = 0;
}
void CStateManager::SetState(int state) {
	//m_iState = state;
	if (state < 0) {
		printf("�߸��� ��");
		return;
	}
	m_iState = state;
}

//switch���� ����� Do it()����Լ�

//void CStateManager::DoIt() {
//	switch (m_iState) {
//	case 0:
//		State_Idle();
//		break;
//	case 1:
//		State_Attack();
//		break;
//	case 2:
//		State_GameOver();
//		break;
//	}
//}

//�Լ������͹迭�� ����� Do it()��� �Լ�
void CStateManager::DoIt() {
	//*fp[3] = void CStateManager::State_GameOver()
	//void *fp[3] = CStateManager::State_GameOver()
	//void  CStateManager::*fp[3]() = State_GameOver
	//void  (CStateManager::*fp)[3]() = &CStateManager::State_GameOver
	void(CStateManager::*fp[3])() = {
		&CStateManager::State_Idle,
		&CStateManager::State_Attack,
		&CStateManager::State_GameOver,
	};
	(this->*fp[m_iState])();
}
void main() {
	void (CStateManager::*fp)(int);
	fp = &CStateManager::SetState;

	CStateManager sman;
	(sman.*fp)(1);
	sman.DoIt();
}
#endif

//static
#if 0
#include<stdio.h>
class CStateManager {
private:
	// 0 : idle state
	// 1 : attack state
	// 2 : game over state
	static int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();

public:
	CStateManager();
	static void SetState(int state);
	void DoIt();
};

void CStateManager::State_Idle() {
	printf("idle\n");
}
void CStateManager::State_Attack() {
	printf("attack\n");
}
void CStateManager::State_GameOver() {
	printf("game over\n");
}
CStateManager::CStateManager() {
	m_iState = 0;
}
void CStateManager::SetState(int state) {
	//m_iState = state;
	if (state < 0) {
		printf("�߸��� ��");
		return;
	}
	m_iState = state;
}

void CStateManager::DoIt() {
	switch (m_iState) {
	case 0:
		State_Idle();
		break;
	case 1:
		State_Attack();
		break;
	case 2:
		State_GameOver();
		break;
	}
}

void main() {
	//void CStateManager::SetState(int state)
	//void(int state) = CStateManager::SetState
	//void  (*fp) (int state) = CStateManager::SetState
	//void  (CStateManager::*fp) (int state) = CStateManager::SetState
	//void  (CStateManager::*fp) (int) = CStateManager::SetState

	/*void (CStateManager::*fp)(int);
	fp = CStateManager::SetState;*/

	void(*fp)(int) = CStateManager::SetState;

	CStateManager sman;
	fp(1);
	sman.DoIt();

	sman.SetState(1);
}
#endif


//�Լ�������
#if 0
#include<stdio.h>
int Sum(int a, int b) {
	return a + b;
}

int main() {
	//fp = int Sum(inta, int b)
	//int fp(int a, int b) = Sum
	//int (*fp)(int a, int b) = Sum
	//int (*fp)(int, int) = Sum
	int(*fp)(int, int) = Sum;
	int i;
	fp = Sum;
	i = fp(2, 3);
	printf("%d\n", i);
}
#endif

//â���� bit flag�� Ȱ��
#if 0
#include<Windows.h>
int main() {
	MessageBox(NULL, "Hello", "hello world", MB_OKCANCEL | MB_ICONASTERISK);
}
#endif

//bit flag
#if 0
#include <stdio.h>

#define MB_OK 0x00000000L
#define MB_OKCANCEL 0x00000001L
#define MB_ABORTRETRYIGNORE 0x00000002L
#define MB_YESNOCANCEL 0x00000003L
#define MB_YESNO 0x00000004L
#define MB_RETRYCANCEL 0x00000005L

#define MB_ICONHAND 0x00000010L
#define MB_ICONQUESTION 0x00000020L
#define MB_ICONEXCLAMATION 0x00000030L
#define MB_ICONASTERISK 0x00000040L

void MessageBox(const char* pszMessage, unsigned int flag) {
	int iButton = flag & 0x000f;
	int iIcon = (flag & 0x00f0) >> 4;
	const char * pszButtons[] = { "OK", "OKCANCEL",
							"ABORTRETRYIGNORE", "YESNOCANCEL",
							"YESNO", "RETRYCANCEL" };
	const char * pszIcons[] = { "", "HAND", "QUESTION",
							"EXCLAMATION", "ASTERISK" };

	printf("msg = %s\n"
		"button = %s\n"
		"icon = %s\n",
		pszMessage, pszButtons[iButton], pszIcons[iIcon]);
}

void main() {
	MessageBox("hello", MB_OK | MB_ICONQUESTION);
}
#endif