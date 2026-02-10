#include <iostream>
#include "userType.h"
#include "ui.h"

using namespace std;


int main()
{
	userType user;

	// display login menu
	if(loginMenu(user)) {
		// show main menu if login successful
		displayMainMenu(user);
	}

	else {
		cout << "Goodbye!\n"; // cancelled login ends the program
	}

	return 0;
}
