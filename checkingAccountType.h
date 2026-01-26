#ifndef CHECKING_ACCOUNT_TYPE_H
#define CHECKING_ACCOUNT_TYPE_H

#include "bankAccountType.h"

class checkingAccountType: public bankAccountType
{
private:
        double minimumBalance:
        double serviceCharge:

public:
        // constructor
        checkingAccountType(string name, int accountNumber, double balance, double minBalance, double charge);

        virtual void writeCheck(double amount) = 0;

        double getMinimumBalance() const;
        double getServiceCharge() const;

        void setMinimumBalance(double minBalance);
        void setServiceCharge(double charge);

        // destructor
        virtual ~checkingAccountType() {}
};

#endif
