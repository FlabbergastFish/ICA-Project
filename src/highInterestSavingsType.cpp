#include "highInterestSavingsType.h"
#include <iostream>
#include <iomanip>

using namespace std;

highInterestSavingsType::highInterestSavingsType(string name, int accountNumber, int balance) : savingsAccountType(name, accountNumber, balance){}

double highInterestSavingsType::getMinBalance(){
	return MIN_BALANCE;
}

void highInterestSavingsType::withdraw(int amount){
	if(highInterestSavingsType::getMinBalance() <= balance - amount){
		balance = balance - amount;
	}
}

void highInterestSavingsType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "===============================\n";
	cout << "Account Type: HIGH INTEREST SAVINGS\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Interest Rate: " << (getInterestRate() * 100) << "%\n";
	cout << "Minimum Balance: $" << getMinBalance() << endl;
	cout << "===============================\n";
}
