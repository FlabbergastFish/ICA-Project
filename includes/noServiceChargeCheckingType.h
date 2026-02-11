#ifndef NO_SERVICE_CHARGE_CHECKING_TYPE_H_
#define NO_SERVICE_CHARGE_CHECKING_TYPE_H_

#include <string>
#include "checkingAccountType.h"

using namespace std;

class noServiceChargeCheckingType : public checkingAccountType {
	public:
		noServiceChargeCheckingType(string name, int accountNumber, double balance, bool frozen);
		noServiceChargeCheckingType(string name, int accountNumber, double balance, bool frozen, 
				            double minBalance, double intRate);

		double getMinimumBalance();
		void setMinimumBalance(double account);
		bool verifyMinimumBalance(double amount);
		void writeCheck(double amount);
		void withdraw(int amount);
		virtual void createMonthlyStatement();
		virtual void print();

	protected:
		double minimumBalance;
		double interestRate;

	private:
		static const double MIN_BALANCE; // = 1000.00;
		static const double INTEREST_RATE; // = 0.02;

};

#endif /* NO_SERVICE_CHARGE_CHECKING_TYPE_H_ */
