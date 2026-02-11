#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeCheckingType.h"

using namespace std;

const double noServiceChargeCheckingType::MIN_BALANCE = 1000.00;
const double noServiceChargeCheckingType::INTEREST_RATE = 0.02;

noServiceChargeCheckingType::noServiceChargeCheckingType(string name,
	                     int accountNumber, double balance, bool frozen) 
	                   : checkingAccountType(name, accountNumber, balance, frozen)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;

}

noServiceChargeCheckingType::noServiceChargeCheckingType(string name, 
		             int accountNumber, double balance, bool frozen, 
			     double minBalance, double intRate) 
	                   : checkingAccountType(name, accountNumber, balance, frozen)
{
	minimumBalance = minBalance;
	interestRate = intRate;

}

double noServiceChargeCheckingType::getMinimumBalance()
{
	return minimumBalance;
}

void noServiceChargeCheckingType::setMinimumBalance(double minBalnce)
{
	minimumBalance = minBalnce;
}

bool noServiceChargeCheckingType::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void noServiceChargeCheckingType::writeCheck(double amount)
{
	if(frozen) {
		return;
	}

	if (verifyMinimumBalance(amount)){
		balance = balance - amount;
	}
}

void noServiceChargeCheckingType::createMonthlyStatement(){
	cout << "monthly statment" << endl;
}


void noServiceChargeCheckingType::print()
{
	if(frozen) {
		cout << "================[FROZEN]================\n";
	}else {
		cout << "========================================\n";
	}
	cout << "Account Type: NO SERVICE CHARGE CHECKING\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Monthly Fee: $0.00\n";
	cout << "Minimum Balance: $" << getMinimumBalance() << endl;
	cout << "Interest Rate: " << (interestRate * 100) << "%\n";
	cout << "========================================\n";
}

void noServiceChargeCheckingType::withdraw(int amount){
	if(balance - amount >= noServiceChargeCheckingType::getMinimumBalance()){
		balance =- amount;
	}

}
