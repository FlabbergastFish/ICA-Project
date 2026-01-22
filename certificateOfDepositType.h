#include "bankAccountType.h"

class certificateOfDepositType : public bankAccount
{
public:
    double interestRate;
    int currentCDMonth;
    certificateOfDepositType(double interestRate, int doubleCDMonth) : bankAccount(name, accountNumber, balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = interestRate;
        this->currentCDMonth = doubleCDMonth;
    }
};
