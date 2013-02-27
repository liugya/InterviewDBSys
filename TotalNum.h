#if !defined(AFX_TOTALNUM_H__12FAABFD_F1C1_4AE9_9968_CF0FEF2DD036__INCLUDED_)
#define AFX_TOTALNUM_H__12FAABFD_F1C1_4AE9_9968_CF0FEF2DD036__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TotalNum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTotalNum dialog

class CTotalNum : public CDialog
{
// Construction
public:
	CTotalNum(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTotalNum)
	enum { IDD = IDD_DIALOG_TOTAL };
	int		m_engnum;
	int		m_softnum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTotalNum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTotalNum)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOTALNUM_H__12FAABFD_F1C1_4AE9_9968_CF0FEF2DD036__INCLUDED_)
