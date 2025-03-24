#include "employeeManager.h"

void employeeManager::printEmployeMenu(Employee* e)
{
	do
	{
		cout << " Please Enter Your Choice\n"
			" 1 -> Add New Client\n"
			" 2 -> List All Clients\n"
			" 3 -> Search For A Client\n"
			" 4 -> Edit Client Info\n"
			" 5 -> Account Details\n"
			" 6 -> Update Password\n"
			" 7 -> Logout\n";
	} while (employeeOptions(e));
}

void employeeManager::newClient(Employee* employee)
{
	string name, password;
	double balance;
	Client c;

	cout << " Add New Client\n";

	cout << " Enter Name : ";
	name = verifyName();
	c.setName(name);

	cout << " Enter Password : ";
	password = verifyPassword();
	c.setPassword(password);
		
	cout << " Enter Balance : ";
	balance = verifyBalance();
	employee->addClients(c);
	cout << " Client Added Successfully \n";
	fileHelper::updateClients(allclients);
}
void employeeManager::listAllClients(Employee* e)
{
	e->listAllClients();
}
void employeeManager::searchForClient(Employee* e)
{
	Client* c;
	int id;
	cout << " Enter Client ID : ";
	cin >> id;
	c = e->searchClients(id);
	if (c != nullptr) c->Display();
	else cout << " Client Not Found \n";
}
void employeeManager::editClientInfo(Employee* e)
{
	int id;
	string name, password;
	double balance;
	
	cout << " Enter The ID Of Client You want to edit : ";
	id=clientManager::checkInt();
	
	Client *c;
	c = e->searchClients(id);
	if (c != nullptr)
	{
		c->Display();
		cout << " Enter New Name : ";
		name = verifyName();
		cout << " Enter New Password : ";
		password =verifyPassword();
		cout << " Enter New Balance : ";
		balance = verifyBalance();
		e->editClient(id,name, password,balance);
		fileHelper::updateClients(allclients);
		cout << " Client Updated Successfully \n";
	}
	else
	{
		cout << " User Not Found\n";
	}
}
Employee* employeeManager::login(int id, string password)
{	
	Admin a;
	Employee *e = a.searchEmployee(id);
	if (e && e->getPassword() == password)
	{	
		system("cls");
		cout << " Welcome " << e->getName() << endl;
		printEmployeMenu(e);
		return  e;
	}
	cout << "Id And Password Don't Match\n";
	system("cls");
	Screens::loginScreen(2);
	return nullptr;
}
bool employeeManager::employeeOptions(Employee* e) 
{
	string name;
	int option = clientManager::checkInt();
	switch (option)
	{
		case 1:
			system("cls");
			newClient(e);
			clientManager::waitForKeyPress();
			break;

		case 2:
			system("cls");
			listAllClients(e);
			clientManager::waitForKeyPress();
			break;
		case 3:
			system("cls");
			searchForClient(e);
			clientManager::waitForKeyPress();
			break;
		case 4:
			system("cls");
			editClientInfo(e);
			clientManager::waitForKeyPress();
			break;
		case 5:
			system("cls");
			e->Display();
			clientManager::waitForKeyPress();
			break;
		case 6:
			system("cls");
			clientManager::updatePassword(e);
			fileHelper::updateEmployees(allEmployees);
			clientManager::waitForKeyPress();
			break;
		case 7:
			system("cls");
			cout <<e->getName()<< " You Now Logged Out\n";
			system("cls");
			Screens::logout();
			return false;;
		default:
			system("cls");
			cout << " please enter correct choice\n";
			break;
	}
		return true;
}
string employeeManager:: verifyName()
{
	string name;
	while (true)
	{
		cin >> name;
		if(Validate::Name(name))
			break;
		else
		{
			cout << " Name is not valid ,please enter alphabets only from 5 to 20 : ";
		}
	}
	return name;
}
string employeeManager::verifyPassword()
{
	string password;
	while (true)
	{
		cin >> password;
		if (Validate::Password(password))
			break;
		else
		{
			cout << " Password Is not valid ,Please Enter from 8 to 20 Charcters : ";
		}
	}
	return password;
}
double employeeManager::verifyBalance()
{
	Client c;
	double balance;
	while (true)
	{
		cin >> balance;
		try
		{
			c.setBalance(balance);
			cout << " Balance is : " << c.getBalance() << endl;
			break;
		}
		catch (exception& e)
		{
			cout << e.what();
		}
	}
	return balance;
}