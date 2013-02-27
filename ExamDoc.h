// ExamDoc.h : interface of the CExamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXAMDOC_H__992BEA61_E02D_488E_914E_C77DCA9151E5__INCLUDED_)
#define AFX_EXAMDOC_H__992BEA61_E02D_488E_914E_C77DCA9151E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExamDoc : public CDocument
{
protected: // create from serialization only
	CExamDoc();
	DECLARE_DYNCREATE(CExamDoc)

// Attributes
public:
	bool m_eng;//
	bool m_soft;//
	int hang;//间距
	int size;//设置的英语出题数量
	int size2;//设置的专业出题数量

	int c[300];//测试随机数
	int serial[300];//有序随机数
	int eng_num;//英语题目总数
	int soft_num;//专业题目总数
	CString english;//英语试题的文件名
	CString englishc;//changed eng
	CString software;//专业课试题的文件名
	CString softwarec;//changed soft
	CString softwarelong;
	CString englishlong;
	

	int startEng;//在View中输出eng的起点
	int startSoft;//在View中输出eng的起点
	int widthEng;//english每行的宽度
	int widthSoft;//software 每行的宽度

	int engFont;//英语字体大小
	int softFont;//专业字体大小

	int x;//logo x
	int y;//logo y

	int engH;//英语的行间间隔
	int softH;//专业的行间间隔

	bool BSoftMan;//按钮
	int SoftMan;//专业题号1
	int SoftMan2;//专业题号2

	bool BEngMan;//按钮
	int EngMan;//英语题号
	
	int serE[300];//英语顺序的随机数
	int serS[300];//专业顺序的随机数
	bool TotalTest;

	int hang1;

	int stu;
	int tea;

	int fping;
	int tping;




// Otions
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMDOC_H__992BEA61_E02D_488E_914E_C77DCA9151E5__INCLUDED_)
