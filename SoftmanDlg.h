#if !defined(AFX_SOFTMANDLG_H__7797115B_ED20_437A_B0CB_041793053920__INCLUDED_)
#define AFX_SOFTMANDLG_H__7797115B_ED20_437A_B0CB_041793053920__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SoftmanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSoftmanDlg dialog

class CSoftmanDlg : public CDialog
{
// Construction
public:
	CSoftmanDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSoftmanDlg)
	enum { IDD = IDD_DIALOG_SOFTMAN };
	int		m_softMan;
	int		m_softMan2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoftmanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSoftmanDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOFTMANDLG_H__7797115B_ED20_437A_B0CB_041793053920__INCLUDED_)
