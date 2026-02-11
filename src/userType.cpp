#include "userType.h"

userType::userType() {

}

// Load user and account data
int userType::Initialize() {
    fs::path userPath = fs::path(USER_DIR);
    ifstream inFile;
    int accountTypeInt;
    double interestRate;
    int currentCDMonth;
    int accountCounter = 0;
    double currTransaction;
    int accountNumber;

    // Check if path to user exists
    if (!fs::exists(userPath)) {
        // cerr << "\n*** Could not find accounts directory. User not initialized ***\n\n";
        return 1;
    }

    if (fs::is_empty(userPath)) {
        // cerr << "\n*** No user directories in accounts directory. User not initialized ***\n\n";
        return 2;
    }

    userPath = userPath / this -> username;

    // TODO: exists check
    if (!fs::directory_entry(userPath).is_directory()) {
        // cerr << "\n*** No user directory. User not initialized ***\n\n";
        return 3;
    }

    inFile.open(userPath / DATA_FILE);

    if (!inFile.is_open()) {
        // cerr << "\n*** File is not open. User not initialized ***\n\n";
        return 4;
    }

    // Read name(string), manager check(boolean), salt(string) into user object
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

    // Iterate through all files in user's directory to get accounts
    for (const fs::directory_entry &file : fs::directory_iterator(userPath)) {

        // Skips data file and any other folders
        if (file.is_directory() || file.path().filename().string() == DATA_FILE) {
            continue;
        }

        inFile.open(file.path());

        if (!inFile.is_open()) {
            cerr << "\n*** File is not open. Account data not initialized ***\n\n";
            continue;
        }

        // Read in account type as int
        inFile >> accountTypeInt;
        
        // Verify int is within enum range skip if not
        if(accountTypeInt < 0 || accountTypeInt > 5) {
            // cerr << file.path().filename().string() << endl;
            // cerr << "\n*** Invalid account type. Account data not initialized ***\n\n";
            continue;
        }
        
        if(bankingType(accountTypeInt) == CERTIFICATE_OF_DEPOSIT) {
            inFile >> interestRate;
            inFile >> currentCDMonth;
        }

        // Add empty vector to back of transactions vector
        this -> transactions.push_back(vector<double>());

        // Read transactions into just added empty vector
        while(inFile >> currTransaction) {
            this -> transactions[accountCounter].push_back(currTransaction);
        }

        // Get account number from file name (without .txt extension) and convert to int
        accountNumber = stoi(file.path().filename().stem().string());

        // Add acount to back of accounts vector (Calls sumTransactions to get balance)
        switch(bankingType(accountTypeInt)) {
            case SAVINGS:
                this -> accounts.push_back(new savingsAccountType(this -> name, accountNumber, sumTransactions(accountCounter)));
                break;

            case HIGH_INTEREST_SAVINGS:
                this -> accounts.push_back(new highInterestSavingsType(this -> name, accountNumber, sumTransactions(accountCounter)));
                break;

            case NO_SERVICE_CHARGE_CHECKING:
                this -> accounts.push_back(new noServiceChargeCheckingType(this -> name, accountNumber, sumTransactions(accountCounter)));
                break;

            case SERVICE_CHARGE_CHECKING: 
                this -> accounts.push_back(new serviceChargeCheckingType(this -> name, accountNumber, sumTransactions(accountCounter)));
                break;

            case HIGH_INTEREST_CHECKING:
                this -> accounts.push_back(new highInterestCheckingType(this -> name, accountNumber, sumTransactions(accountCounter)));
                break;

            case CERTIFICATE_OF_DEPOSIT:
                this -> accounts.push_back(new certificateOfDepositType(this -> name, accountNumber, sumTransactions(accountCounter), interestRate, currentCDMonth));
                break;
        }

        // Clear Buffer since ints were the last read
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        inFile.close();

        // Increase account counter for next account
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

    // Loop through user's accounts to the find account matching acount1
    for(bankAccountType* account : this -> accounts) {
        if(account -> getAccountNumber() == account1) {
            accountFound = true;
            break;
        }

        account1Index++;
    }

    // Check if amount being transferred is more than is in account
    if(this -> accounts[account1Index] -> getBalance() < amount) {
        return;
    }

    if (!accountFound) {
        cerr << "\n*** Account 1 not found ***\n\n";
        return;
    }

    accountFound = false;

    // Iterate through all users
    for(const fs::directory_entry &user : fs::directory_iterator(USER_DIR)) {
        // Iterate through all entries in user directory
        for(const fs::directory_entry &account : fs::directory_iterator(user)) {
            // Skip to next if is data file or folder
            if(account.is_directory() || account.path().filename().string() == DATA_FILE) {
                continue;
            }

            // Set deposit path to account's parent directory when account found
            if(stoi(account.path().filename().stem().string()) == account2) {
                // Check if the user is the owner of the deposit account
                if(user.path().filename().string() == this -> username) {
                    ownAccount = true;
                }

                accountFound = true;
                depositUserPath = account.path().parent_path();
                break;
            }

            // Should line up with user.account[]
            account2Index++;
        }

        // Exit loop if account is found
        if(accountFound) {
            break;
        }

        account2Index = 0;
    }

    if (!accountFound) {
        cerr << "\n*** Account 2 not found ***\n\n";
        return;
    }

    // If transferring to own account the updates can be instant
    if(ownAccount) {
        this->accounts[account1Index] -> withdraw(amount);
        this->transactions[account1Index].push_back(-amount); // Negative because it's a withdraw 
        this->accounts[account2Index] -> makeDeposit(amount);
        this->transactions[account2Index].push_back(amount);

        return;
    }

    // If not own account, create pending transfers directory if it doesn't exist
    if(!fs::exists(depositUserPath / TRANSFERS_DIR)) {
        fs::create_directory(depositUserPath / TRANSFERS_DIR);
    }

    // Open account file in transfers directory in append mode (creates it if it doesn't exist)
    transferFile.open(depositUserPath / TRANSFERS_DIR / (to_string(account2) + ".txt"), ios::app);

    if(!transferFile.is_open()) {
        cerr << "\n*** Unable to open transfer file. Transfer aborted. ***\n\n";
        return;
    }

    transferFile << amount << endl;

    transferFile.close();

    // After adding transfer to other user's pending transfers, withdraw
    // amount from own account and add to transactions
    this->accounts[account1Index] -> withdraw(amount);
    this->transactions[account1Index].push_back(-amount); // Negative because it's a withdraw

}

double userType::sumTransactions(int accountIndex) const {
    double balance = 0;

    for(const double &amount : this -> transactions[accountIndex]) {
        balance += amount;
    }

    return balance;
}
