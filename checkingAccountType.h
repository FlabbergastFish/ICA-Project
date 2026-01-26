#ifndef CHECKING_ACCOUNT_TYPE_H
#define CHECKING_ACCOUNT_TYPE_H

#include <string>
#include "bankAccountType.h"

using namespace std;


class checkingAccountType: public bankAccountType
{
//private:
//      double minimumBalance:
//      double serviceCharge:

public:
        // constructor
        checkingAccountType(string name, int accountNumber, double balance);

        virtual void writeCheck(double amount) = 0;

//      double getMinimumBalance() const;
//      double getServiceCharge() const;

//      void setMinimumBalance(double minBalance);
//      void setServiceCharge(double charge);

        // destructor
//      virtual ~checkingAccountType() {}
};

#endif
