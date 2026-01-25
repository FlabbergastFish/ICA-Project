#include "savingsAccountType.h"
#include <iostream>




savingsAccountType::savingsAccountType(string name,int accountNumber, int balance) : bankAccountType(name, accountNumber, balance){


}


double savingsAccountType:: getInterestRate(){
	return savingsIntRate;
}
	
void savingsAccountType:: createMonthlyStatement(){
	cout << "your balance was <balance> and for the month you made <interest earned>" << endl;
	}

	
void savingsAccountType:: print(){
	cout << "your account details are <account details>" << endl;
	}

