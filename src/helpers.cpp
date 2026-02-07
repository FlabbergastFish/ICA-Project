#include "helpers.h"

// Load user and account data into struct
bool InitializeAccounts(vector<User> &userAccounts) {
    fs::path userPath = fs::path(ACCOUNTS_DIR);
    ifstream inFile;
    bankingType accountType;
    int accountTypeInt;
    double interestRate;
    int currentCDMonth;
    int userCounter = 0;
    int accountCounter = 0;
    double currTransaction;
    int accountNumber;
    string name;

    if (!fs::exists(userPath)) {
        cerr << "\n*** Could not find accounts directory. Users not initialized ***\n\n";
        return false;
    }

    if (fs::is_empty(userPath)) {
        cerr << "\n*** No user directories in accounts directory. Users not initialized ***\n\n";
        return false;
    }

    for(const fs::directory_entry &userDir : fs::directory_iterator(userPath)) {
        if (!userDir.is_directory()){
            continue;
        }

        inFile.open(userDir.path() / USER_DATA_FILE);

        if (!inFile.is_open()) {
            cerr << "\n*** File is not open. User not initialized **\n\n";
            continue;
        }

        User blankUser = {};
        userAccounts.push_back(blankUser);

        userAccounts[userCounter].username = userDir.path().filename().string();


        getline(inFile, userAccounts[userCounter].name);
        getline(inFile, userAccounts[userCounter].salt);

        inFile.close();

        accountCounter = 0;
        for (const fs::directory_entry &file : fs::directory_iterator(userPath / userAccounts[userCounter].username)) {
            if (file.is_directory() || file.path().filename().string() == USER_DATA_FILE) {
                continue;
            }

            inFile.open(file.path());

            if (!inFile.is_open()) {
                cerr << "\n*** File is not open. Account data not initialized ***\n\n";
                continue;
            }

            inFile >> accountTypeInt;
            
            if(accountTypeInt < 0 || accountTypeInt > 5){
                cerr << file.path().filename().string() << endl;
                cerr << "\n*** Invalid account type. Account data not initialized ***\n\n";
                continue;
            }
            
            accountType = bankingType(accountTypeInt);
        
            if(accountType == CERTIFICATE_OF_DEPOSIT){
                inFile >> interestRate;
                inFile >> currentCDMonth;
            }

            userAccounts[userCounter].transactions.push_back(vector<double>());

            while(inFile >> currTransaction){
                userAccounts[userCounter].transactions[accountCounter].push_back(currTransaction);
            }

            accountNumber = stoi(file.path().filename().stem().string());
            name = userAccounts[userCounter].name;

            switch(accountType){
                case SAVINGS:
                    userAccounts[userCounter].accounts.push_back(new savingsAccountType(name, accountNumber, sumTransactions(userAccounts[userCounter], accountCounter)));
                    break;

                case HIGH_INTEREST_SAVINGS:
                    userAccounts[userCounter].accounts.push_back(new highInterestSavingsType(name, accountNumber, sumTransactions(userAccounts[userCounter], accountCounter)));
                    break;

                case NO_SERVICE_CHARGE_CHECKING:
                    userAccounts[userCounter].accounts.push_back(new noServiceChargeCheckingType(name, accountNumber, sumTransactions(userAccounts[userCounter], accountCounter)));
                    break;

                case SERVICE_CHARGE_CHECKING: 
                    userAccounts[userCounter].accounts.push_back(new serviceChargeCheckingType(name, accountNumber, sumTransactions(userAccounts[userCounter], accountCounter)));
                    break;

                case HIGH_INTEREST_CHECKING:
                    userAccounts[userCounter].accounts.push_back(new highInterestCheckingType(name, accountNumber, sumTransactions(userAccounts[userCounter], accountCounter)));
                    break;

                case CERTIFICATE_OF_DEPOSIT:
                    userAccounts[userCounter].accounts.push_back(new certificateOfDepositType(name, accountNumber, sumTransactions(userAccounts[userCounter], accountCounter), interestRate, currentCDMonth));
                    break;
                }
                inFile.ignore(numeric_limits<streamsize>::max(),'\n');

            inFile.close();
            accountCounter++;
        }

        userCounter++;
    }

    return true;
}

double sumTransactions(const User &user, int accountIndex){
    double balance = 0;

    for(const double &amount : user.transactions[accountIndex]){
        balance += amount;
    }

    return balance;
}
