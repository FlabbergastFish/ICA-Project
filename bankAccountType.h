#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
class bankAccountType
{
public:
    string name;
    int accountNumber;
    int balance;
    bankAccountType(string name, int accountNumber, int balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    string getAccountName();

    int getAccountNumber();

    int getBalance();

    void makeDeposit(int depositAmount);

    void makeWithdrawal(int withdrawalAmount);

    void createMonthlyStatement();
};
