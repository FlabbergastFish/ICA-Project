#ifndef UI_H_
#define UI_H_

#include <iostream> /* cout */
#include <vector>
#include "userType.h"
#include "bankAccountType.h"

using namespace std;

// login function
bool loginMenu(userType &user);

// main menu after login
void displayMainMenu(userType &user);

// account selection menu
void selectAccountMenu(userType &user);

// account actions menu
void accountActionsMenu(userType &user, int accountIndex);

// account action functions
void viewBalance(bankAccountType* account);
void depositFunds(bankAccountType* account);
void withdrawFunds(bankAccountType* account);
void transferFunds(userType &user, int fromAccountIndex);
void viewAccountDetails(bankAccountType* account);
void viewAllAccounts(userType &user);


#endif /* UI_H_ */
