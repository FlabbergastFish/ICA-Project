#include "userType.h"

userType::userType() {

}

// Load user and account data
int userType::Initialize() {
    fs::path userPath = fs::path(USER_DIR);
    ifstream inFile;
    bankingType accountType;
    int accountTypeInt;
    double interestRate;
    int currentCDMonth;
    int accountCounter = 0;
    double currTransaction;
    int accountNumber;
    string name;

    if (!fs::exists(userPath)) {
        // cerr << "\n*** Could not find accounts directory. User not initialized ***\n\n";
        return 1;
    }

    if (fs::is_empty(userPath)) {
        // cerr << "\n*** No user directories in accounts directory. User not initialized ***\n\n";
        return 2;
    }

    userPath = userPath / this -> username;

    if (!fs::directory_entry(userPath).is_directory()) {
        // cerr << "\n*** No user directory. User not initialized ***\n\n";
        return 3;
    }

    inFile.open(userPath / DATA_FILE);

    if (!inFile.is_open()) {
        // cerr << "\n*** File is not open. User not initialized ***\n\n";
        return 4;
    }

    this -> username = userPath.filename().string();


    getline(inFile, this -> name);
    inFile >> this -> manager;
    inFile.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(inFile, this -> salt);

    inFile.close();

    // TODO: Authenticate User Password
    if(false) {
        // cerr << "\n*** Incorrect password. User not initialized ***\n\n";
        return 5;
    }

    accountCounter = 0;

    for (const fs::directory_entry &file : fs::directory_iterator(userPath)) {
        if (file.is_directory() || file.path().filename().string() == DATA_FILE) {
            continue;
        }

        inFile.open(file.path());

        if (!inFile.is_open()) {
            cerr << "\n*** File is not open. Account data not initialized ***\n\n";
            continue;
        }

        inFile >> accountTypeInt;
        
        if(accountTypeInt < 0 || accountTypeInt > 5) {
            // cerr << file.path().filename().string() << endl;
            // cerr << "\n*** Invalid account type. Account data not initialized ***\n\n";
            continue;
        }
        
        accountType = bankingType(accountTypeInt);
    
        if(accountType == CERTIFICATE_OF_DEPOSIT) {
            inFile >> interestRate;
            inFile >> currentCDMonth;
        }

        this -> transactions.push_back(vector<double>());

        while(inFile >> currTransaction) {
            this -> transactions[accountCounter].push_back(currTransaction);
        }

        accountNumber = stoi(file.path().filename().stem().string());
        name = this -> name;

        switch(accountType) {
            case SAVINGS:
                this -> accounts.push_back(new savingsAccountType(name, accountNumber, sumTransactions(accountCounter)));
                break;

            case HIGH_INTEREST_SAVINGS:
                this -> accounts.push_back(new highInterestSavingsType(name, accountNumber, sumTransactions(accountCounter)));
                break;

            case NO_SERVICE_CHARGE_CHECKING:
                this -> accounts.push_back(new noServiceChargeCheckingType(name, accountNumber, sumTransactions(accountCounter)));
                break;

            case SERVICE_CHARGE_CHECKING: 
                this -> accounts.push_back(new serviceChargeCheckingType(name, accountNumber, sumTransactions(accountCounter)));
                break;

            case HIGH_INTEREST_CHECKING:
                this -> accounts.push_back(new highInterestCheckingType(name, accountNumber, sumTransactions(accountCounter)));
                break;

            case CERTIFICATE_OF_DEPOSIT:
                this -> accounts.push_back(new certificateOfDepositType(name, accountNumber, sumTransactions(accountCounter), interestRate, currentCDMonth));
                break;
        }

        inFile.ignore(numeric_limits<streamsize>::max(),'\n');

        inFile.close();
        accountCounter++;
    }

    return 0;
}

void userType::transfer(double amount, int account1, int account2) {
    fs::path userPath = fs::path(USER_DIR);
    fs::path depositUserPath;
    bool accountFound = false;
    bool ownAccount = false;
    int account1Index = 0;
    int account2Index = 0;
    ofstream transferFile;

    if(amount < 0) {
        cerr << "\n*** Cannot transfer a negative amount ***\n\n";
        return;
    }

    for(bankAccountType* account : this -> accounts) {
        if(account -> getAccountNumber() == account1) {
            accountFound = true;
            break;
        }

        account1Index++;
    }

    if(this ->accounts[account1Index] -> getBalance() <= amount) {
        return;
    }

    if (!accountFound) {
        cerr << "\n*** Account 1 not found ***\n\n";
        return;
    }

    accountFound = false;

    for(const fs::directory_entry &user : fs::directory_iterator(USER_DIR)) {
        for(const fs::directory_entry &account : fs::directory_iterator(user)) {
            if(account.is_directory() || account.path().filename().string() == DATA_FILE) {
                continue;
            }

            if(stoi(account.path().filename().stem().string()) == account2) {
                if(user.path().filename().string() == this -> username) {
                    ownAccount = true;
                }

                accountFound = true;
                depositUserPath = account.path().parent_path();
                break;
            }

            account2Index++;
        }

        if(accountFound) {
            break;
        }

        account2Index = 0;
    }

    if (!accountFound) {
        cerr << "\n*** Account 2 not found ***\n\n";
        return;
    }

    if(ownAccount) {
        this->accounts[account1Index] -> withdraw(amount);
        this->transactions[account1Index].push_back(-amount);
        this->accounts[account2Index] -> makeDeposit(amount);
        this->transactions[account2Index].push_back(amount);

        return;
    }

    if(!fs::exists(depositUserPath / TRANSFERS_DIR)) {
        fs::create_directory(depositUserPath / TRANSFERS_DIR);
    }

    transferFile.open(depositUserPath / TRANSFERS_DIR / (to_string(account2) + ".txt"), ios::app);

    if(!transferFile.is_open()) {
        cerr << "\n*** Unable to open transfer file. Transfer aborted. ***\n\n";
        return;
    }

    transferFile << amount << endl;

    transferFile.close();

    this->accounts[account1Index] -> withdraw(amount);
    this->transactions[account1Index].push_back(-amount);

}

double userType::sumTransactions(int accountIndex) const {
    double balance = 0;

    for(const double &amount : this -> transactions[accountIndex]) {
        balance += amount;
    }

    return balance;
}
