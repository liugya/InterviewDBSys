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
	int hang;//���
	int size;//���õ�Ӣ���������
	int size2;//���õ�רҵ��������

	int c[300];//���������
	int serial[300];//���������
	int eng_num;//Ӣ����Ŀ����
	int soft_num;//רҵ��Ŀ����
	CString english;//Ӣ��������ļ���
	CString englishc;//changed eng
	CString software;//רҵ��������ļ���
	CString softwarec;//changed soft
	CString softwarelong;
	CString englishlong;
	

	int startEng;//��View�����eng�����
	int startSoft;//��View�����eng�����
	int widthEng;//englishÿ�еĿ��
	int widthSoft;//software ÿ�еĿ��

	int engFont;//Ӣ�������С
	int softFont;//רҵ�����С

	int x;//logo x
	int y;//logo y

	int engH;//Ӣ����м���
	int softH;//רҵ���м���

	bool BSoftMan;//��ť
	int SoftMan;//רҵ���1
	int SoftMan2;//רҵ���2

	bool BEngMan;//��ť
	int EngMan;//Ӣ�����
	
	int serE[300];//Ӣ��˳��������
	int serS[300];//רҵ˳��������
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
