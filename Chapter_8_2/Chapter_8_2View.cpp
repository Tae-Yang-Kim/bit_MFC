
// Chapter_8_2View.cpp: CChapter82View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Chapter_8_2.h"
#endif

#include "Chapter_8_2Doc.h"
#include "Chapter_8_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChapter82View

IMPLEMENT_DYNCREATE(CChapter82View, CView)

BEGIN_MESSAGE_MAP(CChapter82View, CView)
END_MESSAGE_MAP()

// CChapter82View 생성/소멸

CChapter82View::CChapter82View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CChapter82View::~CChapter82View()
{
}

BOOL CChapter82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CChapter82View 그리기

void CChapter82View::OnDraw(CDC* /*pDC*/)
{
	CChapter82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CChapter82View 진단

#ifdef _DEBUG
void CChapter82View::AssertValid() const
{
	CView::AssertValid();
}

void CChapter82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChapter82Doc* CChapter82View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChapter82Doc)));
	return (CChapter82Doc*)m_pDocument;
}
#endif //_DEBUG


// CChapter82View 메시지 처리기
