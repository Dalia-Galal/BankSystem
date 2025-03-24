#include "adminManager.h"
void adminManager::printAdminMenu(Admin* a){
	do
	{
		cout << " Please Enter Your Choice\n"
			" 1 -> Add New Client\n"
			" 2 -> List All Clients\n"
			" 3 -> Search For A Client\n"
			" 4 -> Edit Client Info\n"
			" 5 -> Add New Employee\n"
			" 6 -> List All Employees\n"
			" 7 -> Search For An Employee\n"
			" 8 -> Edit Employee Info\n"
			" 9 -> Account Details\n"
			" 10 -> Update Password\n"
			" 11 -> Logout\n";
	} while (adminOptions(a));
}
void adminManager::newClient(Admin* a)
{
	employeeManager::newClient(a);
}
void adminManager::listAllClients(Admin* a)
{
	a->listAllClients();
}
void adminManager::searchForClient(Admin* a)
{
	employeeManager::searchForClient(a);
}
void adminManager::editClientInfo(Admin* a)
{
	employeeManager::editClientInfo(a);
}
void adminManager::newEmployee(Admin* a)
{
	string name, password;
	double salary;
	Employee e;

	cout << " Add New Employee\n";

	cout << " Enter Name : ";
	name = employeeManager::verifyName();
	e.setName(name);

	cout << " Enter Password : ";
	password = employeeManager::verifyPassword();
	e.setPassword(password);

	cout << " Enter Salary : ";
	salary = verifySalary();
	e.setSalary(salary);

	a->addEmployee(e);
	fileHelper::updateEmployees(allEmployees);
}
void adminManager::listAllEmployees(Admin* a)
{
	a->listEmployee();
}
void adminManager::searchForEmployee(Admin* a){
	Employee* e ;
	int id;
	cout << " Enter Employee ID : ";
	cin >> id;
	e = a->searchEmployee(id);
	if (e != nullptr) e->Display();
	else cout << " Employee Not Found \n";
}
void adminManager::editEmployeeInfo(Admin* a)
{
	int id;
	string name, password;
	double salary;

	cout << " Enter The ID Of Employee You want to edit : ";
	id = clientManager::checkInt();
	Employee* e;
	e = a->searchEmployee(id);
	if (e != nullptr)
	{
		e->Display();

		cout << " Enter New Name : ";
		name = employeeManager::verifyName();
		e->setName(name);

		cout << " Enter New Password : ";
		password = employeeManager::verifyPassword();
		e->setPassword(password);

		cout << " Enter New Salary : ";
		salary =verifySalary();
		e->setSalary(salary);

		e->editClient(id, name, password, salary);
		fileHelper::updateEmployees(allEmployees);
	}
	else
	{
		cout << " User Not Found\n";
	}
}
Admin* adminManager::login(int id, string password)
{
	for (auto &admin : allAdmins)
	{
		if (admin.getId() == id&& admin.getPassword() == password)
		{
			system("cls");
			cout << " Welcome , " << admin.getName() << endl;
			printAdminMenu(&admin);
			return &admin;
		}
	}
	cout << " User Not Found\n";
	system("cls");
	Screens::loginScreen(3);
	return nullptr;
}
bool adminManager::adminOptions(Admin* a)
{
	int key;
	key = clientManager::checkInt();
	switch (key)
	{
	case 1:
		system("cls");
		newClient(a);
		clientManager::waitForKeyPress();
		break;
	case 2:
		system("cls");
		listAllClients(a);
		clientManager::waitForKeyPress();
		break;
	case 3:
		system("cls");
		searchForClient(a);
		clientManager::waitForKeyPress();
		break;
	case 4:
		system("cls");
		editClientInfo(a);
		clientManager::waitForKeyPress();
		break;
	case 5:
		system("cls");
		newEmployee(a);
		clientManager::waitForKeyPress();
		break;
	case 6:
		system("cls");
		listAllEmployees(a);
		clientManager::waitForKeyPress();
		break;
	case 7:
		searchForEmployee(a);
		clientManager::waitForKeyPress();
		break;
	case 8:
		editEmployeeInfo(a);
		clientManager::waitForKeyPress();
		break;
	case 9:
		system("cls");
		a->Display();
		clientManager::waitForKeyPress();
		break;
	case 10:
		system("cls");
		clientManager::updatePassword(a);
		fileHelper::updateAdmins(allAdmins);
		clientManager::waitForKeyPress();
		break;
	case 11:
		system("cls");
		cout << " " << a->getName() << " Now Logged Out\n";
		clientManager::waitForKeyPress();
		Screens::logout();
		system("cls");
		return false;;
	default:
		system("cls");
		cout << " Please Enter Correct Choice\n";
		break;
	}
	return true;
}
double adminManager::verifySalary()
{
	Employee e;
	double salary;
	while (true)
	{
		cin >> salary;
		try
		{
			e.setSalary(salary);
			break;
		}
		catch (exception& e)
		{
			cout << e.what();
		}
	}
	return salary;
}