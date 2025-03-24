#pragma once
#include "Person.h"
#include"Client.h"
#include<vector>
class Employee :public Person
{
private:
    double salary;
    
protected:
    static int noOfEmployees;
    Employee(string name, string password, double balance, int);
public:
    Employee();

    Employee(string name, string password, double salary);

    void setSalary(double salary);
    double getSalary();
    string ToString();
    void addClients(Client& c);
    void listAllClients();
    Client* searchClients(int id);
    void editClient(int id, string name, string password, double balance);
    void Display();
};
extern vector<Employee>allEmployees;