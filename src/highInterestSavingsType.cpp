#include "highInterestSavingsType.h"
#include <iostream>
#include <iomanip>

using namespace std;

highInterestSavingsType::highInterestSavingsType(string name, int accountNumber, int balance, bool frozen) : savingsAccountType(name, accountNumber, balance, frozen){}

double highInterestSavingsType::getMinBalance(){
	return MIN_BALANCE;
}

void highInterestSavingsType::withdraw(int amount){
	if(frozen) {
		return;
	}

	if(highInterestSavingsType::getMinBalance() <= balance - amount){
		balance = balance - amount;
	}
}

void highInterestSavingsType::print()
{
	cout << fixed << showpoint << setprecision(2);
	if(frozen) {
		cout << "================[FROZEN]================\n";
	}else {
		cout << "========================================\n";
	}
	cout << "Account Type: HIGH INTEREST SAVINGS\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Interest Rate: " << (getInterestRate() * 100) << "%\n";
	cout << "Minimum Balance: $" << getMinBalance() << endl;
	cout << "========================================\n";
}
