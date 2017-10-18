
// robot_arm_cppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "robot_arm_cpp.h"
#include "robot_arm_cppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Crobot_arm_cppDlg 对话框



Crobot_arm_cppDlg::Crobot_arm_cppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Crobot_arm_cppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Crobot_arm_cppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Crobot_arm_cppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Crobot_arm_cppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Crobot_arm_cppDlg::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Crobot_arm_cppDlg 消息处理程序

BOOL Crobot_arm_cppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Crobot_arm_cppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Crobot_arm_cppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Crobot_arm_cppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Crobot_arm_cppDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	double freq = 0.0;
	double t1, t0 = dhdGetTime();

	// message
	int major, minor, release, revision;
	dhdGetSDKVersion(&major, &minor, &release, &revision);

	// 打开设备
	if (dhdOpen()<0)
	{
		AfxMessageBox(TEXT("未检测到设备"));
		dhdSleep(2.0);
	}

	// 识别设备名称
	CString device_name(dhdGetSystemName());

	//开启force模式
	dhdEnableForce(DHD_ON);

	SetTimer(0, 100, NULL);	
	
}


void Crobot_arm_cppDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码

	if (dhdClose() < 0)
	{
		CString close_error_msg;
		close_error_msg.Format(TEXT("error: (%s)\n"), dhdErrorGetLastStr());
		AfxMessageBox(close_error_msg);
		done = 1;
	}
	else
	{
		done = 1;
	}
	
}


void Crobot_arm_cppDlg::OnTimer(UINT_PTR nIDEvent)
{

	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString str;
	double px, py, pz;
	double angle_a, angle_b, angle_g;
	double fx, fy, fz;
	double gripper_angle;
	switch (nIDEvent)
	{
	case 0:
		//归零
		if (dhdSetForceAndTorqueAndGripperForce(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) < DHD_NO_ERROR)
		{
			CString force_error_msg;
			force_error_msg.Format(TEXT("error: cannot set force (%s)\n"), dhdErrorGetLastStr());
			AfxMessageBox(force_error_msg);
			done = 1;
		}

		// retrieve position
		//if (dhdGetPosition(&px, &py, &pz) < DHD_NO_ERROR)
		//{
		//	CString pos_error_msg;
		//	pos_error_msg.Format(TEXT("error: cannot read position (%s)\n"), dhdErrorGetLastStr());
		//	AfxMessageBox(pos_error_msg);
		//	done = 1;
		//}
		if (dhdGetPositionAndOrientationDeg(&px,&py,&pz,&angle_a,&angle_b,&angle_g) < DHD_NO_ERROR)
		{
			CString pos_error_msg;
			pos_error_msg.Format(TEXT("error:cannot read position (%s)\n"), dhdErrorGetLastStr());
			AfxMessageBox(pos_error_msg);
			done = 1;
		}

		// retrieve force
		if (dhdGetForce(&fx, &fy, &fz) < DHD_NO_ERROR)
		{
			CString force_error_msg;
			force_error_msg.Format(TEXT("error: cannot read force (%s)\n"), dhdErrorGetLastStr());
			AfxMessageBox(force_error_msg);
			done = 1;
		}

		if (dhdGetGripperAngleDeg(&gripper_angle) < DHD_NO_ERROR)
		{
			CString griper_force_error_msg;
			griper_force_error_msg.Format(TEXT("error: cannot read gripper force (%s)\n"), dhdErrorGetLastStr());
			AfxMessageBox(griper_force_error_msg);
			done = 1;
		}
		str.Format(TEXT("%lf"), px);
		SetDlgItemText(ID_X, str);
		str.Format(TEXT("%lf"), py);
		SetDlgItemText(ID_Y, str);
		str.Format(TEXT("%lf"), pz);
		SetDlgItemText(ID_Z, str);
		str.Format(TEXT("%lf"), angle_a);
		SetDlgItemText(ID_A_ANGLE, str);
		str.Format(TEXT("%lf"), angle_b);
		SetDlgItemText(ID_B_ANGLE, str);
		str.Format(TEXT("%lf"), angle_g);
		SetDlgItemText(ID_G_ANGLE, str);

		str.Format(TEXT("%lf"), fx);
		SetDlgItemText(ID_X_F, str);
		str.Format(TEXT("%lf"), fy);
		SetDlgItemText(ID_Y_F, str);
		str.Format(TEXT("%lf"), fz);
		SetDlgItemText(ID_Z_F, str);
		str.Format(TEXT("%lf"), gripper_angle);
		SetDlgItemText(ID_GRIP_ANGLE, str);
		
		// test for exit condition
		if (dhdGetButtonMask()) done = 1;
	

	//获取可用设备数
	//int device_cnt = dhdGetDeviceCount();
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
