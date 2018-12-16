; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCGWORK1112View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CGWORK1112.h"
LastPage=0

ClassCount=7
Class1=CCGWORK1112App
Class2=CCGWORK1112Doc
Class3=CCGWORK1112View
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_DIALOG2
Class5=CAboutDlg
Resource2=IDD_DIALOG1
Resource3=IDD_ABOUTBOX
Class6=InputColorDlg2
Resource4=IDR_MAINFRAME
Class7=InputColorDlgB
Resource5=IDD_DIALOG3

[CLS:CCGWORK1112App]
Type=0
HeaderFile=CGWORK1112.h
ImplementationFile=CGWORK1112.cpp
Filter=N

[CLS:CCGWORK1112Doc]
Type=0
HeaderFile=CGWORK1112Doc.h
ImplementationFile=CGWORK1112Doc.cpp
Filter=N
LastObject=CCGWORK1112Doc

[CLS:CCGWORK1112View]
Type=0
HeaderFile=CGWORK1112View.h
ImplementationFile=CGWORK1112View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_SER_COLOR3


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=CGWORK1112.cpp
ImplementationFile=CGWORK1112.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_DRAW_RECT
Command18=ID_DRAW_CIRCULAR
Command19=ID_DRAW_LINE
Command20=ID_SET_COLOR1
Command21=ID_DRAW_POLYGON
Command22=ID_SET_COLOR2
Command23=ID_DRAW_CUBE
Command24=ID_MOVE_X
Command25=ID_MOVE_Y
Command26=ID_MOVE_Z
Command27=ID_SPIN_X
Command28=ID_SPIN_Y
Command29=ID_SPIN_Z
Command30=ID_MENUITEM32783
Command31=ID_DRAW_BEZIER
Command32=ID_SER_COLOR3
CommandCount=32

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RECT_COLOR,static,1342308352
Control4=IDC_STATIC_R1,static,1342308352
Control5=IDC_STATIC_G1,static,1342308352
Control6=IDC_STATIC_B1,static,1342308352
Control7=IDC_RECT_R,edit,1350631552
Control8=IDC_RECT_G,edit,1350631552
Control9=IDC_RECT_B,edit,1350631552
Control10=IDC_CIRCULAR_COLOR,static,1342308352
Control11=IDC_STATIC_R2,static,1342308352
Control12=IDC_CIRCULAR_R,edit,1350631552
Control13=IDC_STATIC_G2,static,1342308352
Control14=IDC_CIRCULAR_G,edit,1350631552
Control15=IDC_STATIC_B2,static,1342308352
Control16=IDC_CIRCULAR_B,edit,1350631552
Control17=IDC_CHECK1,button,1342242819

[DLG:IDD_DIALOG2]
Type=1
Class=InputColorDlg2
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BORDER_R,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BORDER_G,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BORDER_B,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_FILL_R,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_FILL_G,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_FILL_B,edit,1350631552

[CLS:InputColorDlg2]
Type=0
HeaderFile=InputColorDlg2.h
ImplementationFile=InputColorDlg2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG3]
Type=1
Class=InputColorDlgB
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BORDER_R,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_BORDER_G,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BORDER_B,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_CURVE_R,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CURVE_G,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_CURVE_B,edit,1350631552

[CLS:InputColorDlgB]
Type=0
HeaderFile=InputColorDlgB.h
ImplementationFile=InputColorDlgB.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

