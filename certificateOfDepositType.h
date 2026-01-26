#include "bankAccountType.h"

class certificateOfDepositType : public bankAccountType
{
public:
    double interestRate;
    int currentCDMonth;

    certificateOfDepositType(string name, int accountNumber, double balance, double interestRate, int currentCDMonth);
};
