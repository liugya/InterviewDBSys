// ImportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "ImportDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImportDlg dialog


CImportDlg::CImportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImportDlg)
	m_Fenglish = _T("eng.txt");
	m_Fsoftware = _T("soft.txt");
	//}}AFX_DATA_INIT
}


void CImportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImportDlg)
	DDX_Text(pDX, IDC_EDIT_ENG, m_Fenglish);
	DDX_Text(pDX, IDC_EDIT_SOFT, m_Fsoftware);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImportDlg, CDialog)
	//{{AFX_MSG_MAP(CImportDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImportDlg message handlers
