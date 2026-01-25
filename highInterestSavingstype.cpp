#include "highInterestSavingsType.h"
#include <iostream>

using namespace std;

highInterestSavingsType::highInterestSavingsType(string name, int accountNumber, int balance) : savingsAccountType(name, accountNumber, balance){}

double highInterestSavingsType::getMinBalance(){
	return MIN_BALANCE;
}

void highInterestSavingsType::withdraw(double amount){
	if(highInterestSavingsType::getMinBalance() <= balance - amount){
		balance = balance - amount;
	}
}

void highInterestSavingsType::print(){
	cout << "your value is <value>" << endl;
}
