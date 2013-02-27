#if !defined(AFX_CONFIG_H__ED5F9947_19A0_40E6_A18D_6F8A928C3748__INCLUDED_)
#define AFX_CONFIG_H__ED5F9947_19A0_40E6_A18D_6F8A928C3748__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Config.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConfig dialog

class CConfig : public CDialog
{
// Construction
public:
	CConfig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConfig)
	enum { IDD = IDD_DIALOG_CONFIG };
	int		m_config;
	int		m_config2;
	int		m_staEng;
	int		m_staSoft;
	int		m_widEng;
	int		m_widSoft;
	int		m_engFont;
	int		m_softFont;
	int		m_engH;
	int		m_softH;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConfig)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIG_H__ED5F9947_19A0_40E6_A18D_6F8A928C3748__INCLUDED_)
