#ifndef HIGH_INTEREST_CHECKING_TYPE_H_
#define HIGH_INTEREST_CHECKING_TYPE_H_

#include <string>
#include "noServiceChargeCheckingType.h"

using namespace std;

class highInterestCheckingType : public noServiceChargeCheckingType{
	public:
		highInterestCheckingType(string name, int accountNumber, double balance, bool frozen);
		highInterestCheckingType(string name, int accountNumber, double balance, bool frozen, 
				         double minBalance, double intRate);

		double getInterestRate();
		void setInterestRate(double intRate);
		void postInterest();
		void createMonthlyStatement();
		virtual void print();

	private:
		static const double INTEREST_RATE; // = 0.05;
		static const double MIN_BALANCE; // = 5000.00;
};

#endif /* HIGH_INTEREST_CHECKING_TYPE_H_ */
