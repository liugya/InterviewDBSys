// SoftmanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "SoftmanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSoftmanDlg dialog


CSoftmanDlg::CSoftmanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoftmanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoftmanDlg)
	m_softMan = 0;
	m_softMan2 = 0;
	//}}AFX_DATA_INIT
}


void CSoftmanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoftmanDlg)
	DDX_Text(pDX, IDC_EDIT1, m_softMan);
	DDX_Text(pDX, IDC_EDIT2, m_softMan2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSoftmanDlg, CDialog)
	//{{AFX_MSG_MAP(CSoftmanDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoftmanDlg message handlers
