#ifndef SERVICE_CHARGE_CHECKING_TYPE_H
#define SERVICE_CHARGE_CHECKING_TYPE_H

#include "checkingAccountType.h"

class serviceChargeCheckingType : public checkingAccountType
{
private:
        int numChecks;
        double checkFee;

public:
        // constructor
        serviceChargeCheckingType(string name, int accountNumber, double balance, double minBalance,
                                                                          double charge, double fee);

        void writeCheck(double amount);

        int getNumChecks() const;
        double getCheckFee() const;
        void setCheckFee(double fee);
        void resetNumChecks();

        // destructor
        ~serviceChargeCheckingType() {}
};

#endif
