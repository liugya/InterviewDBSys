#if !defined(AFX_STYLEDLG_H__851EB4AB_4789_49C3_B4A5_54C526A40818__INCLUDED_)
#define AFX_STYLEDLG_H__851EB4AB_4789_49C3_B4A5_54C526A40818__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StyleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg dialog

class CStyleDlg : public CDialog
{
// Construction
public:
	CStyleDlg(CWnd* pParent = NULL);   // standard constructor
    int fping;
	int tping;
// Dialog Data
	//{{AFX_DATA(CStyleDlg)
	enum { IDD = IDD_DIALOG_SHOWSTYLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStyleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStyleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLEDLG_H__851EB4AB_4789_49C3_B4A5_54C526A40818__INCLUDED_)
