; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPanel
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Exam.h"
LastPage=0

ClassCount=13
Class1=CExamApp
Class2=CExamDoc
Class3=CExamView
Class4=CMainFrame

ResourceCount=20
Resource1=IDD_DIALOG_IMPORT
Resource2=IDD_DIALOG_ENGMAN
Class5=CAboutDlg
Class6=CPanel
Resource3=IDD_DIALOG_STATUS
Class7=CConfig
Resource4=IDD_FORMVIEW_CONTROL
Class8=CTotalNum
Resource5=IDR_MAINFRAME
Class9=CImportDlg
Resource6=IDD_ABOUTBOX
Class10=CSoftmanDlg
Resource7=IDD_DIALOG_TOTAL
Class11=CEngmanDlg
Resource8=IDD_DIALOG_CONFIG
Class12=CStatusDlg
Resource9=IDD_DIALOG_SOFTMAN
Class13=CStyleDlg
Resource10=IDD_DIALOG_SHOWSTYLE
Resource11=IDD_DIALOG_SOFTMAN (Chinese (P.R.C.))
Resource12=IDD_DIALOG_STATUS (Chinese (P.R.C.))
Resource13=IDD_DIALOG_ENGMAN (Chinese (P.R.C.))
Resource14=IDD_DIALOG_CONFIG (Chinese (P.R.C.))
Resource15=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource16=IDD_DIALOG_IMPORT (Chinese (P.R.C.))
Resource17=IDD_FORMVIEW_CONTROL (Chinese (P.R.C.))
Resource18=IDD_DIALOG_TOTAL (Chinese (P.R.C.))
Resource19=IDR_MAINFRAME (Chinese (P.R.C.))
Resource20=IDD_DIALOG_SHOWSTYLE (Chinese (P.R.C.))

[CLS:CExamApp]
Type=0
HeaderFile=Exam.h
ImplementationFile=Exam.cpp
Filter=N

[CLS:CExamDoc]
Type=0
HeaderFile=ExamDoc.h
ImplementationFile=ExamDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CExamDoc

[CLS:CExamView]
Type=0
HeaderFile=ExamView.h
ImplementationFile=ExamView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CExamView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=IDM_SHOW




[CLS:CAboutDlg]
Type=0
HeaderFile=Exam.cpp
ImplementationFile=Exam.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_IMPORT
Command2=IDM_SHOW
Command3=ID_APP_EXIT
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_FORMVIEW_CONTROL]
Type=1
Class=CPanel
ControlCount=9
Control1=IDC_CONFIG,button,1476460544
Control2=IDC_ENGLISH,button,1476460544
Control3=IDC_SOFT,button,1476460544
Control4=IDC_RETEST,button,1476460544
Control5=IDC_EXIT,button,1342242816
Control6=IDC_BUTTON_SOFTMAN,button,1476460544
Control7=IDC_BUTTON_ENGMAN,button,1476460544
Control8=IDC_BUTTON_TOTALTEST,button,1476460544
Control9=IDC_BUTTON_STATUS,button,1342242816

[CLS:CPanel]
Type=0
HeaderFile=Panel.h
ImplementationFile=Panel.cpp
BaseClass=CFormView
Filter=D
LastObject=CPanel
VirtualFilter=VWC

[DLG:IDD_DIALOG_CONFIG]
Type=1
Class=CConfig
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_STARTENG,edit,1350631552
Control8=IDC_EDIT_WIDTHENG,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_WIDTHSOFT,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_STARTSOFT,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_FONTENG,edit,1350631552
Control16=IDC_EDIT_FONTSOFT,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_ENGH,edit,1350631552
Control20=IDC_EDIT_SOFTH,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,button,1342177287

[CLS:CConfig]
Type=0
HeaderFile=Config.h
ImplementationFile=Config.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfig
VirtualFilter=dWC

[DLG:IDD_DIALOG_TOTAL]
Type=1
Class=CTotalNum
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ENG,edit,1350631552
Control4=IDC_EDIT_SOFT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CTotalNum]
Type=0
HeaderFile=TotalNum.h
ImplementationFile=TotalNum.cpp
BaseClass=CDialog
Filter=D
LastObject=CTotalNum
VirtualFilter=dWC

[DLG:IDD_DIALOG_IMPORT]
Type=1
Class=CImportDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ENG,edit,1350631552
Control4=IDC_EDIT_SOFT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287

[CLS:CImportDlg]
Type=0
HeaderFile=ImportDlg.h
ImplementationFile=ImportDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CImportDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_SOFTMAN]
Type=1
Class=CSoftmanDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287

[CLS:CSoftmanDlg]
Type=0
HeaderFile=SoftmanDlg.h
ImplementationFile=SoftmanDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSoftmanDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_ENGMAN]
Type=1
Class=CEngmanDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ENG,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CEngmanDlg]
Type=0
HeaderFile=EngmanDlg.h
ImplementationFile=EngmanDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEngmanDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_STATUS]
Type=1
Class=CStatusDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_STU,button,1342177289
Control4=IDC_RADIO_TEA,button,1342177289
Control5=IDC_STATIC,button,1342177287

[CLS:CStatusDlg]
Type=0
HeaderFile=StatusDlg.h
ImplementationFile=StatusDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CStatusDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_SHOWSTYLE]
Type=1
Class=CStyleDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_STATIC,button,1342177287

[CLS:CStyleDlg]
Type=0
HeaderFile=StyleDlg.h
ImplementationFile=StyleDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO2
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG_CONFIG (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_STARTENG,edit,1350631552
Control8=IDC_EDIT_WIDTHENG,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_WIDTHSOFT,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_STARTSOFT,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_FONTENG,edit,1350631552
Control16=IDC_EDIT_FONTSOFT,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_ENGH,edit,1350631552
Control20=IDC_EDIT_SOFTH,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,button,1342177287

[MNU:IDR_MAINFRAME (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_FILE_IMPORT
Command2=IDM_SHOW
Command3=ID_APP_EXIT
Command4=ID_APP_ABOUT
CommandCount=4

[DLG:IDD_DIALOG_ENGMAN (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ENG,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_IMPORT (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ENG,edit,1350631552
Control4=IDC_EDIT_SOFT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG_SHOWSTYLE (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG_SOFTMAN (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG_STATUS (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_STU,button,1342177289
Control4=IDC_RADIO_TEA,button,1342177289
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG_TOTAL (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ENG,edit,1350631552
Control4=IDC_EDIT_SOFT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_FORMVIEW_CONTROL (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=9
Control1=IDC_CONFIG,button,1476460544
Control2=IDC_ENGLISH,button,1476460544
Control3=IDC_SOFT,button,1476460544
Control4=IDC_RETEST,button,1476460544
Control5=IDC_EXIT,button,1342242816
Control6=IDC_BUTTON_SOFTMAN,button,1476460544
Control7=IDC_BUTTON_ENGMAN,button,1476460544
Control8=IDC_BUTTON_TOTALTEST,button,1476460544
Control9=IDC_BUTTON_STATUS,button,1342242816

[ACL:IDR_MAINFRAME (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

