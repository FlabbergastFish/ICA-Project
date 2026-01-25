#ifndef savingsAccountType_H
#define savingsAccountType_H

#include <string>
#include "bankAccountType.h"

using namespace std;

class savingsAccountType: public bankAccountType{

	public:
	savingsAccountType(string name, int accountNumber, int balance);

	double getInterestRate();
	virtual void createMonthlyStatement();
	virtual void print();


	private:
	const double savingsIntRate = 0.03;

};
#endif
