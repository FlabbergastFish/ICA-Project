#include <iostream>
#include "userType.h"
#include "ui.h"

using namespace std;


int main()
{
	userType user;

	if(!loginMenu(user)) {
		return 0; // Cancelled login ends the program
	}

	return 0;
}