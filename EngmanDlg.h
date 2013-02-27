#if !defined(AFX_ENGMANDLG_H__82EA965E_A96B_492F_B23B_ADA6A91618E9__INCLUDED_)
#define AFX_ENGMANDLG_H__82EA965E_A96B_492F_B23B_ADA6A91618E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EngmanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEngmanDlg dialog

class CEngmanDlg : public CDialog
{
// Construction
public:
	CEngmanDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEngmanDlg)
	enum { IDD = IDD_DIALOG_ENGMAN };
	CEdit	m_engManC;
	int		m_engMan;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngmanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEngmanDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGMANDLG_H__82EA965E_A96B_492F_B23B_ADA6A91618E9__INCLUDED_)
