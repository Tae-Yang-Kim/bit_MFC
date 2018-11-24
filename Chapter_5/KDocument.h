#include "KListBox.h"
#include "KView.h"

class KDocument
{
public:
	typedef KListBox<int>::VITOR KDITOR;

private:
	KListBox<int>	m_kListBox;
	KView* m_pView;

public:
	KDocument();
	virtual ~KDocument();

	void Insert(int iData);
	void SetView(KView* pView);
	KView* GetView();
	KListBox<int>* GetListBox();
};