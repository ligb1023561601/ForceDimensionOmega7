
// robot_arm_cppDlg.h : 头文件
//

#pragma once
#include "dhdc.h"
#include <windows.h>
#include <string.h>
// Crobot_arm_cppDlg 对话框
class Crobot_arm_cppDlg : public CDialogEx
{
// 构造
public:
	Crobot_arm_cppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ROBOT_ARM_CPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
