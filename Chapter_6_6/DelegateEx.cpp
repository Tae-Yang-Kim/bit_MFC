#include <stdio.h>

class KBase
{
public:
    int m_aiData[10];

    void BaseFun(int i, float f)
    {
        printf( "KBase::BaseFun() this=%p\n", this );
    }
};

//���߻�ӽ� ��ȣ���̶�� �޼����� ���ٵ� �̰��� �ذ��ϱ�����
//��ӽ� virtual�� �ٿ� �ذ� �� �� �ִ�.
class KMiddle : virtual public KBase
{
public:
    int m_aiData[10];
};

class KMiddle2 : virtual public KBase
{
public:
    int m_aiData[20];
};

class KDerived : public KMiddle, public KMiddle2
{
public:
    int m_aiData[30];
};

void main()
{
    KDerived    d;

    d.BaseFun( 1, 2.f );
}//main()