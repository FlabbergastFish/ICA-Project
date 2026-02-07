#ifndef HELPERS_H_
#define HELPERS_H_

#include <string>     /* string */
#include <vector>     /* string */
#include <filesystem> /* path, exists, is_directory, filename, string, stem */
#include <fstream>    /* ifstream */
#include <iostream>   /* cerr */
#include <ios>        /* streamsize */
#include <limits>     /* numeric_limits */
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
#include "bankAccountType.h"

const string ACCOUNTS_DIR = "data/accounts";
const string USER_DATA_FILE = "data.txt";
enum bankingType{SAVINGS, HIGH_INTEREST_SAVINGS, NO_SERVICE_CHARGE_CHECKING, SERVICE_CHARGE_CHECKING, HIGH_INTEREST_CHECKING, CERTIFICATE_OF_DEPOSIT};

using namespace std;
namespace fs = filesystem;

struct User {
	string username;
	string name;
	string salt;
	string password;
	vector<bankAccountType *> accounts;
	vector<vector<double>> transactions;
};

// Load user and account data into struct
bool InitializeAccounts(vector<User> &user);

double sumTransactions(const User &user, int accountIndex);

#endif /* HELPERS_H_ */