#ifndef USER_TYPE_H_
#define USER_TYPE_H_

#include <string>     /* string */
#include <vector>     /* vector */
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

const string ACCOUNTS_DIR = "data/accounts";
const string USER_DATA_FILE = "data.txt";
enum bankingType{SAVINGS, HIGH_INTEREST_SAVINGS, NO_SERVICE_CHARGE_CHECKING, SERVICE_CHARGE_CHECKING, HIGH_INTEREST_CHECKING, CERTIFICATE_OF_DEPOSIT};

using namespace std;
namespace fs = filesystem;

class userType {
	public:
	userType();

	// Load user and account data into vector of structs
	bool Initialize();

	// Sum all transactions in an account
	double sumTransactions(int accountIndex) const;

	string username;
	string name;
	string salt;
	string password;
	bool manager = false;
	vector<bankAccountType *> accounts;
	vector<vector<double>> transactions;

};

#endif /* USER_TYPE_H_ */