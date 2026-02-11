#include "bankAccountType.h"

class certificateOfDepositType : public bankAccountType
{
public:
	double interestRate;
	int currentCDMonth;

	void createMonthlyStatement() override;
	virtual void print() override;

    certificateOfDepositType(string name, int accountNumber, double balance, bool frozen, double interestRate, int currentCDMonth);
};
