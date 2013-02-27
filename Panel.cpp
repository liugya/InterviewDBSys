// Panel.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "Panel.h"

#include "ImportDlg.h"
#include "ExamDoc.h"
#include "Config.h"
#include "MainFrm.h"
#include "TotalNum.h"
#include "ExamView.h"
#include "SoftManDlg.h"
#include "EngmanDlg.h"
#include "StatusDlg.h"
#include "StyleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPanel

IMPLEMENT_DYNCREATE(CPanel, CFormView)

CPanel::CPanel()
	: CFormView(CPanel::IDD)
{
	//{{AFX_DATA_INIT(CPanel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPanel::~CPanel()
{
}

void CPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPanel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPanel, CFormView)
	//{{AFX_MSG_MAP(CPanel)
	ON_BN_CLICKED(IDC_ENGLISH, OnEnglish)
	ON_BN_CLICKED(IDC_RETEST, OnRetest)
	ON_BN_CLICKED(IDC_SOFT, OnSoft)
	ON_BN_CLICKED(IDC_CONFIG, OnConfig)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_BN_CLICKED(IDC_BUTTON_SOFTMAN, OnButtonSoftman)
	ON_BN_CLICKED(IDC_BUTTON_ENGMAN, OnButtonEngman)
	ON_COMMAND(IDM_SHOW, OnShow)
	ON_BN_CLICKED(IDC_BUTTON_TOTALTEST, OnButtonTotaltest)
	ON_BN_CLICKED(IDC_BUTTON_STATUS, OnButtonStatus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPanel diagnostics

#ifdef _DEBUG
void CPanel::AssertValid() const
{
	CFormView::AssertValid();
}

void CPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPanel message handlers

void CPanel::OnEnglish() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	pDoc->m_eng = true;
	pDoc->m_soft = false;
	pDoc->BSoftMan = false;
	pDoc->BEngMan = false;
	pDoc->TotalTest = false;

	pDoc->hang = 100;

	if(pDoc->stu == 1)
	{
		GetDlgItem(IDC_ENGLISH)->EnableWindow(false);
	}
	
	for(int i = 0; i< 300; i++)
	{
		pDoc->c[i] = INT_MAX;
		pDoc->serial[i] = INT_MAX;
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnRetest() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	pDoc->m_eng = false;
	pDoc->m_soft = false;
	pDoc->BSoftMan = false;
	pDoc->BEngMan = false;
	pDoc->TotalTest = false;
	if(pDoc->stu == 1 && pDoc->tea == 0)
	{
		GetDlgItem(IDC_BUTTON_STATUS)->EnableWindow(false);
		GetDlgItem(IDC_CONFIG)->EnableWindow(true);
		//GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_ENGMAN)->EnableWindow(false);
		//GetDlgItem(IDC_ENGLISH)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_SOFTMAN)->EnableWindow(false);
		//GetDlgItem(IDC_SOFT)->EnableWindow(false);
		if(pDoc->fping == 1)
		{
			GetDlgItem(IDC_ENGLISH)->EnableWindow(true);
			GetDlgItem(IDC_SOFT)->EnableWindow(true);
			GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(false);
		}
		else if(pDoc->tping == 1)
		{
			GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(true);
			GetDlgItem(IDC_ENGLISH)->EnableWindow(false);
			GetDlgItem(IDC_SOFT)->EnableWindow(false);
		}
	}
	else if(pDoc->stu == 0 && pDoc->tea == 1)
	{
		GetDlgItem(IDC_BUTTON_STATUS)->EnableWindow(false);
		GetDlgItem(IDC_CONFIG)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_ENGMAN)->EnableWindow(true);
		GetDlgItem(IDC_ENGLISH)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_SOFTMAN)->EnableWindow(true);
		GetDlgItem(IDC_SOFT)->EnableWindow(true);
	}
	

	pDoc->hang = 100;

	for(int i = 0; i< 300; i++)
	{
		pDoc->c[i] = INT_MAX;
		pDoc->serial[i] = INT_MAX;
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnSoft() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();

	pDoc->m_soft =true;
	pDoc->m_eng =false;
	pDoc->BSoftMan = false;
	pDoc->BEngMan = false;
	pDoc->TotalTest = false;

	pDoc->hang = 100;

	if(pDoc->stu == 1)
	{
		GetDlgItem(IDC_SOFT)->EnableWindow(false);
	}
	for(int i = 0; i< 300; i++)
	{
		pDoc->c[i] = INT_MAX;
		pDoc->serial[i] = INT_MAX;
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnConfig() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	//OnButtonTotaltest();
	//pDoc->TotalTest = false;
	CStyleDlg s;
	if(s.DoModal() == IDOK)
	{
		bool x = s.fping || s.tping;
		if(!x)
		{
			MessageBox("必须选择显示方式，才能进入下一步","警告窗口",MB_ICONINFORMATION);
		}
		else
		{
			GetDlgItem(IDC_CONFIG)->EnableWindow(false);
			if(s.fping == 1)
			{
				pDoc->fping = 1;
				pDoc->tping = 0;
				GetDlgItem(IDC_ENGLISH)->EnableWindow(true);
				GetDlgItem(IDC_SOFT)->EnableWindow(true);
				GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(false);
			}
			else
			{
				pDoc->tping = 1;
				pDoc->fping = 0;
				GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(true);
				GetDlgItem(IDC_ENGLISH)->EnableWindow(false);
				GetDlgItem(IDC_SOFT)->EnableWindow(false);
			}
		}
	}
	else
	{
		OnRetest();
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnExit() 
{
	// TODO: Add your control notification handler code here
	int m=MessageBox("确实要退出该随机抽题系统么？","提示信息",
		     MB_ICONQUESTION|MB_YESNO);
    if(m==IDYES)
	{
	   
		CDocument *Doc;
        CSingleDocTemplate* pNewDocTemplate;
        CWnd* m_pMainWnd;
   
    	CExamApp *p=(CExamApp*) AfxGetApp(); 
        m_pMainWnd=p->GetMainWnd();
        pNewDocTemplate=p->pDocTemplate;  
        CFrameWnd *ActiveWnd=((CMainFrame*)m_pMainWnd)->GetActiveFrame();
        Doc=ActiveWnd->GetActiveDocument();
		::PostMessage(GetParentFrame()->m_hWnd, WM_CLOSE, 0, 0L);
	}
}

class CExamView;
void CPanel::OnFileImport() 
{
	// TODO: Add your command handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	CImportDlg dlg;
	
	ChangeFilePanel();
	
	pDoc->m_eng = false;
	pDoc->m_soft = false;
	pDoc->BEngMan = false;
	pDoc->BSoftMan = false;
	pDoc->TotalTest = false;

	pDoc->hang = 100;
	
	for(int i = 0; i< 300; i++)
	{
		pDoc->c[i] = INT_MAX;
		pDoc->serial[i] = INT_MAX;
	}
	
	GetDocument()->UpdateAllViews(this);
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.m_Fsoftware.IsEmpty())
		{
			MessageBox("专业试题库不能为空,请重新设置!","提示窗口",MB_ICONINFORMATION);
			return;
		}
		else if(dlg.m_Fenglish.IsEmpty())
		{
			MessageBox("英语试题库不能为空,请重新设置!","提示窗口",MB_ICONINFORMATION);
			return;
		}
		else
		{
			pDoc->english = dlg.m_Fenglish;
			pDoc->software = dlg.m_Fsoftware;
			MessageBox("题库导入成功!","提示窗口",MB_ICONINFORMATION);
		}
	}
	else
	{
		OnRetest();
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::ChangeFilePanel()
{
	CExamDoc* pDoc = (CExamDoc*) GetDocument();
	CImportDlg dlg;
	fstream ineng, insoft;
	fstream outeng, outsoft;
	
	ineng.open(pDoc->english, ios::in);
	insoft.open(pDoc->software, ios::in);


	char bufeng[100];
	char bufsoft[100];
	char streng[100000] = "";//save *.txt file string
	char strsoft[10000] = "";
	while(!ineng.eof())
	{
		ineng.getline(bufeng, sizeof(bufeng));
		strcat(streng, bufeng);
	}
	while(!insoft.eof())
	{
		insoft.getline(bufsoft, sizeof(bufsoft));
		strcat(strsoft, bufsoft);
	}
	ineng.close();
	insoft.close();
	//now string char str[] 
	
	//outeng.open(pDoc->englishc, ios::out);
	outeng.open("C:/eng.txt", ios::out);
	outsoft.open(pDoc->softwarec, ios::out);
	
	char *pe = streng;
	int count = 0;//??
	while (*pe != '\0')
	{
		//怎样才不会把单词截断?
		if(*pe == '#')
		{
			outeng.put('\n');
			
			count = 0;
		}
		if(!(*pe & 0x80))//output english
		{
			outeng.put(*pe);
			pe++;
			count++;
		}
		else//output chinese
		{
			outeng.put(*pe++);
			outeng.put(*pe);
			pe++;
			count += 2;
			if (count >= pDoc->widthEng)//大概范围 
			{
				outeng.put('\n');
				outeng.put(' ');
				outeng.put(' ');
				outeng.put(' ');
				//cout << endl;
				count = 0;//reset count
			}
		}
		
		if (count >= pDoc->widthEng)//大概范围 
		{ 	
			//if(!(((*pe)<='z' &&(*pe)>='a') || ((*pe)<='Z' &&(*pe)>='A') || (*pe) == ',' || (*pe) == '?'|| (*pe) == '.'|| (*pe) == ';' || (*pe) == 0x27))
			if(*pe == ' ')
			{
				outeng.put('\n');
				outeng.put(' ');
				outeng.put(' ');
				outeng.put(' ');
				count = 0;//reset count
			}
			
		}
	}
	outeng.close();
	
	char *ps = strsoft;
	int count2 = 0;//??
	while (*ps != '\0')
	{
		//怎样才不会把单词截断?
		if(*ps == '#')
		{
			outsoft.put('\n');			
			count2 = 0;
		}
		if(!(*ps & 0x80))//output english
		{
			outsoft.put(*ps);
			ps++;
			count2++;
		}
		else//output chinese
		{
			outsoft.put(*ps++);
			outsoft.put(*ps);
			ps++;
			count2 += 2;
			if (count2 >= pDoc->widthSoft)//大概范围 
			{
				outsoft.put('\n');
				outsoft.put(' ');
				outsoft.put(' ');
				outsoft.put(' ');
				count2 = 0;//reset count
			}
		}
		
		if (count2 >= pDoc->widthSoft)//大概范围 
		{ 	
			//if(!(((*ps) <= 'z' &&(*ps) >= 'a') || ((*ps) <= 'Z' &&(*ps) >= 'A') || (*ps) == ',' || (*ps) == '?'|| (*ps) == '.'|| (*ps) == ';' || (*ps) == 0x27))
			if(*ps == ' ')
			{
				outsoft.put('\n');
				outsoft.put(' ');
				outsoft.put(' ');
				outsoft.put(' ');
				count2 = 0;//reset count
			}
		}
	}
	outsoft.close();
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnButtonSoftman() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc = (CExamDoc*) GetDocument();

	pDoc->BSoftMan = true;
	pDoc->BEngMan = false;
	pDoc->m_eng = false;
	pDoc->m_soft = false;
	pDoc->TotalTest = false;

	CSoftmanDlg dlg;
	CString str;
	str.Format("现有专业题目数量为:%d,题号越界!", pDoc->soft_num-1);
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.m_softMan <= 0 || dlg.m_softMan2 <= 0)
		{
			pDoc->BSoftMan = false;
			MessageBox("请输入大于0的数!","提示窗口",MB_ICONINFORMATION);
			return;
		}
		if(dlg.m_softMan > pDoc->soft_num || dlg.m_softMan2 > pDoc->soft_num)
		{
			pDoc->BSoftMan = false;
			MessageBox(str,"提示窗口",MB_ICONINFORMATION);
			return;
		}
		if (dlg.m_softMan >= dlg.m_softMan2)
		{
			int tmp;
			tmp = dlg.m_softMan;
			dlg.m_softMan = dlg.m_softMan2;
			dlg.m_softMan2 = tmp;
		}
		pDoc->SoftMan = dlg.m_softMan;
		pDoc->SoftMan2 = dlg.m_softMan2;
	
	}
	else
	{
		OnRetest();
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnButtonEngman() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc = (CExamDoc*) GetDocument();

	pDoc->BEngMan = true;
	pDoc->BSoftMan = false;
	pDoc->m_eng = false;
	pDoc->m_soft = false;
	pDoc->TotalTest = false;

	CEngmanDlg dlg;
	CString str;
	str.Format("现有英语题目数量为:%d,题号越界!", pDoc->eng_num-1);
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.m_engMan <= 0)
		{
			pDoc->BEngMan = false;
			MessageBox("请输入大于0的数!","提示窗口",MB_ICONINFORMATION);
			return;
		}
		if(dlg.m_engMan > pDoc->eng_num)
		{
			pDoc->BEngMan = false;
			MessageBox(str,"提示窗口",MB_ICONINFORMATION);
			return;
		}
		pDoc->EngMan = dlg.m_engMan;
		//MessageBox("题库导入成功!","提示窗口",MB_ICONINFORMATION);
	}
	else
	{
		OnRetest();
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnShow() 
{
	// TODO: Add your command handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	CConfig con;

	pDoc->m_eng = false;
	pDoc->m_soft = false;
	pDoc->BEngMan = false;
	pDoc->BSoftMan = false;
	pDoc->TotalTest = false;

	int r = con.DoModal();
	if(r == IDOK)
	{
		pDoc->size = con.m_config;//英语
		pDoc->size2 = con.m_config2;//专业
		pDoc->startEng = con.m_staEng;
		pDoc->startSoft = con.m_staSoft;
		pDoc->widthEng = con.m_widEng;
		pDoc->widthSoft = con.m_widSoft;
		pDoc->engFont = con.m_engFont;
		pDoc->softFont = con.m_softFont;
		pDoc->engH = con.m_engH;
		pDoc->softH = con.m_softH;
		MessageBox("设置成功!如果修改了题目的输出长度，请重新倒入文件!","提示窗口",MB_ICONINFORMATION);
	}
	else
	{
		OnRetest();
	}
	
	pDoc->hang = 100;
	
	for(int i = 0; i< 300; i++)
	{
		pDoc->c[i] = INT_MAX;
		pDoc->serial[i] = INT_MAX;
	}
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnButtonTotaltest() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	if(pDoc->stu == 1)
	{
		GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(false);
	}
	GetDlgItem(IDC_CONFIG)->EnableWindow(false);
	pDoc->TotalTest = true;
	pDoc->m_eng = false;
	pDoc->m_soft = false;
	pDoc->BEngMan = false;
	pDoc->BSoftMan = false;
	
	GetDocument()->UpdateAllViews(this);
}

void CPanel::OnButtonStatus() 
{
	// TODO: Add your control notification handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	OnButtonTotaltest();
	pDoc->TotalTest = false;
	CStatusDlg s;
	if(s.DoModal() == IDOK)
	{
		bool x = s.stu || s.tea;
		if(!x)
		{
			MessageBox("必须选择身份，才能进入下一步","警告窗口",MB_ICONINFORMATION);
		}
		else
		{
			GetDlgItem(IDC_RETEST)->EnableWindow(true);
			GetDlgItem(IDC_BUTTON_STATUS)->EnableWindow(false);
			if(s.stu == 1)
			{
				pDoc->stu = 1;
				pDoc->tea = 0;
				GetDlgItem(IDC_CONFIG)->EnableWindow(true);
				GetDlgItem(IDC_EXIT)->EnableWindow(false);
			}
			else
			{
				pDoc->stu = 0;
				pDoc->tea = 1;
				GetDlgItem(IDC_BUTTON_STATUS)->EnableWindow(false);
				GetDlgItem(IDC_CONFIG)->EnableWindow(false);
				GetDlgItem(IDC_BUTTON_TOTALTEST)->EnableWindow(true);
				GetDlgItem(IDC_BUTTON_ENGMAN)->EnableWindow(true);
				GetDlgItem(IDC_ENGLISH)->EnableWindow(true);
				GetDlgItem(IDC_BUTTON_SOFTMAN)->EnableWindow(true);
				GetDlgItem(IDC_SOFT)->EnableWindow(true);
			}
		}
	}
	else
	{
		OnRetest();
	}
	GetDocument()->UpdateAllViews(this);
}
