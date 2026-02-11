#include <iostream>
#include <string>
#include <iomanip>
#include "serviceChargeCheckingType.h"

using namespace std;

const double serviceChargeCheckingType::ACCOUNT_SERVICE_CHARGE = 10.00;
const int serviceChargeCheckingType::MAXIMUM_NUM_OF_CHECKS = 5;
const double serviceChargeCheckingType::SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5;

serviceChargeCheckingType::serviceChargeCheckingType(string name, int accountNumber,
        double balance, bool frozen)
        : checkingAccountType(name, accountNumber, balance, frozen)
{
        serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
        numberOfChecksWritten = 0;
        serviceChargeCheck = 0;
}

serviceChargeCheckingType::serviceChargeCheckingType(string name, int accountNumber,
                                                     double balance, bool frozen,
                                                     double servChargeAmount,
                                                     double servChargeCheck)
                                                 : checkingAccountType(name, accountNumber, balance, frozen)
{
        serviceChargeAccount = servChargeAmount;
        serviceChargeCheck = servChargeCheck;
        numberOfChecksWritten = 0;
}

void serviceChargeCheckingType::withdraw(int withdrawalAmount)
{
        if(frozen) {
		return;
	}

	const double EXTRA_SERVICE_FEE = 5.00;
	cout << "SERVICE CHARGE CHECKING withdrawal: $" << withdrawalAmount << " + $"
		  << EXTRA_SERVICE_FEE << " service fee\n";
	balance -= (withdrawalAmount + EXTRA_SERVICE_FEE);
	cout << "New balance: $" << balance << endl;
}

double serviceChargeCheckingType::getServiceChargeAccount()
{
        return serviceChargeAccount;
}

void serviceChargeCheckingType::setServiceChargeAccount(double amount)
{
        if(frozen) {
		return;
	}

        serviceChargeAccount = amount;
}

double serviceChargeCheckingType::getServiceChargeChecks()
{
        return serviceChargeCheck;
}

void serviceChargeCheckingType::setServiceChargeChecks(double amount)
{
        if(frozen) {
		return;
	}

        serviceChargeCheck = amount;
}

int serviceChargeCheckingType::getNumberOfChecksWritten()
{
	return numberOfChecksWritten;
}

void serviceChargeCheckingType::postServiceCharge()
{
        balance = balance - serviceChargeAccount;
}

void serviceChargeCheckingType:: writeChecks(double amount)
{
        if(frozen) {
		return;
	}

        if (numberOfChecksWritten < MAXIMUM_NUM_OF_CHECKS)
                balance = balance - amount;
        else
                balance = balance - amount - serviceChargeCheck;
        numberOfChecksWritten++;
}

void serviceChargeCheckingType::createMonthlyStatement()
{
        postServiceCharge();
}

void serviceChargeCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	if(frozen) {
		cout << "================[FROZEN]================\n";
	}else {
		cout << "========================================\n";
	}
	cout << "Account Type: SERVICE CHARGE CHECKING\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Monthly Service Charge: $" << serviceChargeAccount << endl;
	cout << "Withdrawal Fee: $5.00 per transaction\n";
	cout << "Checks Written This Month: " << numberOfChecksWritten << endl;
	cout << "========================================\n";
}
