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

const string USER_DIR = "data/accounts";
const string DATA_FILE = "data.txt";
const string TRANSFERS_DIR = "pending_transfers";
enum bankingType{SAVINGS, HIGH_INTEREST_SAVINGS, NO_SERVICE_CHARGE_CHECKING, SERVICE_CHARGE_CHECKING, HIGH_INTEREST_CHECKING, CERTIFICATE_OF_DEPOSIT};

using namespace std;
namespace fs = filesystem;

class userType {
	public:
	userType();

	// Load user and account data into vector of structs
	int Initialize();
	// account 1 is the account is the account the money will be withdrawn from and account 2 is the one being deposited into
	void transfer(double amount, int account1, int account2);

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