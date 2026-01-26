#include "bankAccountType.h"

string bankAccountType::getAccountName()
{
    return this->name;
}

int bankAccountType::getAccountNumber()
{
    return this->accountNumber;
}

int bankAccountType::getBalance()
{
    return balance;
}

void bankAccountType::makeDeposit(int depositAmount)
{
    balance += depositAmount;
}

void bankAccountType::withdraw(int withdrawalAmount)
{
    balance -= withdrawalAmount;
}

void bankAccountType::createMonthlyStatement()
{
    cout << "I'm a monthly statement!";
}
