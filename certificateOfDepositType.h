#include "bankAccountType.h"

class certificateOfDepositType : public bankAccountType
{
public:
    double interestRate;
    int currentCDMonth;
    certificateOfDepositType(double interestRate, int doubleCDMonth) : bankAccountType(name, accountNumber, balance);
};
