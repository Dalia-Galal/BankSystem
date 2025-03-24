#include "FileManager.h"
    void fileManager::addClient(Client c)
    {
        fileHelper::saveClient(c);
    }
    void fileManager::addEmployee(Employee &e)
    {
        fileHelper::saveEmployee(e);
    }
    void fileManager::addAdmin(Admin &a)
    {
        fileHelper::saveAdmin(a);
    }
    void fileManager::getAllClients()
    {
        fileHelper::getClients();
    }
    void fileManager::getAllEmployees()
    {
        fileHelper::getEmployees();
    }
    void fileManager::getAllAdmins()
    {
        fileHelper::getAdmins();
    }
    void fileManager::removeAllClients()
    {
        fileHelper::clearFile("Clients.txt", "lastClientID.txt");
    }
    void fileManager::removeAllEmployees()
    {
        fileHelper::clearFile("Employees.txt", "lastEmployeeID.txt");
    }
    void fileManager::removeAllAdmins()
    {
        fileHelper::clearFile("Admins.txt", "lastAdminID.txt");
    }