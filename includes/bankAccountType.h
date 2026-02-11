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
    bool frozen;
    bankAccountType(string name, int accountNumber, int balance, bool frozen)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
        this -> frozen = frozen;
    }

    string getAccountName();

    int getAccountNumber();

    int getBalance();

    virtual void makeDeposit(int depositAmount);

    virtual void withdraw(int withdrawalAmount);

    virtual void createMonthlyStatement() = 0;

    virtual void print();

	 virtual ~bankAccountType() {};
};
