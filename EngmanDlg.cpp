// EngmanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "EngmanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEngmanDlg dialog


CEngmanDlg::CEngmanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEngmanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEngmanDlg)
	m_engMan = 0;
	//}}AFX_DATA_INIT
}


void CEngmanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEngmanDlg)
	DDX_Control(pDX, IDC_EDIT_ENG, m_engManC);
	DDX_Text(pDX, IDC_EDIT_ENG, m_engMan);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEngmanDlg, CDialog)
	//{{AFX_MSG_MAP(CEngmanDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEngmanDlg message handlers

BOOL CEngmanDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_engManC.SetSel(0, -1);
	m_engManC.ReplaceSel("");
	m_engManC.GetFocus();
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
