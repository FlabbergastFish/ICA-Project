#ifndef CHECKING_ACCOUNT_TYPE_H
#define CHECKING_ACCOUNT_TYPE_H

#include <string>
#include "bankAccountType.h"

using namespace std;


class checkingAccountType: public bankAccountType
{
public:
        // constructor
        checkingAccountType(string name, int accountNumber, double balance);

        virtual void writeCheck(double amount);
		  virtual void withdraw(int withdrawalAmount) override;
		  virtual void makeDeposit(int depositAmount) override;
			virtual void createMonthlyStatement() override;

//      double getMinimumBalance() const;
//      double getServiceCharge() const;

//      void setMinimumBalance(double minBalance);
//      void setServiceCharge(double charge);

        // destructor
		  virtual ~checkingAccountType() {}
};

#endif
