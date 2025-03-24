#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Employee.h"
#include"client.h"
using namespace std;


class Admin :public Employee {
    private:
    static int noOfAdmins;
public:

    Admin();
    Admin(string name, string password, double salary);
    string ToString();
    
    void addClients(Client & client);
    Client* searchClients(int id);
    void listAllClients();
    void editClient(int id, string name, string password, double balance);
    void addEmployee(Employee& e);
    Employee* searchEmployee(int id);
    void editEmployee(int id, string name, string password, double salary);
    void listEmployee();
    void Display();
};
extern vector<Admin>allAdmins;