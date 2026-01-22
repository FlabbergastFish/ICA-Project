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

    string getAccountName()
    {
        return this->name;
    }

    int getAccountNumber()
    {
        return this->accountNumber;
    }

    int getBalance()
    {
        return balance;
    }

    void makeDeposit(int depositAmount)
    {
        balance += depositAmount;
    }

    void makeWithdrawal(int withdrawalAmount)
    {
        balance -= withdrawalAmount;
    }

    void createMonthlyStatement()
    {
        cout << "I'm a monthly statement!";
    }
};
