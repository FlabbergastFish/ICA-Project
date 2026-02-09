#include "ui.h"

bool loginMenu(userType &user) {
    bool loginSuccess = false;

    cout << "Hello! Please login (enter 'x' to exit)\n";

    do {
		cout << "Username: ";
        getline(cin, user.username);

		if(user.username == "x" || user.username == "X") {
			return false;
		}

		cout << "Password: ";
        getline(cin, user.password);

        if(user.password == "x" || user.password == "X") {
            return false;
		}

		switch (user.Initialize()){
            case 0 :
                loginSuccess = true;
                break;
            case 1:
                cout << "\n*** Could not find accounts directory. User not logged in ***\n\n";
                break;
            case 2 :
                cout << "\n*** No user directories in accounts directory. User not logged in ***\n\n";
                break;
            case 3:
                cout << "\n*** Incorrect username ***\n\n";
                break;
            case 4:
                cout << "\n*** File is not open. User not logged in ***\n\n";
                break;
            case 5 :
                cout << "\n*** Incorrect password ***\n\n";
                break;
            default:
                cout << "\n*** Login Error ***\n\n";
                break;
        }

	} while (!loginSuccess);

    return true;
}