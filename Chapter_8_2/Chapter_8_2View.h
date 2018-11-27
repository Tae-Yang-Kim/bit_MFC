
// Chapter_8_2View.h: CChapter82View 클래스의 인터페이스
//

#pragma once


class CChapter82View : public CView
{
protected: // serialization에서만 만들어집니다.
	CChapter82View() noexcept;
	DECLARE_DYNCREATE(CChapter82View)

// 특성입니다.
public:
	CChapter82Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CChapter82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Chapter_8_2View.cpp의 디버그 버전
inline CChapter82Doc* CChapter82View::GetDocument() const
   { return reinterpret_cast<CChapter82Doc*>(m_pDocument); }
#endif

