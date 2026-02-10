#include "ui.h"

bool loginMenu(userType &user) {
    bool loginSuccess = false;

    cout << "Hello! Please login (enter 'x' to exit)\n";

    do {
		cout << "Username: ";
        getline(cin, user.username);

		if(user.username == "x" || user.username == "X") {
			return false;
		}

		cout << "Password: ";
        getline(cin, user.password);

        if(user.password == "x" || user.password == "X") {
            return false;
		}

		switch (user.Initialize()){
            case 0 :
                loginSuccess = true;
                break;
            case 1:
                cout << "\n*** Could not find accounts directory. User not logged in ***\n\n";
                break;
            case 2 :
                cout << "\n*** No user directories in accounts directory. User not logged in ***\n\n";
                break;
            case 3:
                cout << "\n*** Incorrect username ***\n\n";
                break;
            case 4:
                cout << "\n*** File is not open. User not logged in ***\n\n";
                break;
            case 5 :
                cout << "\n*** Incorrect password ***\n\n";
                break;
            default:
                cout << "\n*** Login Error ***\n\n";
                break;
        }

	} while (!loginSuccess);

    return true;
}

void displayMainMenu(userType &user) {
	int choice;
	bool exitMenu = false;

	while (!exitMenu) {
		cout << "\n========================================\n";
      cout << "         MAIN MENU\n";
      cout << "         Welcome, " << user.username << "!\n";
      cout << "========================================\n";
		cout << "1. Select Account\n";
		cout << "2. View all Accounts\n";
		cout << "3. Logout\n";
		cout << "Enter choice: ";
		cin  >> choice;
		cin.ignore();

		switch(choice) {
			case 1:
				selectAccountMenu(user);
				break;
			case 2:
            viewAllAccounts(user);
            break;
         case 3:
            cout << "\nLogging out...\n" << endl;
            exitMenu = true;
            break;
         default:
            cout << "\n*** Invalid choice. Please try again. ***\n" << endl;
            break;
        }
    }
}

void selectAccountMenu(userType &user) {
	int choice;

	cout << "\n========================================\n";
	cout << "         YOUR ACCOUNTS\n";
	cout << "========================================\n";

	// Display all account numbers
	int numAccounts = static_cast<int>(user.accounts.size());
	for (int i = 0; i < numAccounts; i++) {
		cout << (i + 1) << ". ";
		cout << "Account #" << user.accounts[i]->getAccountNumber()
			  << " - Balance: $" << user.accounts[i]->getBalance() << endl;
	}

	cout << (numAccounts + 1) << ". Back to Main Menu\n";
	cout << "========================================\n";
	cout << "Select account: ";

	cin  >> choice;
	cin.ignore();

	if (choice > 0 && choice <= numAccounts) {
		accountActionsMenu(user, choice - 1);
	}

	else if (choice == numAccounts + 1) {
		return; // to main menu
	}

	else {
		cout << "\n**** Invalid account selection****\n";
	}
}

void accountActionsMenu (userType &user, int accountIndex) {
	int choice;
	bool exitMenu = false;

	while (!exitMenu) {
		bankAccountType* account = user.accounts[accountIndex];

		cout << "\n========================================\n";
		cout << "         ACCOUNT MENU\n";
		cout << "         " << user.name << endl;
		cout << "         Account #" << account->getAccountNumber() << endl;
		cout << "========================================\n";
		cout << "1. View Balance\n";
		cout << "2. Deposit Funds\n";
		cout << "3. Withdraw Funds\n";
		cout << "4. Transfer Funds\n";
		cout << "5. View Account Details\n";
		cout << "6. Back to Account Selection\n";
		cout << "========================================\n";
		cout << "Enter choice: ";
		cin  >> choice;
		cin.ignore();

		switch(choice) {
			case 1:
				viewBalance(account);
				break;
			case 2:
				depositFunds(account);
				break;
			case 3:
				withdrawFunds(account);
				break;
			case 4:
				transferFunds(user, accountIndex);
				break;
			case 5:
				viewAccountDetails(account);
				break;
			case 6:
				exitMenu = true;
				break;
			default:
				cout << "\n****Invalid choice. Please try again. ****\n\n";
				break;

		}
	}

}


