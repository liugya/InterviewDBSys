// ExamView.h : interface of the CExamView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXAMVIEW_H__541D1E05_4BE5_4CAC_A5FE_F6BAF6294D9A__INCLUDED_)
#define AFX_EXAMVIEW_H__541D1E05_4BE5_4CAC_A5FE_F6BAF6294D9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <fstream.h>
class CExamView : public CScrollView
{
protected: // create from serialization only
	CExamView();
	DECLARE_DYNCREATE(CExamView)

// Attributes
public:
	CExamDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	void ChangeFile2();
	void count();
	void ShowTotalText(int, bool);
	void Random(int e, int s);
	void AddBk();
	void ChangeFile();
	void RandomSerial(int);
	void ShowText(int);
	void OnFileImport();
	virtual ~CExamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExamView)
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ExamView.cpp
inline CExamDoc* CExamView::GetDocument()
   { return (CExamDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMVIEW_H__541D1E05_4BE5_4CAC_A5FE_F6BAF6294D9A__INCLUDED_)
