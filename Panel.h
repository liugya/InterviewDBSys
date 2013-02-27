#if !defined(AFX_PANEL_H__9D9229DB_E754_49BC_9783_1CD5A4039BA0__INCLUDED_)
#define AFX_PANEL_H__9D9229DB_E754_49BC_9783_1CD5A4039BA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Panel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPanel form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CPanel : public CFormView
{
protected:
	CPanel();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPanel)

// Form Data
public:
	//{{AFX_DATA(CPanel)
	enum { IDD = IDD_FORMVIEW_CONTROL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void ChangeFilePanel();
	afx_msg void OnRetest();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPanel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPanel();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPanel)
	afx_msg void OnEnglish();
	//afx_msg void OnRetest();
	afx_msg void OnSoft();
	afx_msg void OnConfig();
	afx_msg void OnExit();
	afx_msg void OnFileImport();
	afx_msg void OnButtonSoftman();
	afx_msg void OnButtonEngman();
	afx_msg void OnShow();
	afx_msg void OnButtonTotaltest();
	afx_msg void OnButtonStatus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PANEL_H__9D9229DB_E754_49BC_9783_1CD5A4039BA0__INCLUDED_)
