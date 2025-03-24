#pragma once
#include"FileHelper.h"
#include"clientManager.h"
#include"employeeManager.h"
#include"adminManager.h"
class Screens
{
public:
	static void bankName();
	static void welcome();
	static void loginOptions();
	static int loginAs();
	static void invalid(int c);
	static void logout();
	static void loginScreen(int c);
	static void runApp();
};

