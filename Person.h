#pragma once
#include<iostream>
using namespace std;
class Person
{
private:
	int id;
	string name;
	string password;

public:
	
	Person();
	
	Person(string name, string password);
	
	void setId(int id);
	int getId();
	void setName(string name);
	string getName();
	void setPassword(string password);
	string getPassword();
	virtual void Display();
};

