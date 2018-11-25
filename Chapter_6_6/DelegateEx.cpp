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

//다중상속시 모호함이라는 메세지가 뜰텐데 이것을 해결하기위해
//상속시 virtual을 붙여 해결 할 수 있다.
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