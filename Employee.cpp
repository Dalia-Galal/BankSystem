#include "Employee.h"
#include"Client.h"
#include"FileManager.h"
#include"Validate.h"
#include"Exceptions.h"
#include<string>
#include<sstream>
using namespace std;
int Employee::noOfEmployees = 0;

Employee::Employee() :Person()
{
    this->salary = 5000;
} 
Employee::Employee(string name, string password, double salary, int):Person(name,password)
{   
    this->setSalary(salary);
}
Employee::Employee(string name, string password, double salary) :Person(name, password)
{
   this->setId(++noOfEmployees);
   this->setSalary(salary);
}

void Employee::setSalary(double salary)
{
    if (Validate::Salary(salary))
    {
        this->salary = salary;
    }
    else
    {
        throw salaryExc();
    }
}
double Employee::getSalary()
{
    return this->salary;
}
string Employee::ToString()
{
    return to_string(getId()) + "," + getName() + "," + getPassword() + "," + to_string(getSalary());
}
void Employee::addClients(Client &c)
{
    if (c.getId() == 0) {
        c.setId(++Client::noOfClients);
    }
    allclients.push_back(move(c));
}

void Employee::listAllClients()
{   
    for (auto &client: allclients)
    {
        client.Display();
    }
}
 Client* Employee::searchClients(int id)
 {
     for (auto &client:allclients)
     {  
         if (client.getId() == id)
         {   
             return &client;
         }
     }
     return nullptr;
 }
 void Employee::editClient(int id, string name, string password, double balance)
 {
     if(searchClients(id))
     {  
         Client* c = Employee::searchClients(id);
         c->setName(name);
         c->setPassword(password);
         c->setBalance(balance);
     }
 }
void Employee::Display()
{
    cout << " Employee Details\n";
    cout << " ID is " << Person::getId() << endl;
    cout << " Name is " << Person::getName() << endl;
    cout << " Password is " << Person::getPassword() << endl;
    cout << " Salary is " << getSalary() << endl;
}

 vector<Employee>allEmployees;

