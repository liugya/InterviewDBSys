// ExamDoc.cpp : implementation of the CExamDoc class
//

#include "stdafx.h"
#include "Exam.h"

#include "ExamDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamDoc

IMPLEMENT_DYNCREATE(CExamDoc, CDocument)

BEGIN_MESSAGE_MAP(CExamDoc, CDocument)
	//{{AFX_MSG_MAP(CExamDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamDoc construction/destruction

CExamDoc::CExamDoc()
{
	// TODO: add one-time construction code here
	m_eng = false;
	m_soft = false;
	hang = 95;//初始位置

	hang1 = 90;
	
	size = 1;//英语
	size2 = 4;//专业

	eng_num = 100;//英语题库
	soft_num = 100;//专业题库
	for(int i = 0; i< 300; i++)
	{//题目排序专用
		c[i] = INT_MAX;
		serial[i] = INT_MAX;
		serE[i] = INT_MAX;
	    serS[i] = INT_MAX;
	}
	english = "eng.txt";
	software = "soft.txt";
	englishc = "english.txt";
	softwarec = "software.txt";
	softwarelong = "softlong.txt";
	englishlong = "englong.txt";

	startEng = 28;
	startSoft = 28;
	widthEng = 55;
	widthSoft = 58;
	engFont = 30;
	softFont = 30;

	x = 130;
	y = 250;

	engH = 33;//英语行间间隔
	softH = 35;//专业行间间隔

	BSoftMan = false;//按钮
	SoftMan = 1;//专业题号1
	SoftMan = 2;//专业题号2

	BEngMan = false;//按钮
	EngMan = 1;//英语题号

	TotalTest = false;

	stu = 0;
	tea = 0;

	fping = 0;
	tping = 0;


}

CExamDoc::~CExamDoc()
{
}

BOOL CExamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExamDoc serialization

void CExamDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExamDoc diagnostics

#ifdef _DEBUG
void CExamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExamDoc commands

void CExamDoc::SetTitle(LPCTSTR lpszTitle) 
{
	// TODO: Add your specialized code here and/or call the base class
	lpszTitle="西安交通大学软件学院硕士研究生面试随机抽题系统  2.0版  Good Luck!";
	CDocument::SetTitle(lpszTitle);
}
