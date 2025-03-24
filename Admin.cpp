#include "Admin.h"
#include"Employee.h"
#include"FileManager.h"
#include"FileHelper.h"
#include<string>
#include<vector>
using namespace std;

int Admin::noOfAdmins=0 ;

Admin::Admin() {};
Admin::Admin(string name, string password, double salary) :Employee(name, password, salary, 0)
{
    setId(++noOfAdmins);
}

string Admin::ToString()
{
    return to_string(getId()) + "," + getName() + "," + getPassword() + "," + to_string(getSalary());
}
void Admin::addClients(Client& c)
{
   Employee::addClients(c);
}
Client* Admin::searchClients(int id)
{
    return Employee::searchClients(id);
}
void Admin::editClient(int id, string name, string password, double balance)
{
    Employee::editClient(id, name, password, balance);
}
void Admin::listAllClients()
{
    Employee::listAllClients();
}
void Admin::addEmployee(Employee& e)
{
    if (e.getId() == 0) {
        e.setId(++Employee::noOfEmployees);
    }
    allEmployees.emplace_back(move(e));
}
Employee* Admin::searchEmployee(int id)
{
    for (auto &employee : allEmployees)
    {
        if (employee.getId() == id)
        {
            return &employee;
        }
    }
    return nullptr;
}
void Admin::editEmployee(int id, string name, string password, double salary)
{
    if (searchEmployee(id))
    {
        Employee * e = searchEmployee(id);
        e->setName(name);
        e->setPassword(password);
        e->setSalary(salary);
    }
}
void Admin::listEmployee()
{ 
    for (auto &employee : allEmployees)
    {
        employee.Display();
    }
}
void Admin::Display()
{
    Employee::Display();
}
vector<Admin>allAdmins;