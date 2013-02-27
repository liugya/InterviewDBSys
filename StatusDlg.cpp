// StatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "StatusDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusDlg dialog


CStatusDlg::CStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	stu = 1;
	tea = 0;	
}


void CStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatusDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CStatusDlg)
	ON_BN_CLICKED(IDC_RADIO_STU, OnRadioStu)
	ON_BN_CLICKED(IDC_RADIO_TEA, OnRadioTea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusDlg message handlers

void CStatusDlg::OnRadioStu() 
{
	// TODO: Add your control notification handler code here
	stu = 1;
	tea = 0;
}

void CStatusDlg::OnRadioTea() 
{
	// TODO: Add your control notification handler code here
	stu = 0;
	tea = 1;
}

BOOL CStatusDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO_STU, IDC_RADIO_TEA, IDC_RADIO_STU);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
