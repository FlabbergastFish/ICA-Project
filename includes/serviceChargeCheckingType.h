#ifndef SERVICE_CHARGE_CHECKING_TYPE_H
#define SERVICE_CHARGE_CHECKING_TYPE_H

#include <string>
#include "checkingAccountType.h"
using namespace std;

class serviceChargeCheckingType : public checkingAccountType
{
        public:
                serviceChargeCheckingType(string name, int accountNumber, double balance, bool frozen);
                serviceChargeCheckingType(string name, int accountNumber, double balance, bool frozen,
                                          double servChargeAmount, double servChargeCheck);

                double getServiceChargeAccount();
                void setServiceChargeAccount(double amount);
                double getServiceChargeChecks();
                void setServiceChargeChecks(double amount);
                int getNumberOfChecksWritten();
                void setNumberOfChecksWritten(int num);
                void postServiceCharge();
                void writeChecks(double amount);
					 virtual void withdraw(int withdrawalAmount) override;
                virtual void createMonthlyStatement();
                virtual void print();

        protected:
                double serviceChargeAccount;
                double serviceChargeCheck;
                int numberOfChecksWritten;

        private:
                static const double ACCOUNT_SERVICE_CHARGE; // = 10.00;
                static const int MAXIMUM_NUM_OF_CHECKS; // = 5;
                static const double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS; // = 5;
};

#endif
