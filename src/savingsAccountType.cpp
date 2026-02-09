#include "savingsAccountType.h"
#include <iostream>




savingsAccountType::savingsAccountType(string name,int accountNumber, int balance) : bankAccountType(name, accountNumber, balance){


}


double savingsAccountType:: getInterestRate(){
	return savingsIntRate;
}

void savingsAccountType::withdraw(int withdrawalAmount){
	cout << "SAVINGS withdrawal:\n";
	if (balance - withdrawalAmount < minimumBalance){
		cout << "ERROR: Withdrawal would bring balance below minimum of $" << minimumBalance << endl;
		cout << "Current balance: $" << balance << ", Attempted withdrawal: $" << withdrawalAmount << endl;
	}
	else{
		balance -= withdrawalAmount;
		cout << "Withdrawal successful: $" << withdrawalAmount << endl;
		cout << "New balance: $" << balance << endl;
	}
}

void savingsAccountType::makeDeposit(int depositAmount){
	cout << "SAVINGS deposit: Adding $" << depositAmount << endl;
	balance += depositAmount;
	cout << "New balance: $" << balance << endl;
}

void savingsAccountType:: createMonthlyStatement(){
	cout << "your balance was <balance> and for the month you made <interest earned>" << endl;
	}


void savingsAccountType:: print()
{
	cout << "===============================\n";
	cout << "Account Type: SAVINGS ACCOUNT\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Interest Rate: " << (savingsIntRate * 100) << "%\n";
	cout << "Minimum Balance Required: $" << minimumBalance << endl;
	cout << "===============================\n";
}
