#include <iostream>
#include "helpers.h"

using namespace std;


int main()
{
	User user; // The actual user signed in
	vector<User> users; // All accounts at bank if user.manager = true

	// Set at login. All that needs set for init.
	user.username = "j_doe";

	InitializeUser(user, users);

	return 0;
}