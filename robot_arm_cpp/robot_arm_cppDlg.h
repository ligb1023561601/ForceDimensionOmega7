
// robot_arm_cppDlg.h : ͷ�ļ�
//

#pragma once
#include "dhdc.h"
#include <windows.h>
#include <string.h>
// Crobot_arm_cppDlg �Ի���
class Crobot_arm_cppDlg : public CDialogEx
{
// ����
public:
	Crobot_arm_cppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ROBOT_ARM_CPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

public:
	int done = 0;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
