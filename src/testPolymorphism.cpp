#include <iostream>
#include <vector>
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "checkingAccountType.h"
#include "serviceChargeCheckingType.h"

using namespace std;

void displayAllAccounts(vector<bankAccountType*>& accounts)
{
	cout << "\n=============================\n";
	cout << "  Account Information Display\n";
	cout << "  Total Accounts: " << accounts.size() << endl;
	cout << "=============================\n";

	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->print();
		cout << endl;
	}
}

int main()
{
    vector<bankAccountType*> accounts;

    // Create different account types
    accounts.push_back(new savingsAccountType("Alice Johnson", 1001, 2000));
    accounts.push_back(new checkingAccountType("Bob Smith", 2001, 1500));
    accounts.push_back(new serviceChargeCheckingType("Charlie Brown", 3001, 1000));

	// Initial display of accounts
    displayAllAccounts(accounts);
    // Test deposits 
    cout << "--- TESTING DEPOSITS ---\n" << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "Account: " << accounts[i]->getAccountName() << endl;
        accounts[i]->makeDeposit(100);  
        cout << endl;
    }
    
    // Test withdrawals 
    cout << "\n--- TESTING WITHDRAWALS ---\n" << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "Account: " << accounts[i]->getAccountName() << endl;
        accounts[i]->withdraw(500);  // Virtual function call through base pointer
        cout << endl;
    }
    
    // Test withdrawal that violates savings minimum balance
    cout << "\n--- TESTING SAVINGS MINIMUM BALANCE VIOLATION ---\n" << endl;
    cout << "Account: " << accounts[0]->getAccountName() << endl;
    accounts[0]->withdraw(1500);  // This should fail for savings account
    cout << endl;

	// Display accounts after transactions
	displayAllAccounts(accounts);
    // Clean up memory
    for (int i = 0; i < accounts.size(); i++)
    {
        delete accounts[i];
    }
    
    return 0;
}
