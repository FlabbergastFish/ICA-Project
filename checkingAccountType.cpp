#include <iostream>
#include <string>
#include "checkingAccountType.h"

using namespace std;

checkingAccountType::checkingAccountType(string name, int accountNumber, double balance)
        : bankAccountType(name, accountNumber, balance){
};

void checkingAccountType::withdraw(int withdrawalAmount){
	const double WITHDRAWAL_FEE = 2.50;

	cout << "Checking withdrawal: $" << withdrawalAmount << " + $" << WITHDRAWAL_FEE << " fee" << endl;
	balance -= (withdrawalAmount + WITHDRAWAL_FEE);
	cout << "New balance: $" << balance << endl;
}

void checkingAccountType::makeDeposit(int depositAmount){
	cout << "Checking deposit: Adding $" << depositAmount << endl;
	balance += depositAmount;
	cout << "New balance: $" << balance << endl;
}

void checkingAccountType::createMonthlyStatement()
{
    cout << "Monthly statement for checking account" << endl;
}

void checkingAccountType::writeCheck(double amount){};
