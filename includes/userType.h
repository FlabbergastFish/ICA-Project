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

/***************************************************************************************
 * Data/File Structure Documentation
 * *************************************************************************************
 * Generic User Directory Layout
 * -------------------------------------------------------------------------------------
 * Folders are followed by a '/', and anything surrounded with <> is a dynamic names.
 * -------------------------------------------------------------------------------------
 * 
 * data/
 * 	|-- accounts/
 * 	|	 |-- <username>/
 * 	|	 |	   |-- data.txt
 * 	|	 |	   |-- passwd.txt
 * 	|	 |	   |-- pending_transfers/
 * 	|	 |	   |	| -- <account#>.txt
 * 	|	 |	   |	| -- <secondAccount#>.txt
 * 	|	 |	   |	L -- <...Account#>.txt
 * 	|	 |	   |-- <account#>.txt
 * 	|	 |	   |-- <secondAccount#>.txt
 * 	|	 |	   L-- <...Account#>.txt
 * 	|	 |-- <username>/
 * 	|	 |	   |-- ...
 * 
 * *************************************************************************************
 * File Layouts
 * -------------------------------------------------------------------------------------
 * 
 * data/accounts/<username>/data.txt
 * 	 Line 1:	name		 	(string)				e.g. Jane Doe
 * 	 Line 2:	manager     	(bool)					e.g. 0
 * 	 Line 3:	salt        	(string)				e.g. h23k8JO1K
 * 
 * data/accounts/<username>/passwd.txt
 * 	 Line 1:	password 	    (string)				e.g. badPass!
 * 
 * data/accounts/<username>/<acount#>.txt
 * 	 Line 1:	accountType 	(int/enum bankingType)	e.g. 0
 * 	 Line 2:	frozen		 	(bool)					e.g. 0
 * 	 Line 3:	transaction 	(signed double)			e.g. -23.12
 * 	 Line 4+:	transaction 	(signed double)			e.g. 71.84
 * 
 * data/accounts/<username>/pending_transfers/<acount#>.txt
 * 	 Line 1:	transaction 	(double)				e.g. 12.96
 * 	 Line 2+:	transaction 	(double)				e.g. 38.39
 * 
 ***************************************************************************************/

const string USER_DIR = "data/accounts";
const string DATA_FILE = "data.txt";
const string PASSWD_FILE = "passwd.txt";
const string TRANSFERS_DIR = "pending_transfers";
enum bankingType{SAVINGS, HIGH_INTEREST_SAVINGS, NO_SERVICE_CHARGE_CHECKING, SERVICE_CHARGE_CHECKING, HIGH_INTEREST_CHECKING, CERTIFICATE_OF_DEPOSIT};

using namespace std;
namespace fs = filesystem;

class userType {
	public:
	userType();

	// Load user and account data into vector of structs
	int Initialize();
	bool AuthPass();
	// account 1 is the account is the account the money will be withdrawn from and account 2 is the one being deposited into
	int transfer(double amount, int account1, int account2);

	// Sum all transactions in an account
	double sumTransactions(int accountIndex) const;

	string username;
	string name;
	string salt;
	string password;
	bool manager = false;
	vector<bankAccountType *> accounts;
	vector<vector<double>> transactions;
	bool authed = false;
};

#endif /* USER_TYPE_H_ */