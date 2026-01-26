#include <iostream>
#include <string>
#include "checkingAccountType.h"

using namespace std;

checkingAccountType::checkingAccountType(string name, int accountNumber, double balance)
        : bankAccountType(name, accountNumber, balance){


};

void checkingAccountType::writeCheck(double amount){};
