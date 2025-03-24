#pragma once
#include "fileHelper.h"

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

   void fileHelper::readFile(string fileName)
    {
        fstream file;
        file.open(fileName, ios::in);
        string line;
        while (getline(file, line, '\n'))
        {
            stringstream ss(line);
            if (fileName == "Clients.txt")
            {
                Client c = Parser::ParseToClient(line);
                allclients.push_back(move(c));
            }
            else if (fileName == "Employees.txt")
            {
                Employee e = Parser::ParseToEmployee(line);
                allEmployees.emplace_back(e);
            }
            else if (fileName == "Admins.txt")
            {
                Admin a = Parser::ParseToAdmin(line);
                allAdmins.emplace_back(a);
            }
        }
        file.close();
    }
    void fileHelper::saveLast(string fileName, int id)
    {
        fstream file(fileName, ios::out);
        file << id;
        file.close();
    }
    int fileHelper::getLast(string fileName)
    {
        string id;
        fstream file(fileName, ios::in);
        file >> id;
        file.close();
        return stoi(id);
    }
    void fileHelper::saveClient(Client c)
    {
        fstream file;
        file.open("Clients.txt", ios::app);
        file << c.ToString() << endl;
        saveLast("lastClientID.txt", c.getId());
        file.close();
    }
    void fileHelper::saveEmployee(Employee &e)
    {
        fstream file("Employees.txt", ios::app);
        file << e.ToString() << endl;;
        saveLast("lastEmployeeId.txt", e.getId());
        file.close();
    }
    void fileHelper::saveAdmin(Admin& a)
    {
        fstream file;
        if (!file) {
            std::cerr << "Error: Unable to open Clients.txt for writing.\n";
            return;
        }
        file.open("Admins.txt", ios::app);
        file << a.ToString() << endl;;
        saveLast("lastAdminId.txt", a.getId());
        file.close();
    }
    void fileHelper::updateClients(vector<Client> allclients)
    {
        ofstream file("Clients.txt", ios::trunc);
        if (!file) {
            std::cerr << "Error: Unable to open Clients.txt for writing.\n";
            return;
        }
        for (auto &client : allclients)
        {
            file << client.ToString() << endl;
        }
        file.close();
    }
    void fileHelper::updateEmployees(vector<Employee> allEmployees)
    {
        ofstream file("Employees.txt", ios::trunc);
        if (!file) {
            std::cerr << "Error: Unable to open Clients.txt for writing.\n";
            return;
        }
        for (auto &employee : allEmployees)
        {
            file << employee.ToString() << endl;
        }
        file.close();
    }
    void fileHelper::updateAdmins(vector<Admin> allAdmins)
    {
        ofstream file("Admins.txt", ios::trunc);
        if (!file) {
            std::cerr << "Error: Unable to open Clients.txt for writing.\n";
            return;
        }
        for (auto& admin : allAdmins)
        {   
            file << admin.ToString() << endl;
        }
        file.close();
    }
    void fileHelper::getClients()
    {
        readFile("Clients.txt");
    }
    void fileHelper::getEmployees()
    {
        readFile("Employees.txt");
    }
    void fileHelper::getAdmins()
    {
        readFile("Admins.txt");
    }
    void fileHelper::getAllData()
    {
        getClients();
        getEmployees();
        getAdmins();
    }
    void fileHelper::clearFile(string fileName, string lastIdFile)
    {
        ofstream file(fileName), file2;
        file.close();
        file2.open(lastIdFile, ios::in);
        file2 << "0";
        file2.close();
    }
