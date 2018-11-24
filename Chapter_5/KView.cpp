#include "KView.h"
#include "KDocument.h"
#include <iostream>

using std::cout;
using std::endl;

KView::KView(KDocument* pDoc)
{
	m_pDocument = pDoc;
	m_iStart = 0;
	m_iDisplayStart = 0;
	m_iSelected = 0;
}

KView::~KView()
{
}

void KView::SetDocument(KDocument* pDoc)
{
	m_pDocument = pDoc;
}

KDocument* KView::GeDocument()
{
	return m_pDocument;
}

void KView::SetDisplayStart(int iDisplayStart)
{
	m_iDisplayStart = iDisplayStart;
		m_iStart = GeDocument()->GetListBox()->SetDisplayStart(m_iDisplayStart);
}

void KView::SetSelected(int iSelected)
{
	m_iSelected = iSelected;
	GeDocument()->GetListBox()->SetSelected(m_iSelected);
}

void KView::Draw()
{
	int iStart = m_iStart;
	for (KDocument::KDITOR itor = GeDocument()->GetListBox()->BeginDisplay(); \
		itor != GeDocument()->GetListBox()->EndDisplay(); ++itor)
	{
		if (GeDocument()->GetListBox()->IsSelected(iStart))
			cout << "* ";
		else
			cout << "  ";
		cout << "element value = " << (*itor) << endl;
		++iStart;
	}
}