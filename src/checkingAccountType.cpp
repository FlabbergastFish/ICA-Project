#include <iostream>
#include <string>
#include "checkingAccountType.h"

using namespace std;

checkingAccountType::checkingAccountType(string name, int accountNumber, double balance, bool frozen)
        : bankAccountType(name, accountNumber, balance, frozen){
};

void checkingAccountType::withdraw(int withdrawalAmount){
	const double WITHDRAWAL_FEE = 2.50;
	
	if(frozen) {
		return;
	}

	cout << "Checking withdrawal: $" << withdrawalAmount << " + $" << WITHDRAWAL_FEE << " fee" << endl;
	balance -= (withdrawalAmount + WITHDRAWAL_FEE);
	cout << "New balance: $" << balance << endl;
}

void checkingAccountType::makeDeposit(int depositAmount){
	if(frozen) {
		return;
	}

	cout << "Checking deposit: Adding $" << depositAmount << endl;
	balance += depositAmount;
	cout << "New balance: $" << balance << endl;
}

void checkingAccountType::createMonthlyStatement()
{
    cout << "Monthly statement for checking account" << endl;
}

void checkingAccountType::writeCheck(double amount){
	if(frozen) {
		return;
	}
};

void checkingAccountType::print()
{
	if(frozen) {
		cout << "================[FROZEN]================\n";
	}else {
		cout << "========================================\n";
	}
	cout << "Account Type: CHECKING ACCOUNT\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Withdrawal Fee: $2.50 per transaction\n";
	cout << "========================================\n";
}
