
// robot_arm_cpp.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Crobot_arm_cppApp: 
// 有关此类的实现，请参阅 robot_arm_cpp.cpp
//

class Crobot_arm_cppApp : public CWinApp
{
public:
	Crobot_arm_cppApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Crobot_arm_cppApp theApp;