#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
class bankAccount
{
public:
    string name;
    int accountNumber;
    int balance;
    bankAccount(string name, int accountNumber, int balance)
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
