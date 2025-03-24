#pragma once
#include "Person.h"
#include<vector>
class Client : public Person
{
private:
    double balance;
public:
    static int noOfClients;
    Client();
    Client(string name, string password, double balance);
    void setBalance(double balance);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount,Client& recipeint);
    string ToString();
    void Display();
};
extern vector<Client>allclients;
