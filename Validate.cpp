#include "Validate.h"
#include<iostream>
#include<string>
using namespace std;

bool flag = false;

bool Validate::Name(string name)
{
    if (name.length() < 5 || name.length() > 20)
    {
        flag = false;
    }
    else
    {
        for (int i = 0; i < name.length(); i++)
        {
            if (!isalpha(name.at(i)))
            {
                flag = false;
            }
            else
            {
                flag = true;
            }
        }
    }
    return flag;
}
bool Validate::Password(string password)
{
    return(password.length() < 8 || password.length() > 20) ? false : true;
}
bool Validate::Balance(double balance)
{
    return (balance >= 1500)? true : false;
}
bool Validate::Salary(double salary)
{
    if (salary < 5000)
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
    return flag;
}
bool Validate::isBalanceAllowed(double balance, double amount)
{
   return (amount < balance) ? true : false;
}
