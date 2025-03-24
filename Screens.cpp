#include "Screens.h"


void Screens:: bankName() {}
void Screens::welcome(){}
void Screens::loginOptions(){
	cout <<
	    " 1 -> Client \n"
		" 2 -> Employee \n"
		" 3 -> Admin \n" 
		" 4 -> Exit \n"
		" Login As : ";
}
int  Screens::loginAs(){
	loginOptions();
	
	int option = clientManager::checkInt();
	switch (option)
	{
	case 1:
		system("cls");
		loginScreen(option);
		break;
	case 2:
		system("cls");
		loginScreen(option);
		break;
	case 3:
		system("cls");
		loginScreen(option);
		break;
	case 4:
		break;
	default:
		cout << "Please Choose A Nunber From 1 -> 4 : \n";
		loginAs();
	}
	return option;
	
}
void Screens::invalid(int c)
{
	cout << c << " Is Not A Valid Number  \n";
	loginOptions();
}
void Screens::logout(){
	loginAs();
	
}
void Screens::loginScreen(int c)
{	
	string password;
	while(true)
	{
		cout << " Enter Your Id : ";
		int id=clientManager::checkInt();
		cout << " Enter Your Password : ";
		cin >> password;
		if (c == 1)
		{
			clientManager::login(id, password);
			break;
		}
		else if (c == 2)
		{
			employeeManager::login(id, password);
			break;
		}
		else if (c == 3)
		{
			adminManager::login(id, password);
			break;
		}
		else
			loginAs();
	}
}
void Screens::runApp()
{	fileHelper::getAllData() ;
	loginAs();
	
}