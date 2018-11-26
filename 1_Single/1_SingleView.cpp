
// 1_SingleView.cpp: CMy1SingleView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1_Single.h"
#endif

#include "1_SingleDoc.h"
#include "1_SingleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1SingleView

IMPLEMENT_DYNCREATE(CMy1SingleView, CView)

BEGIN_MESSAGE_MAP(CMy1SingleView, CView)
END_MESSAGE_MAP()

// CMy1SingleView 생성/소멸

CMy1SingleView::CMy1SingleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1SingleView::~CMy1SingleView()
{
}

BOOL CMy1SingleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1SingleView 그리기

void CMy1SingleView::OnDraw(CDC* /*pDC*/)
{
	CMy1SingleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy1SingleView 진단

#ifdef _DEBUG
void CMy1SingleView::AssertValid() const
{
	CView::AssertValid();
}

void CMy1SingleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1SingleDoc* CMy1SingleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1SingleDoc)));
	return (CMy1SingleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy1SingleView 메시지 처리기
