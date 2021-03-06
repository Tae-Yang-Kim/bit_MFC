#include<iostream>
#include<conio.h>
#include<Windows.h>

#define KEY_ESC 27

using std::cout;
using std::endl;

class CAccount {
public:
	enum {
		STATE_IDLE,
		STATE_INPUT,
		STATE_WAIT_ACK,

		STATE_MAX
	};
public:
	int m_iState;

	CAccount();
	void OnIdle();
	void OnInput();
	void OnWaitAck();

	void SetState(int iState);
	void Render();
};

CAccount::CAccount() {
	m_iState = STATE_IDLE;
}

void CAccount::OnIdle() {
	cout << "OnIdle()" << endl;
}

void CAccount::OnInput() {
	cout << "OnInput()" << endl;
}

void CAccount::OnWaitAck() {
	cout << "OnWaitAck()" << endl;
}

void CAccount::SetState(int iState) {
	m_iState = iState;
}

void CAccount::Render() {
	static void (CAccount::*mfp[])() = {
		&CAccount::OnIdle,
		&CAccount::OnInput,
		&CAccount::OnWaitAck
	};
	
	if (m_iState >= 0 && m_iState < STATE_MAX) {
		(this->*mfp[m_iState])();
	}

}

void main() {
	CAccount account;
	int ch = 0;

	while (ch != KEY_ESC) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == '1')
				account.SetState(CAccount::STATE_IDLE);
			else if (ch == '2')
				account.SetState(CAccount::STATE_INPUT);
			else if (ch == '3')
				account.SetState(CAccount::STATE_WAIT_ACK);
		}

		Sleep(100);
		account.Render();
	}
}