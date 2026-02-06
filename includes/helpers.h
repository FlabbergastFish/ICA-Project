#ifndef HELPER_H_
#define HELPER_H_

#include <string> /* string */
#include <vector> /* string */
#include "bankAccountType.h"

using namespace std;

struct User {
	string username;
	string name;
	string salt;
	vector<bankAccountType *> accounts;
};

void InitializeAccount(User &user);

void InitializeAccount(User &user){

}

#endif /* HELPER_H_ */