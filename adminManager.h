#pragma once
#include "Employee.h"
#include"Admin.h"
#include"Client.h"
#include"FileHelper.h"
#include"clientManager.h"
#include"Screens.h"
class adminManager
{
public:
	static void printAdminMenu(Admin* admin);
	static void newClient(Admin* admin);
	static void listAllClients(Admin* admin);
	static void searchForClient(Admin* admin);
	static void editClientInfo(Admin* admin);
	static void newEmployee(Admin* admin);
	static void listAllEmployees(Admin* admin);
	static void searchForEmployee(Admin* admin);
	static void editEmployeeInfo(Admin* admin);
	static Admin* login(int id, string password);
	static bool adminOptions(Admin* admin);
	static double verifySalary();
};

