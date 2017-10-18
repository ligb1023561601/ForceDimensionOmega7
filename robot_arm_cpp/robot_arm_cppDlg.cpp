
// robot_arm_cppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "robot_arm_cpp.h"
#include "robot_arm_cppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Crobot_arm_cppDlg �Ի���



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


// Crobot_arm_cppDlg ��Ϣ�������

BOOL Crobot_arm_cppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Crobot_arm_cppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Crobot_arm_cppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Crobot_arm_cppDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	double freq = 0.0;
	double t1, t0 = dhdGetTime();

	// message
	int major, minor, release, revision;
	dhdGetSDKVersion(&major, &minor, &release, &revision);

	// ���豸
	if (dhdOpen()<0)
	{
		AfxMessageBox(TEXT("δ��⵽�豸"));
		dhdSleep(2.0);
	}

	// ʶ���豸����
	CString device_name(dhdGetSystemName());

	//����forceģʽ
	dhdEnableForce(DHD_ON);

	SetTimer(0, 100, NULL);	
	
}


void Crobot_arm_cppDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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

	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	double px, py, pz;
	double angle_a, angle_b, angle_g;
	double fx, fy, fz;
	double gripper_angle;
	switch (nIDEvent)
	{
	case 0:
		//����
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
	

	//��ȡ�����豸��
	//int device_cnt = dhdGetDeviceCount();
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
