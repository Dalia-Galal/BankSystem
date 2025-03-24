#pragma once
#include<iostream>
#include<string>

#include<vector>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class Parser
{
public:
    static vector<string> Split(string line);
    static Client ParseToClient(string line);
    static Employee ParseToEmployee(string line);
    static Admin ParseToAdmin(string line);
    
};

