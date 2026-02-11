#ifndef highInterestSavingsType_H
#define highInterestSavingsType_H


#include <string>
#include "savingsAccountType.h"

class highInterestSavingsType: public savingsAccountType{
public:
	highInterestSavingsType(string name, int accountNumber, int balance, bool frozen);


	double getMinBalance();
	void withdraw(int amount);
	void print();

private:
	const double MIN_BALANCE = 1000;
	const double HIGH_INTEREST_RATE = 2.5;
};















#endif
