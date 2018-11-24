#include<stdio.h>
#include<assert.h>
#include"vector"

#define AfxGetApp() KSingleton<CWinApp>::GetSingleton()

template<typename T>
class KSingleton {
private:
	static T* ms_pSingleton;

public:
	KSingleton() {
		printf("KSingleton()\n");
		//assert�Լ��� Ư���ѿ����� �վ�� �Լ��̰�
		//��ü�� ��������� �����ڰ� ȣ��Ǵµ� �̶� static���� ����� �� ��ü��
		//�ٽ� �������� �ʵ��� �س�����
		assert(NULL == KSingleton<T>::ms_pSingleton);
		KSingleton<T>::ms_pSingleton = (T*)this;
	}
	~KSingleton() {
		printf("~KSingleton()\n");
		KSingleton<T>::ms_pSingleton = NULL;
	}
	static T* GetSingleton() {
		printf("GetSingleton()\n");
		return ms_pSingleton;
	}
};

template<typename T> T* KSingleton<T>::ms_pSingleton = NULL;
class CWinApp : public KSingleton<CWinApp> {
public:
	void Print() {
		printf("function(hello)\n");
		printf("hello\n");
	}
};

CWinApp theApp;

void main() {

	AfxGetApp()->Print();
}