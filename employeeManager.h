#pragma once
#include "Employee.h"
#include"Admin.h"
#include"Client.h"
#include"clientManager.h"
#include"FileHelper.h"
#include"Screens.h"
class employeeManager
{
public:
	static void printEmployeMenu(Employee* employee);
	static void newClient(Employee* employee);
	static void listAllClients(Employee* employee);
	static void searchForClient(Employee* employee);
	static void editClientInfo(Employee* employee);
	static Employee* login(int id, string password);
	static bool employeeOptions(Employee* employee);
	static string verifyName();
	static string verifyPassword();
	static double verifyBalance();
};

