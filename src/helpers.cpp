#include "helpers.h"

// Load user and account data into struct
bool InitializeAccount(vector<User> &userAccounts) {
    fs::path userPath = fs::path(ACCOUNTS_DIR);
    ifstream inFile;
    bankingType accountType;
    string accountTypeStr;
    double interestRate;
    int currentCDMonth;
    int userCounter = 0;
    int accountCounter = 0;
    User blankUser;
    double currTransaction;
    int accountNumber;
    string name;

    if (!fs::exists(userPath)) {
        cerr << "\n*** Could not find accounts directory. Accounts not initialized ***\n\n";
            return false;
    }

    // TODO: EMPTY ACCOUNTS DIR CHECK

    accountCounter = 0;
    for(const fs::directory_entry &userDir : fs::directory_iterator(userPath)) {
        inFile.open(userDir.path() / USER_DATA_FILE);

        if (!inFile.is_open()) {
            cerr << "\n*** File is not open. Account not initialized **\n\n";
            continue;
        }

        // TODO: ENSURE BLANK USER ACTUALLY BLANK
        userAccounts.push_back(blankUser);

        userAccounts[userCounter].username = userDir.path().filename().stem().string();


        getline(inFile, userAccounts[userCounter].name);
        getline(inFile, userAccounts[userCounter].salt);

        inFile.close();

        for (const fs::directory_entry &file : fs::directory_iterator(userPath / userAccounts[userCounter].username)) {
            if (file.is_directory() || file.path().filename().string() == USER_DATA_FILE) {
                continue;
            }

            inFile.open(file.path());

            if (!inFile.is_open()) {
                cerr << "\n*** File is not open. Account partially Initialized ***\n\n";
                continue;
            }

            getline(inFile, accountTypeStr);
        
            if(accountTypeStr == "Savings"){
                accountType = SAVINGS;
            }

            else if(accountTypeStr == "High Interest Savings"){
                accountType = HIGH_INTEREST_SAVINGS; 
            } 

            else if(accountTypeStr == "No Service Charge Checking"){
                accountType = NO_SERVICE_CHARGE_CHECKING;
            }

            else if(accountTypeStr == "Service Charge Checking"){
                accountType = SERVICE_CHARGE_CHECKING;
            }

            else if(accountTypeStr == "High Interest Checking"){
                accountType = HIGH_INTEREST_CHECKING;
            }

            else if(accountTypeStr == "Certificate of Deposit"){
                accountType = CERTIFICATE_OF_DEPOSIT;
                inFile >> interestRate;
                inFile >> currentCDMonth;
            }
            else{
                continue;
            }

            userAccounts[userCounter].transactions.push_back(vector<double>());

            while(inFile >> currTransaction){
                userAccounts[userCounter].transactions[accountCounter].push_back(currTransaction);
            }

            accountNumber = stoi(file.path().filename().stem().string());
            name = userAccounts[userCounter].name;

            switch(accountType){
                case SAVINGS:
                    userAccounts[userCounter].accounts.push_back(new savingsAccountType(name, accountNumber, sumTransactions));
                    break;

                case HIGH_INTEREST_SAVINGS:
                    userAccounts[userCounter].accounts.push_back(new highInterestSavingsType(name, accountNumber, sumTransactions));
                    break;

                case NO_SERVICE_CHARGE_CHECKING:
                    userAccounts[userCounter].accounts.push_back(new noServiceChargeCheckingType(name, accountNumber, sumTransactions));
                    break;

                case SERVICE_CHARGE_CHECKING: 
                    userAccounts[userCounter].accounts.push_back(new serviceChargeCheckingType(name, accountNumber, sumTransactions));
                    break;

                    case HIGH_INTEREST_CHECKING:
                    userAccounts[userCounter].accounts.push_back(new highInterestCheckingType(name, accountNumber, sumTransactions));
                    break;

                case CERTIFICATE_OF_DEPOSIT:
                    userAccounts[userCounter].accounts.push_back(new certificateOfDepositType(name, accountNumber, sumTransactions, interestRate, currentCDMonth));
                    break;
                }

            inFile.close();
            accountCounter++;
        }

        userCounter++;
    }

    return true;
}

double sumTransactions(User user, int accountIndex){
    double balance = 0;

    for(const double &amount : user.transactions[accountIndex]){
        balance += amount;
    }

    return balance;
}
