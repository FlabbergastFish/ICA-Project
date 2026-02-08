#include <iostream>
#include "userType.h"

using namespace std;


int main()
{
	userType user; // The user signed in

	// Set at login. All that needs set for init.
	user.username = "j_doe";

	user.Initialize();

	return 0;
}