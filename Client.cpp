#include "Client.h"
#include<string>
#include<vector>
#include"Validate.h"
#include"Exceptions.h"
using namespace std;

int Client::noOfClients= noOfClients;
Client::Client():Person()
{
    this->balance = 1500;
}
Client::Client(string name, string password, double balance) :Person(name, password)
{   
    this->setId(++noOfClients);
    this->setBalance(balance);
}
void Client::setBalance(double balance)
{
    if (Validate::Balance(balance))
    {
        this->balance = balance;
    }
    else
    {
        throw balanceExc();
    }
}
double Client::getBalance()
{
    return this->balance;
}
void Client::deposit(double amount)
{
    this->balance = getBalance() + amount;
}
void Client::withdraw(double amount)
{
    if (Validate::isBalanceAllowed(this->getBalance(), amount))
    {
        this->balance = this->balance - amount;
    }
    else
    {
        throw isBalanceAllowedExc();
    }
}
void Client::transferTo(double amount,Client &recipient)
{   
     if (Validate::isBalanceAllowed(this->getBalance(), amount))
     {
           this->balance = this->getBalance() - amount;
           recipient.deposit(amount);
     }
     else
     {
              throw isBalanceAllowedExc();
     }
}
string Client::ToString()
{
    return to_string(getId()) + "," + getName() + "," + getPassword() + "," + to_string(getBalance());
}
void Client::Display()
{
    cout << " client Details\n";
    cout << " ID is " << Person::getId() << endl;
    cout << " Name is " << Person::getName() << endl;
    cout << " Password is " << Person::getPassword() << endl;
    cout << " balance is " << getBalance() << endl;
}
vector<Client>allclients;