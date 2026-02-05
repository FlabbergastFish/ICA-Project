#include "certificateOfDepositType.h"

certificateOfDepositType::certificateOfDepositType(string name,
                                                   int accountNumber,
                                                   double balance,
                                                   double interestRate,
                                                   int currentCDMonth)
    : bankAccountType(name, accountNumber, balance),
      interestRate(interestRate),
      currentCDMonth(currentCDMonth)
{
}

void certificateOfDepositType::createMonthlyStatement(){
	cout << "This is a monthly statement";
}

