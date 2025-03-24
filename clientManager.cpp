#include "clientManager.h"
#include <vector>
#include <conio.h>
void clientManager::printClientMenu(Client *c)
{
	do
	{
		cout << " 1 -> Check Balance\n"
			" 2 -> Deposit\n"
			" 3 -> Withdrow\n"
			" 4 -> Transfer Money\n"
			" 5 -> Account Details\n"
			" 6 -> Update Password\n"
			" 7 -> Logout\n";
	}
	while (clientOptions(c));
}
void clientManager::updatePassword (Person* p)
{
		string password;
		cout << " Enter Your New Password\n";
		
		while (true)
		{	
			cin >> password;
			p->setPassword(password);
			if (p->getPassword() == password)
			{
				cout << " Password Updated Successfully\n";
				break;
			}
			else
				cout << " Password Not Valid ,It Must Be from 8 To 20 charecters : \n";
		}
		
}

Client* clientManager::login(int id, string password)
{
	Employee e;
	Client* c = e.searchClients(id);
	if (c && c->getPassword() == password)
	{
		system("cls");
		cout << " Welcome " << c->getName() << endl;
		printClientMenu(c);
		return  c;
	}
	cout << " Id And Password Don't Match \n";
	system("cls");
	Screens::loginScreen(1);
}
bool clientManager::clientOptions(Client *c)
{
	Client c1;
	string name;
	
	int option= checkInt();
	switch (option)
	{
	case 1:
		system("cls");
		checkBalance(c);
		waitForKeyPress();
		break;

	case 2:
		system("cls");
		Deposit(c);
		waitForKeyPress();
		break;
	case 3:
		system("cls");
		withdraw(c);
		waitForKeyPress();
		break;
	case 4:
		system("cls");
		transfer(c);
		waitForKeyPress();
		break;
	case 5:
		system("cls");
		Display(c);
		waitForKeyPress();
		break;
	case 6:
		system("cls");
		updatePassword(c);
		fileHelper::updateClients(allclients);
		waitForKeyPress();
		break;
	case 7:
		system("cls");
		logout(c);
		return false;
	default:
		system("cls");
		cout << " Please Enter Correct Choice\n";
		break;
	}
	return true;
}
void clientManager::Display(Client *c)
{
	c->Display();
}
void clientManager::checkBalance(Client* c)
{
	cout << " Balance : " << c->getBalance() << endl;
}
void clientManager::Deposit(Client* c)
{
	int amount;
	cout << " Enter amount to Deposit : ";
	cin >> amount;
	c->deposit(amount);
	cout << " Successful Deposit\n Your Balance is : " << c->getBalance() << endl;
	fileHelper::updateClients(allclients);
}
void clientManager::withdraw(Client* c)
{
	int amount;
	cout << " Enter amount to withdraw : ";
	cin >> amount;
	try 
	{
		c->withdraw(amount);
		cout << " Successful Withdrwal\n Your Balance is : " << c->getBalance()<< endl;
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	fileHelper::updateClients(allclients);
}
void clientManager::transfer(Client* c)
{	
	Employee e;
	int amount, id;
	cout << " Enter The Client Id You Need To Transfer To : ";
	cin >> id;
	Client* c1 = e.searchClients(id);
	if (c1 !=nullptr)
	{
		cout << " Amount To Tansfer : ";
		cin >> amount;
		cout << " Transfer To : " << c1->getName() << endl;
		try
		{
			c->transferTo(amount,*c1);
			cout << " Successful Transfer to " << c1->getName()<< endl<< " Your Balance is : " << c->getBalance()<< endl;
			fileHelper::updateClients(allclients);
		}
		catch (exception& e)
		{
			cout << e.what();
		}
	}
	else cout << " User Not Found\n";
}
void clientManager::logout(Client *c)
{
	cout << " " << c->getName() << " is now logged out\n";
	waitForKeyPress();
	system("cls");
	Screens::logout();
}
void clientManager::waitForKeyPress()
{
	cout << " Press any key to return to the main menu...\n";
	char key =_getch();
	system("cls");
}
int clientManager::checkInt()
{	
	int option;
	while (true)
	{	
		cin >>option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			system("cls");
			cout << " Please Enter Numbers Only : \n";
		}
		else

			break;
	}
	return option;
}