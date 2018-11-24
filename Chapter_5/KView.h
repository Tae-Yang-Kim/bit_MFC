#pragma once
class KDocument;
class KView
{
private:
	KDocument*	m_pDocument;
	int			m_iStart;
	int			m_iDisplayStart;
	int			m_iSelected;

public:
	KView(KDocument* pDoc);
	virtual ~KView();

	void SetDocument(KDocument* pDoc);
	KDocument* GeDocument();
	void SetDisplayStart(int iStart);
	void SetSelected(int iSelected);
	virtual void Draw();
}; 