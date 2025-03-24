#pragma once
#include"DataSource.h"
#include"FileHelper.h"


class fileManager :public DataSource
{
public:
    static void addClient(Client c);

    static void addEmployee(Employee &e);

    static void addAdmin(Admin &a);
    
    static void getAllClients();
    
    static void getAllEmployees();
    
    static void getAllAdmins();
    
    static void removeAllClients();
    
    static void removeAllEmployees();
   
    static void removeAllAdmins();
    
};

