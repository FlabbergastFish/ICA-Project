#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeCheckingType.h"

using namespace std;

const double noServiceChargeCheckingType::MIN_BALANCE = 1000.00;
const double noServiceChargeCheckingType::INTEREST_RATE = 0.02;

noServiceChargeCheckingType::noServiceChargeCheckingType(string name,
	                     int accountNumber, double balance) 
	                   : checkingAccountType(name, accountNumber, balance)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;

}

noServiceChargeCheckingType::noServiceChargeCheckingType(string name, 
		             int accountNumber, double balance, 
			     double minBalance, double intRate) 
	                   : checkingAccountType(name, accountNumber, balance)
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
	if (verifyMinimumBalance(amount)){
		balance = balance - amount;
	}
}

void noServiceChargeCheckingType::createMonthlyStatement(){
	cout << "monthly statment" << endl;
}


void noServiceChargeCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "No Service Charge Check. " << name << "\t ACCT# " 
	     << getAccountNumber() << "\tBalance: $" << getBalance();
}
