
// robot_arm_cpp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Crobot_arm_cppApp: 
// �йش����ʵ�֣������ robot_arm_cpp.cpp
//

class Crobot_arm_cppApp : public CWinApp
{
public:
	Crobot_arm_cppApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Crobot_arm_cppApp theApp;