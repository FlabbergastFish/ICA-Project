#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestCheckingType.h"

using namespace std;

const double highInterestCheckingType::INTEREST_RATE = 0.05;
const double highInterestCheckingType::MIN_BALANCE = 5000.00;

highInterestCheckingType::highInterestCheckingType(string name, 
		          int accountNumber, double balance) 
	                : noServiceChargeCheckingType(name, accountNumber, 
			  balance)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

highInterestCheckingType::highInterestCheckingType(string name, 
		          int accountNumber, double balance, 
			  double minBalance, double intRate) 
	                : noServiceChargeCheckingType(name, accountNumber, 
			  balance, minBalance, intRate)
{
}

double highInterestCheckingType::getInterestRate()
{
	return interestRate;
}

void highInterestCheckingType::setInterestRate(double intRate)
{
	interestRate = intRate;
}

void highInterestCheckingType::postInterest()
{
	balance = balance + balance * interestRate;
}

void highInterestCheckingType::createMonthlyStatement()
{
	postInterest();
}

void highInterestCheckingType::print()
{
    cout << fixed << showpoint << setprecision(2);
    cout << "===============================\n";
    cout << "Account Type: HIGH INTEREST CHECKING\n";
    cout << "Name: " << name << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << (getInterestRate() * 100) << "%\n";
    cout << "Minimum Balance: $" << getMinimumBalance() << endl;
    cout << "===============================\n";
}
