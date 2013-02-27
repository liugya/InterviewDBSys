// StyleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "StyleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg dialog


CStyleDlg::CStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStyleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStyleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	tping = 1;
	fping = 0;
}


void CStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStyleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStyleDlg, CDialog)
	//{{AFX_MSG_MAP(CStyleDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg message handlers



BOOL CStyleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStyleDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	fping = 0;
	tping = 1;
}

void CStyleDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	fping = 1;
	tping = 0;
}
