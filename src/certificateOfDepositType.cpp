#include "certificateOfDepositType.h"
#include <iomanip>

using namespace std;

certificateOfDepositType::certificateOfDepositType(string name,
                                                   int accountNumber,
                                                   double balance,
                                                   double interestRate,
                                                   int currentCDMonth)
    : bankAccountType(name, accountNumber, balance),
      interestRate(interestRate),
      currentCDMonth(currentCDMonth)
{
}

void certificateOfDepositType::createMonthlyStatement(){
	cout << "This is a monthly statement";
}

void certificateOfDepositType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "===============================\n";
	cout << "Account Type: CERTIFICATE OF DEPOSIT\n";
	cout << "Name: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Interest Rate: " << (interestRate * 100) << "%\n";
	cout << "Current Month: " << currentCDMonth << endl;
	cout << "===============================\n";
}