void viewBalance(bankAccountType* account) {
	cout << "\n----------------------------------------\n";
	cout << "Current Balance: $" << account->getBalance() << endl;
	cout << "----------------------------------------\n";
}

void depositFunds(bankAccountType* account) {
	int amount;
	cout << "\n----------------------------------------\n";
	cout << "Current Balance: $" << account->getBalance() << endl;
	cout << "Enter amount to deposit: $";
	cin >> amount;
	cin.ignore();

	if (amount <= 0) {
		cout << "\n**** Invalid amount. Deposit must be positive. ****\n\n";
		return;
	}

	cout << "\nProcessing deposit...\n";
	account->makeDeposit(amount);
	cout << "Deposit successful!\n";
	cout << "----------------------------------------\n";
}

void withdrawFunds(bankAccountType* account) {
	int amount;
	cout << "\n----------------------------------------\n";
	cout << "Current Balance: $" << account->getBalance() << endl;
	cout << "Enter amount to withdraw: $";
	cin >> amount;
	cin.ignore();

	if (amount <= 0) {
		cout << "\n*** Invalid amount. Withdrawal must be positive. ***\n\n";
		return;
    }

	cout << "\nProcessing withdrawal...\n";
	account->withdraw(amount);
	cout << "----------------------------------------\n";
}

void transferFunds(userType &user, int fromAccountIndex) {
	int numAccounts = static_cast<int>(user.accounts.size());
	int toAccountChoice;

	if (numAccounts < 2) {
		cout << "\n*** You need at least 2 accounts to transfer funds. ***\n\n";
		return;
    }

	cout << "\n========================================\n";
	cout << "         TRANSFER FUNDS\n";
	cout << "         From Account #" << user.accounts[fromAccountIndex]->getAccountNumber() << endl;
	cout << "         Balance: $" << user.accounts[fromAccountIndex]->getBalance() << endl;
	cout << "========================================\n";
	cout << "Select destination account:\n";

    // Show all accounts except the current one
	for (int i = 0; i < numAccounts; i++) {
		if (i != fromAccountIndex) {
			cout << (i + 1) << ". ";
			cout << "Account #" << user.accounts[i]->getAccountNumber()
				  << " - Balance: $" << user.accounts[i]->getBalance() << endl;
        }
    }

	cout << (numAccounts + 1) << ". Cancel Transfer\n";
	cout << "========================================\n";
	cout << "Select account: ";

	cin >> toAccountChoice;
	cin.ignore();

	int toAccountIndex = toAccountChoice - 1;

	if (toAccountChoice == numAccounts + 1) {
		cout << "\nTransfer cancelled.\n\n";
		return;
	}

	if (toAccountIndex < 0 || toAccountIndex >= numAccounts || toAccountIndex == fromAccountIndex) {
		cout << "\n*** Invalid account selection ***\n\n";
		return;
		}

	double amount;
	cout << "\nEnter amount to transfer: $";
	cin >> amount;
	cin.ignore();

	if (amount <= 0) {
		cout << "\n*** Invalid amount. Transfer must be positive. ***\n\n";
		return;
	}

	cout << "\nProcessing transfer...\n";

	// Use the existing transfer method from userType
	int fromAccountNum = user.accounts[fromAccountIndex]->getAccountNumber();
	int toAccountNum = user.accounts[toAccountIndex]->getAccountNumber();

	user.transfer(amount, fromAccountNum, toAccountNum);

	cout << "\nTransfer completed!\n";
	cout << "Transferred $" << amount << " from Account #" << fromAccountNum
		  << " to Account #" << toAccountNum << endl;
	cout << "----------------------------------------\n";
}

void viewAccountDetails(bankAccountType* account) {
	cout << "\n";
	account->print(); // Polymorphic call - each account type shows different details
}

void viewAllAccounts(userType &user) {
	int numAccounts = static_cast<int>(user.accounts.size());
	cout << "\n****************************************\n";
	cout << "      ALL YOUR ACCOUNTS\n";
	cout << "      Total Accounts: " << user.accounts.size() << endl;
	cout << "****************************************\n\n";

	for (int i = 0; i < numAccounts; i++) {
		user.accounts[i]->print();
		cout << endl;
	}

	cout << "\nPress Enter to continue...";
	cin.ignore();
}
