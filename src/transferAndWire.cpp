#include "transfersAndWire.h"

void transfer(double amount, int account1, int account2, vector<User>& users){
	bankAccountType* account1Ptr = nullptr;
	bankAccountType* account2Ptr = nullptr;
	for(int i = 0; i < users.size(); i++){
		for(int j = 0; j < users[i].accounts.size(); j++){
			if(users[i].accounts[j]->getAccountNumber() == account1){
				account1Ptr = users[i].accounts[j];
			}
			if(users[i].accounts[j]->getAccountNumber() == account2){
				account2Ptr = users[i].accounts[j];
			}
		}
	}

	if(account1Ptr == nullptr || account2Ptr == nullptr){
		cout << "one or more invalid account numbers" << endl;
		return;
	}

	account1Ptr -> withdraw(amount);
	account2Ptr -> deposit(amount);


}
