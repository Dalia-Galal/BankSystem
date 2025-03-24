#pragma once
#include"Person.h"
#include"Client.h"
#include"FileHelper.h"
#include"Screens.h"
#include<string>
#include"Exceptions.h"
#include"Validate.h"
using namespace std;
class clientManager
{
public:
	static void printClientMenu(Client *c);
	static void updatePassword(Person *p);
	static Client* login(int id, string password);
	static bool clientOptions(Client *c);
	static void Display(Client* c);
	static void checkBalance(Client* c);
	static void Deposit(Client* c);
	static void withdraw(Client* c);
	static void transfer(Client* c);
	static void logout(Client* c);
	static void waitForKeyPress();
	static int checkInt();
	
};