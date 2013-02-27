// TotalNum.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "TotalNum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTotalNum dialog


CTotalNum::CTotalNum(CWnd* pParent /*=NULL*/)
	: CDialog(CTotalNum::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTotalNum)
	m_engnum = 5;
	m_softnum = 20;
	//}}AFX_DATA_INIT
}


void CTotalNum::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTotalNum)
	DDX_Text(pDX, IDC_EDIT_ENG, m_engnum);
	DDX_Text(pDX, IDC_EDIT_SOFT, m_softnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTotalNum, CDialog)
	//{{AFX_MSG_MAP(CTotalNum)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTotalNum message handlers
