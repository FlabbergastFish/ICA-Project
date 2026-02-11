#ifndef savingsAccountType_H
#define savingsAccountType_H

#include <string>
#include "bankAccountType.h"

using namespace std;

class savingsAccountType: public bankAccountType{

	public:
	savingsAccountType(string name, int accountNumber, int balance, bool frozen);

	double getInterestRate();
	virtual void withdraw(int withdrawalAmount) override; // Override withdraw
	virtual void makeDeposit(int depositAmount) override; // Override deposit
	virtual void createMonthlyStatement();
	virtual void print();


	private:
	const double savingsIntRate = 0.03;
	const int minimumBalance = 500;

};
#endif
