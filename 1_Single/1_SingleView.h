
// 1_SingleView.h: CMy1SingleView 클래스의 인터페이스
//

#pragma once


class CMy1SingleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1SingleView() noexcept;
	DECLARE_DYNCREATE(CMy1SingleView)

// 특성입니다.
public:
	CMy1SingleDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy1SingleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 1_SingleView.cpp의 디버그 버전
inline CMy1SingleDoc* CMy1SingleView::GetDocument() const
   { return reinterpret_cast<CMy1SingleDoc*>(m_pDocument); }
#endif

