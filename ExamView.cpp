// ExamView.cpp : implementation of the CExamView class
//

#include "stdafx.h"
#include "Exam.h"

#include <fstream.h>
#include <stdlib.h>

#include "Config.h"
#include  "ImportDlg.h"
#include "ExamDoc.h"
#include "ExamView.h"
#include "ImportDlg.h"

#include<time.h>

#include <fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamView

IMPLEMENT_DYNCREATE(CExamView, CScrollView)

BEGIN_MESSAGE_MAP(CExamView, CScrollView)
	//{{AFX_MSG_MAP(CExamView)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_COMMAND(IDM_SHOW, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamView construction/destruction

CExamView::CExamView()
{
	// TODO: add construction code here

}

CExamView::~CExamView()
{
}

BOOL CExamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExamView drawing

void CExamView::OnDraw(CDC* pDC)
{
	CExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CClientDC dc(this);

	count();
	CString str,s[5];

    char ch;
	int i = 0;
	int count = 0;
	fstream infile;
	if(pDoc->m_eng == true || pDoc->BEngMan == true)
	{
		infile.open(pDoc->englishc,ios::in);
		if(!infile)
		{
			MessageBox("Ӣ������ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
			pDoc->m_eng = false;
			pDoc->BEngMan = false;
			return;
		}
	}
	else if(pDoc->m_soft == true || pDoc->BSoftMan == true)
	{
		infile.open(pDoc->softwarec,ios::in);
		if(!infile)
		{
			MessageBox("רҵ����ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
			pDoc->m_soft = false;
			pDoc->BSoftMan = false;
			return;
		}
	}
	while(!infile.eof())
	{
		infile.get(ch);
		if(ch == '#')
			count++;
	}
	
	if((count == 0 && pDoc->m_soft == true) || (count == 0 && pDoc->BSoftMan == true))
	{
		MessageBox("רҵ����ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
		pDoc->m_soft = false;
		pDoc->BSoftMan = false;
		return;
	}
	else if((count == 0 && pDoc->m_eng == true) || (count == 0 && pDoc->BEngMan == true))
	{
		MessageBox("Ӣ������ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
		pDoc->m_eng = false;
		pDoc->BEngMan = false;
		return;
	}
	infile.close();
	
	CFont font1, font2, font3, font4;
	VERIFY(font1.CreateFont(
		50,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                   // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"��԰"));                  // lpszFacename
	VERIFY(font3.CreateFont(
		50,0,0,0,FW_SEMIBOLD,FALSE,FALSE,0, ANSI_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,"Tahoma"));
	VERIFY(font4.CreateFont(
		20,0,0,0,FW_SEMIBOLD,FALSE,FALSE,0, ANSI_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,"Tahoma"));
	
	//�������ɵ�����д��ʾ��Ϣ
	CFont* def_font = dc.SelectObject(&font1);
	dc.SetTextColor(RGB(0, 0, 255));
	if(pDoc->m_eng == true || pDoc->BEngMan == true)
	{
		dc.TextOut(260,18,"English Translation");
		dc.MoveTo(0, 85);
		dc.LineTo(1000, 85);
	}
	else if(pDoc->m_soft == true || pDoc->BSoftMan == true)
	{
		dc.TextOut(320,18,"רҵ����");
		dc.MoveTo(0, 85);
		dc.LineTo(1000, 85);
	}
	font1.DeleteObject();//ɾ���½�����1

	
	if(pDoc->TotalTest == true)
	{
		def_font = dc.SelectObject(&font3);
		dc.TextOut(370,18,"�ܲ���");
		dc.MoveTo(0, 75);
		dc.LineTo(1000, 75);
		def_font = dc.SelectObject(&font4);
		dc.TextOut(0,10,"Ӣ�﷭��");
		dc.TextOut(0,30,"רҵ4ѡ2");
	}
	
	
	if(pDoc->m_eng == true)
	{
		RandomSerial(pDoc->size);
	}
	else if(pDoc->m_soft == true)
	{
		RandomSerial(pDoc->size2);
	}
	
	
	int k = 0;
	int present_num = 2;
    if(pDoc->m_eng == true || pDoc->TotalTest == true)
	{
		present_num = pDoc->size;
	}
	else if(pDoc->m_soft == true || pDoc->TotalTest == true)
	{
		present_num = pDoc->size2;
	}
	if(pDoc->m_soft == true || pDoc->m_eng == true)
	{
		for(int size = 0; size < present_num; size++)
		{
			int count2 = 0;
			if(pDoc->m_eng == true)
			{
				infile.open(pDoc->englishc,ios::in);
				if(!infile)
				{
					MessageBox("Ӣ������ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
					pDoc->m_eng = false;
					return;
				}
			}
			if(pDoc->m_soft == true)
			{
				infile.open(pDoc->softwarec,ios::in);
				if(!infile)
				{
					MessageBox("רҵ����ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
					pDoc->m_soft = false;
					return;
				}
			}
			while(!infile.eof())
			{
				infile.get(ch);
				if(ch == '#')
					count2++;
				if(count2 == pDoc->serial[k])
				{
					ShowText(pDoc->serial[k]);
					k++;
				}
			}
			infile.close();
		}
	}
	else if(pDoc->BSoftMan == true)
	{
		infile.open(pDoc->softwarec,ios::in);
		if(!infile)
		{
			MessageBox("רҵ����ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
			pDoc->BSoftMan = false;
			return;
		}
		int countS = 0;
		int a[2] = {pDoc->SoftMan, pDoc->SoftMan2};
		int k = 0;
		while(!infile.eof())
		{
			infile.get(ch);
			if(ch == '#')
				countS++;
			if(countS == a[k])
			{
				ShowText(a[k]);
				++k;
				if (k == 2) 
				{
					break;
				}
			}
		}
		infile.close();
	}
	else if(pDoc->BEngMan == true)
	{
		infile.open(pDoc->englishc,ios::in);
		if(!infile)
		{
			MessageBox("Ӣ������ļ�������,����������!","��ʾ����",MB_ICONINFORMATION);
			pDoc->BEngMan = false;
			return;
		}
		int countS = 0;
		while(!infile.eof())
		{
			infile.get(ch);
			if(ch == '#')
				countS++;
			if(countS == pDoc->EngMan)
			{
				ShowText(pDoc->EngMan);
				break;
			}
		}
		infile.close();
	}
	pDoc->hang = 100;
	if(pDoc->TotalTest == true)
	{
		ChangeFile2();
		
		Random(pDoc->size, pDoc->size2);
		fstream fe, fs;
		char ch;
		fe.open(pDoc->englishlong,ios::in);
		fs.open(pDoc->softwarelong,ios::in);
		int counte = 0;
		int ke = 0;
		while(!fe.eof())
		{
			fe.get(ch);
			if(ch == '#')
				counte++;
			if(counte == pDoc->serE[ke])
			{
				ShowTotalText(pDoc->serE[ke], 1);//������
				ke++;
			}
		}
		int counts = 0;
		int ks =0;
		while(!fs.eof())
		{
			fs.get(ch);
			if(ch == '#')
				counts++;
			if(counts == pDoc->serS[ks])
			{
				ShowTotalText(pDoc->serS[ks], 0);//������
				ks++;
			}
		}
		fs.close();
		pDoc->hang1 = 90;
	}
	//CFont font2;
	VERIFY(font2.CreateFont(
		80,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"��԰"));                 // lpszFacenam

	//�������ɵ�����д��ʾ��Ϣ

	dc.SetTextColor(RGB(163, 29, 255));
	if(!pDoc->m_eng && !pDoc->m_soft && !pDoc->BSoftMan && !pDoc->BEngMan && !pDoc->TotalTest)
	{
		int year;  // Ҫ�Á�����ڵ� //
		time_t T;            // Ҫ�Á��ϵ�y�r�g�� //
		struct tm *TimeP;   // Ҫ�Á�ָ�� localtime() ���ص�λַ�� //
		T = time(NULL);      // ��ϵ�y�r�g�浽 T //
		TimeP = localtime( &T );  // TimeP ָ�� localtime ��õ��Y������λַ //
		year = ( TimeP->tm_year ) + 1900;
	
		CString title;
		title.Format("%d��˶ʿ�о�������", year);

		dc.SetBkMode(TRANSPARENT);
		AddBk();
		dc.SelectObject(&font2);
		dc.TextOut(80,250,title);
		dc.TextOut(220,350,"�������ϵͳ");
		font2.DeleteObject();//ɾ���½�����1
	}
}

void CExamView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CExamView diagnostics

#ifdef _DEBUG
void CExamView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CExamView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CExamDoc* CExamView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExamDoc)));
	return (CExamDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExamView message handlers

void CExamView::ShowText(int i)
{
	CExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CClientDC dc(this);
	CFont font1, font2, font3;
    VERIFY(font1.CreateFont(
		pDoc->softFont,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"�����п�"));                 // lpszFacename
	VERIFY(font2.CreateFont(
		pDoc->engFont,0,0,0,FW_SEMIBOLD,FALSE,FALSE,0, ANSI_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,"Tahoma"));
	VERIFY(font3.CreateFont(
		20,0,0,0,FW_SEMIBOLD,FALSE,FALSE,0, ANSI_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,"Tahoma"));
	
	dc.SetTextColor(RGB(0, 0, 255));
	CFont* def_font;
	//�������ɵ�����д��ʾ��Ϣ
	if(pDoc->m_eng == true || pDoc->BEngMan == true)
	{
		def_font = dc.SelectObject(&font2);
	}
	else if(pDoc->m_soft == true || pDoc->BSoftMan == true)
	{
		def_font = dc.SelectObject(&font1);
	}



	char ch;
	char buf[100];
	int count = 0;

	fstream infile;
	if(pDoc->m_soft == true || pDoc->BSoftMan == true)
	{
		infile.open(pDoc->softwarec,ios::in);
	}
	else if(pDoc->m_eng == true || pDoc->BEngMan == true)
	{
		infile.open(pDoc->englishc,ios::in);
	}
	
	while(!infile.eof())
	{
		infile.get(ch);
		if(ch == '#')
			count++;
		if(count == i)
			break;
	}
	while(true)
	{
		infile.getline(buf, sizeof(buf));
		if(pDoc->m_eng == true || pDoc->BEngMan == true)
		{
			dc.TextOut(pDoc->startEng, pDoc->hang, buf);
		}
		else if(pDoc->m_soft == true || pDoc->BSoftMan == true)
		{
			dc.TextOut(pDoc->startSoft, pDoc->hang, buf);
		}
		if (pDoc->m_eng == true || pDoc->BEngMan == true)
		{
			pDoc->hang += pDoc->engH;//Ӣ����м���
		}
		else if(pDoc->m_soft == true || pDoc->BSoftMan == true)
		{
			pDoc->hang += pDoc->softH;//רҵ�ε��м���
		}
		
		infile.get(ch);
		if(ch == '#')
		{
			dc.MoveTo(0, pDoc->hang+15);
			dc.LineTo(1000, pDoc->hang+15);
			pDoc->hang += 30;
			break;
		}
	}
	infile.close();
}

void CExamView::RandomSerial(int rsize)
{//����ѡ��������
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	int cc[8000], temp;
	int arr[8000];
	srand((unsigned)time( NULL ));
	//srand((unsigned)time( srand((unsigned)time( NULL )) ))
	for(int i = 0; i < 8000; i++)
	{
		arr[i] = i;//��ʼ����Ŀ������ ����8000
	}
    //��������ȵ������
	for(i = 0; i < rsize; i++)
	{
		int k;
		if(pDoc->m_eng == true)//��Ӣ��������ѡ��
		{
			k = (int)(double)rand()%(pDoc->eng_num-2)+1;
		}
		else if(pDoc->m_soft == true)//��רҵ����ѡ��
		{
			k = (int)(double)rand()%(pDoc->soft_num-2)+1;
		}
		
		while(true)
		{
			if(arr[k] == INT_MAX)
			{
				k++;
			}
			else
			{
				cc[i] = arr[k];//���������
				arr[k] = INT_MAX;
				break;
			}
		}
	}
	//���������С��������
	for(int t = 0; t < rsize; t++)
	{
		for(int k = t+1; k < rsize; k++)
		{
			if(cc[t] > cc[k])
			{
				temp = cc[t];
				cc[t] = cc[k];
				cc[k] = temp;
			}
		}
	}
	//���ź�������������serial����
	for(t = 0; t < rsize; t++)
	{
		pDoc->serial[t] = cc[t];
	}
	GetDocument()->UpdateAllViews(this);
}

void CExamView::ChangeFile()
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

	outeng.open(pDoc->englishc, ios::out);
	outsoft.open(pDoc->softwarec, ios::out);
	
	char *pe = streng;
	int count = 0;//??
	while (*pe != '\0')
	{
		//�����Ų���ѵ��ʽض�?
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
			if (count >= pDoc->widthEng)//��ŷ�Χ 
			{
				outeng.put('\n');
				outeng.put(' ');
				outeng.put(' ');
				outeng.put(' ');
				count = 0;//reset count
			}
		}
		
		if (count >= pDoc->widthEng)//��ŷ�Χ 
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
		//�����Ų���ѵ��ʽض�?
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
			if (count2 >= pDoc->widthSoft)//��ŷ�Χ 
			{
				outsoft.put('\n');
				outsoft.put(' ');
				outsoft.put(' ');
				outsoft.put(' ');
				count2 = 0;//reset count
			}
		}
		
		if (count2 >= pDoc->widthSoft)//��ŷ�Χ 
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

void CExamView::OnFileImport() 
{
	// TODO: Add your command handler code here
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	CImportDlg dlg;
	
	ChangeFile();

	pDoc->m_eng =false;
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
			MessageBox("רҵ����ⲻ��Ϊ��,����������!","��ʾ����",MB_ICONINFORMATION);
			return;
		}
		else if(dlg.m_Fenglish.IsEmpty())
		{
			MessageBox("Ӣ������ⲻ��Ϊ��,����������!","��ʾ����",MB_ICONINFORMATION);
			return;
		}
		else
		{
			pDoc->english = dlg.m_Fenglish;
			pDoc->software = dlg.m_Fsoftware;
			MessageBox("��⵼��ɹ�!","��ʾ����",MB_ICONINFORMATION);
		}
	}
	GetDocument()->UpdateAllViews(this);
}


void CExamView::AddBk()
{
	CDC dc1;
    CClientDC dc(this);
	CBitmap bit;
	CBitmap *b;
	dc1.CreateCompatibleDC(&dc);
    bit.LoadBitmap(IDB_BITMAP3);
	b=dc1.SelectObject(&bit);
	dc.BitBlt(0,0,1500,1500,&dc1,0,0,SRCCOPY);
	dc1.SelectObject(b);
}

void CExamView::OnShow() 
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
		pDoc->size = con.m_config;//Ӣ��
		pDoc->size2 = con.m_config2;//רҵ
		pDoc->startEng = con.m_staEng;
		pDoc->startSoft = con.m_staSoft;
		pDoc->widthEng = con.m_widEng;
		pDoc->widthSoft = con.m_widSoft;
		pDoc->engFont = con.m_engFont;
		pDoc->softFont = con.m_softFont;
		pDoc->engH = con.m_engH;
		pDoc->softH = con.m_softH;

		MessageBox("���óɹ�!����޸�����Ŀ��������ȣ������µ����ļ�!","��ʾ����",MB_ICONINFORMATION);
	}
	

	pDoc->hang = 100;
	
	for(int i = 0; i< 300; i++)
	{
		pDoc->c[i] = INT_MAX;
		pDoc->serial[i] = INT_MAX;
	}
	GetDocument()->UpdateAllViews(this);
}

void CExamView::Random(int e, int s)
{
	CExamDoc* pDoc =(CExamDoc*) GetDocument();
	int ce[8000], cs[8000], temp;
	int arre[8000], arrs[8000];
	int ke, ks;
	srand((unsigned)time( NULL ));
	for(int i = 0; i < 8000; i++)
	{
		arre[i] = i;//��ʼ����Ŀ������ ����8000
		arrs[i] = i;
	}
    //��������ȵ������
	/*for(int f = 0; f < 3; f++)
	{
		ke = (int)((double)rand()*(pDoc->eng_num-2)/(double)RAND_MAX)+1;
		ks = (int)((double)rand()*(pDoc->soft_num-2)/(double)RAND_MAX)+1;
	}*/
	if(pDoc->TotalTest == true)
	{
		for(i = 0; i < e; i++)
		{
			ke = (int)(double)rand()%(pDoc->eng_num-2)+1;
			while(true)
			{
				if(arre[ke] == INT_MAX)
				{
					ke++;
				}
				else
				{
					ce[i] = arre[ke];//���������
					arre[ke] = INT_MAX;
					break;
				}
			}
		}
		for(i = 0; i < s; i++)
		{
			ks = (int)(double)rand()%(pDoc->soft_num-2)+1;
			while(true)
			{
				if(arrs[ks] == INT_MAX)
				{
					ks++;
				}
				else
				{
					cs[i] = arrs[ks];//���������
					arrs[ks] = INT_MAX;
					break;
				}
			}
		}
	}
	//���������С��������
	for(int t = 0; t < e; t++)
	{
		for(int k = t+1; k < e; k++)
		{
			if(ce[t] > ce[k])
			{
				temp = ce[t];
				ce[t] = ce[k];
				ce[k] = temp;
			}
		}
	}
	for(t = 0; t < s; t++)
	{
		for(int k = t+1; k < s; k++)
		{
			if(cs[t] > cs[k])
			{
				temp = cs[t];
				cs[t] = cs[k];
				cs[k] = temp;
			}
		}
	}
	//���ź�������������serial����
	for(t = 0; t < e; t++)
	{
		pDoc->serE[t] = ce[t];
	}
	for(t = 0; t < s; t++)
	{
		pDoc->serS[t] = cs[t];
	}
	GetDocument()->UpdateAllViews(this);
}

void CExamView::ShowTotalText(int e,bool s)
{//true is eng false is soft
	CExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CClientDC dc(this);
	CFont font1, font2;
    VERIFY(font1.CreateFont(
		pDoc->softFont,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"�����п�"));                 // lpszFacename
	VERIFY(font2.CreateFont(
		25,0,0,0,FW_SEMIBOLD,FALSE,FALSE,0, ANSI_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,"Tahoma"));
	
	dc.SetTextColor(RGB(0, 0, 255));
	CFont* def_font;
	//�������ɵ�����д��ʾ��Ϣ
	
	def_font = dc.SelectObject(&font2);
	
	char ch;
	char buf[100];
	int count = 0;

	fstream f;
	if(s == false)
	{
		f.open(pDoc->softwarelong,ios::in);
	}
	else
	{
		f.open(pDoc->englishlong,ios::in);
	}
	
	while(!f.eof())
	{
		f.get(ch);
		if(ch == '#')
			count++;
		if(count == e)
			break;
	}
	while(true)
	{
		f.getline(buf, sizeof(buf));
		if(s == true)
		{
			//dc.TextOut(pDoc->startEng, pDoc->hang1, buf);
			//pDoc->hang1 += pDoc->engH;
			dc.TextOut(40, pDoc->hang1, buf);
			pDoc->hang1 += 30;
		}
		else
		{
			//dc.TextOut(pDoc->startSoft, pDoc->hang1, buf);
			//pDoc->hang1 += pDoc->softH;
			dc.TextOut(40, pDoc->hang1, buf);
			pDoc->hang1 += 30;
		}
		
		f.get(ch);
		if(ch == '#')
		{
			dc.MoveTo(0, pDoc->hang1+10);
			dc.LineTo(1000, pDoc->hang1+10);
			pDoc->hang1 += 20;
			break;
		}
	}
	f.close();
}

void CExamView::count()
{
	CExamDoc* pDoc = GetDocument();
	fstream fe,fs;
	char ch;
	fe.open(pDoc->englishc,ios::in);
	fs.open(pDoc->softwarec,ios::in);
	int counte = 0;
	int counts = 0;
	while(!fe.eof())
	{
		fe.get(ch);
		if(ch == '#')
			counte++;
	}
	pDoc->eng_num = counte;
	while(!fs.eof())
	{
		fs.get(ch);
		if(ch == '#')
			counts++;
	}
	pDoc->soft_num = counts;
	GetDocument()->UpdateAllViews(this);
}

void CExamView::ChangeFile2()
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

	outeng.open(pDoc->englishlong, ios::out);
	outsoft.open(pDoc->softwarelong, ios::out);
	
	char *pe = streng;
	int count = 0;//??
	while (*pe != '\0')
	{
		//�����Ų���ѵ��ʽض�?
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
			if (count >= 65)//��ŷ�Χ 
			{
				outeng.put('\n');
				outeng.put(' ');
				outeng.put(' ');
				outeng.put(' ');
				//cout << endl;
				count = 0;//reset count
			}
		}
		
		if (count >= 65)//��ŷ�Χ 
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
		//�����Ų���ѵ��ʽض�?
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
			if (count2 >= 70)//��ŷ�Χ 
			{
				outsoft.put('\n');
				outsoft.put(' ');
				outsoft.put(' ');
				outsoft.put(' ');
				count2 = 0;//reset count
			}
		}
		
		if (count2 >= 70)//��ŷ�Χ 
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
