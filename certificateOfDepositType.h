#include "bankAccountType.h"

class certificateOfDepositType : public bankAccountType
{
public:
    double interestRate;
    int currentCDMonth;

	void createMonthlyStatement() override;

    certificateOfDepositType(string name, int accountNumber, double balance, double interestRate, int currentCDMonth);
};
