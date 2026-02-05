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
	 cout << "Base class deposit: Adding $" << depositAmount << " to account.\n";
    balance += depositAmount;
	 cout << "New balance: $" << balance << endl;
}

void bankAccountType::withdraw(int withdrawalAmount)
{
	 cout << "Base class withdrawal: Removing $" << withdrawalAmount << "From account.\n";
    balance -= withdrawalAmount;
	 cout << "New balance: $" << balance << endl;
}

void bankAccountType::print()
{
    cout << "Name: " << this->name << endl;
    cout << "Account Number: " << this->accountNumber << endl;
    cout << "Balance: " << this->balance << endl;
}
