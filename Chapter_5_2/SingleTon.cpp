#include<iostream>
using namespace std;
class SingleTon {
private:
	int n;
	int m;
	SingleTon() {}
	static SingleTon instance;
public:
	static SingleTon* GetInstance() {
		return &instance;
	}
	void SetData(int a, int b) {
		n = a;
		m = b;
	}
	void Print() {
		cout << "m : " << m << " n : " << n << endl;
	}
};

SingleTon SingleTon::instance;

int main() {
	SingleTon* pInstance = SingleTon::GetInstance();
	pInstance->SetData(10, 20);
}