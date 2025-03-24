#include "Parser.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;

  vector<string> Parser::Split(string line)
   {
        string temp;
        stringstream ss(line);
        vector<string> linevector;
        while (getline(ss, temp, ','))
        {
            linevector.push_back(temp);
        }
        return linevector;
   }
   Client Parser::ParseToClient(string line)
   {
        vector<string> lineSplited = Split(line);
        int id = stoi(lineSplited[0]);
        string name = lineSplited[1];
        string password = (lineSplited[2]);
        double balance = (stod(lineSplited[3]));

        return Client(name,password,balance);
   }
   Employee Parser::ParseToEmployee(string line)
    {
        vector<string> lineSplited = Split(line);
        int id = stoi(lineSplited[0]);
        string name = lineSplited[1];
        string password = (lineSplited[2]);
        double salary = (stod(lineSplited[3]));

        return Employee(name, password, salary);
    }
    Admin Parser::ParseToAdmin(string line)
    {
        vector<string> lineSplited = Split(line);
        int id = stoi(lineSplited[0]);
        string name = lineSplited[1];
        string password = (lineSplited[2]);
        double salary = (stod(lineSplited[3]));

        return Admin(name, password, salary);
    }
