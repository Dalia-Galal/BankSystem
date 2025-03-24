#pragma once
#include<iostream>
using namespace std;

class Validate
{
public:
   static bool Name(string name);
   
   static bool Password(string password);

   static bool Balance(double balance);
   
   static bool Salary(double salary);
   
   static bool isBalanceAllowed(double balance, double amount);
   
};

