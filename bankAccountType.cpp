#include "bankAccountType.h"

string bankAccount::getAccountName()
{
    return this->name;
}

int bankAccount::getAccountNumber()
{
    return this->accountNumber;
}

int bankAccount::getBalance()
{
    return balance;
}

void bankAccount::makeDeposit(int depositAmount)
{
    balance += depositAmount;
}

void bankAccount::makeWithdrawal(int withdrawalAmount)
{
    balance -= withdrawalAmount;
}

void bankAccount::createMonthlyStatement()
{
    cout << "I'm a monthly statement!";
}
