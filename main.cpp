

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <limits> /* numeric_limits */
#include <ios> /* streamsize */
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"

using namespace std;

int main()
{
	vector<bankAccountType *> accountsList;
	fstream accountsFile;
	enum account{SAVINGS, HIGH_INTEREST_SAVINGS, NO_SERVICE_CHARGE_CHECKING, SERVICE_CHARGE_CHECKING, HIGH_INTEREST_CHECKING, CERTIFICATE_OF_DEPOSIT}; 
	account accountType; 
	string accountTypeStr;
	string name; 
	int accountNumber; 
	int balance;
	double interestRate;
	int currentCDMonth;

	accountsFile.open("dummyAccounts.txt");

	while(accountsFile && getline(accountsFile, accountTypeStr)){
		getline(accountsFile, name);
		accountsFile >> accountNumber;
		accountsFile >> balance;
		accountsFile.ignore(numeric_limits<streamsize>::max(), '\n');

		if(accountTypeStr == "Savings"){
			accountType = SAVINGS;
		}
		if(accountTypeStr == "High Interest Savings"){
			accountType = HIGH_INTEREST_SAVINGS; 
		} 
		if(accountTypeStr == "No Service Charge Checking"){
			accountType = NO_SERVICE_CHARGE_CHECKING;
		}
		if(accountTypeStr == "Service Charge Checking"){
			accountType = SERVICE_CHARGE_CHECKING;
		}
		if(accountTypeStr == "High Interest Checking"){
			accountType = HIGH_INTEREST_CHECKING;
		}
		if(accountTypeStr == "Certificate of Deposit"){
			accountType = CERTIFICATE_OF_DEPOSIT;
		}

		switch(accountType){
			case SAVINGS:
				accountsList.push_back(new savingsAccountType(name, accountNumber, balance));
				break;
			case HIGH_INTEREST_SAVINGS:
				accountsList.push_back(new highInterestSavingsType(name, accountNumber, balance));
				break;
			case NO_SERVICE_CHARGE_CHECKING:
				accountsList.push_back(new noServiceChargeCheckingType(name, accountNumber, balance));
				break;
			case SERVICE_CHARGE_CHECKING: 
				accountsList.push_back(new serviceChargeCheckingType(name, accountNumber, balance));
				break;
			case HIGH_INTEREST_CHECKING:
				accountsList.push_back(new highInterestCheckingType(name, accountNumber, balance));
				break;
			case CERTIFICATE_OF_DEPOSIT:
				accountsFile >> interestRate;
				accountsFile >> currentCDMonth;

				accountsList.push_back(new certificateOfDepositType(name, accountNumber, balance, interestRate, currentCDMonth));
				break;
		}
		accountsFile.ignore(numeric_limits<streamsize>::max(), '\n');
	}


	cout << "January:\n-------------" << endl;
	for (int i = 0; i < accountsList.size(); i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
		cout << endl;
    }

	cout << "\nFebruary:\n-------------" << endl;
	for (int i = 0; i < accountsList.size(); i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
		cout << endl;
	}

	for (int i = 0; i < accountsList.size(); i++)
	{
		accountsList[i]->withdraw(500);
	}

	cout << "\nMarch:\n-------------" << endl;
	for (int i = 0; i < accountsList.size(); i++)
	{
		accountsList[i]->createMonthlyStatement();
		accountsList[i]->print();
		cout << endl;
	}

	accountsFile.close();

	return 0;
}
