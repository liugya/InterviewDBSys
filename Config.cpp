// Config.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "Config.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfig dialog


CConfig::CConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfig)
	m_config = 1;
	m_config2 = 4;
	m_staEng = 28;
	m_staSoft = 28;
	m_widEng = 55;
	m_widSoft = 58;
	m_engFont = 30;
	m_softFont = 30;
	m_engH = 33;
	m_softH = 35;
	//}}AFX_DATA_INIT
}


void CConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfig)
	DDX_Text(pDX, IDC_EDIT1, m_config);
	DDX_Text(pDX, IDC_EDIT2, m_config2);
	DDX_Text(pDX, IDC_EDIT_STARTENG, m_staEng);
	DDX_Text(pDX, IDC_EDIT_STARTSOFT, m_staSoft);
	DDX_Text(pDX, IDC_EDIT_WIDTHENG, m_widEng);
	DDX_Text(pDX, IDC_EDIT_WIDTHSOFT, m_widSoft);
	DDX_Text(pDX, IDC_EDIT_FONTENG, m_engFont);
	DDX_Text(pDX, IDC_EDIT_FONTSOFT, m_softFont);
	DDX_Text(pDX, IDC_EDIT_ENGH, m_engH);
	DDX_Text(pDX, IDC_EDIT_SOFTH, m_softH);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfig, CDialog)
	//{{AFX_MSG_MAP(CConfig)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfig message handlers
