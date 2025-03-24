#pragma once
#include<iostream>
#include<exception>

using namespace std;

class salaryExc :public exception
{
public:
    const char* what() const noexcept;
};
class balanceExc :public exception
{
public:
const  char * what() const noexcept;
};
class isBalanceAllowedExc :public exception
{
public:
    const char* what() const noexcept;

};

class clientNotFound :public exception
{
public:
    const char* what() const noexcept;

};