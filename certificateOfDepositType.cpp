#include "certificateOfDepositType.h"

certificateOfDepositType::certificateOfDepositType(double interestRate, int doubleCDMonth) : bankAccount(name, accountNumber, balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = interestRate;
        this->currentCDMonth = doubleCDMonth;
    }
