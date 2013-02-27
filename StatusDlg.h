#if !defined(AFX_STATUSDLG_H__B920C82F_32EC_47FD_B215_3756EB80E1AD__INCLUDED_)
#define AFX_STATUSDLG_H__B920C82F_32EC_47FD_B215_3756EB80E1AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatusDlg dialog

class CStatusDlg : public CDialog
{
// Construction
public:
	CStatusDlg(CWnd* pParent = NULL);   // standard constructor
	int stu;
	int tea;
	
// Dialog Data
	//{{AFX_DATA(CStatusDlg)
	enum { IDD = IDD_DIALOG_STATUS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStatusDlg)
	afx_msg void OnRadioStu();
	afx_msg void OnRadioTea();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSDLG_H__B920C82F_32EC_47FD_B215_3756EB80E1AD__INCLUDED_)
