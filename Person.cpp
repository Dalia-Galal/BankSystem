#include "Person.h"
#include<iostream>
#include"Validate.h"
#include"Exceptions.h"
#include<string>
using namespace std;

Person::Person()
{
    this->id=0;
    this->name = "set name";
    this->password = "Abcd1234";
}
Person::Person(string name, string password)
{
    this->setId(id);
    this->setName(name);
    this->setPassword(password);
}
void Person::setId(int id)
{
    this->id= id;
}
int Person::getId()
{
    return this->id;
}

void Person::setName(string name)
{
    if (Validate::Name(name))
    {
        this->name = name;
    }
    else
    {
        return;
    }
}
string Person::getName()
{
    return this->name;
}
void Person::setPassword(string password)
{
    if (Validate::Password(password))
    {
        this->password = password;
    }
    else
    {
        return;
    }
}
string Person::getPassword()
{
    return this->password;
}
void Person::Display() {}