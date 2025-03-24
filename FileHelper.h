#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"

 using namespace std;


 class fileHelper{
 public:
 
     static void readFile(string fileName);

     static void saveLast(string fileName, int id);

     static int getLast(string fileName);
     static void saveClient(Client c);

     static void saveEmployee(Employee& e);

     static void saveAdmin(Admin &a);

     static void updateClients(vector<Client> allclients);
     static void updateEmployees(vector<Employee> allEmployees);
     static void updateAdmins(vector<Admin> allAdmins);
     static void getClients();

     static void getEmployees();

     static void getAdmins();
     static void getAllData();
     static void clearFile(string fileName, string lastIdFile);
   
};

