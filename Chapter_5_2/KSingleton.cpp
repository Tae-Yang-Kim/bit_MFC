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
		//assert함수는 특정한에러를 뿜어내는 함수이고
		//객체가 만들어져서 생성자가 호출되는데 이때 static으로 선언된 이 객체가
		//다시 생성되지 않도록 해놓은것
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