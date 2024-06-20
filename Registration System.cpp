#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define a User structure to hold username and password
struct User {
	string username;
	string password;
};

// Function to register a new user
void registerUser() {
	User newUser;

	// Input username
	cout << "Enter username: ";
	cin >> newUser.username;

	// Input password
	cout << "Enter password: ";
	cin >> newUser.password;

	// Validate username and password (basic validation for demonstration)
	if (newUser.username.empty() || newUser.password.empty()) {
		cerr << "Username or password cannot be empty.\n";
		return;
	}

	// Open a file to store user data (append mode)
	ofstream outfile("users.txt", ios_base::app);

	if (!outfile) {
		cerr << "Error opening file for writing.\n";
		return;
	}

	// Write user data to the file
	outfile << newUser.username << " " << newUser.password << "\n";

	// Close the file
	outfile.close();

	cout << "User registered successfully.\n";
}

// Function to display all registered users from the file
void displayRegisteredUsers() {
	ifstream infile("users.txt");
	string username, password;
	vector<User> users;

	if (!infile) {
		cerr << "Error opening file for reading.\n";
		return;
	}

	while (infile >> username >> password) {
		User user;
		user.username = username;
		user.password = password;
		users.push_back(user);
	}

	// Display registered users
	cout << "\nRegistered Users:\n";
	for (const auto& user : users) {
		cout << "Username: " << user.username << "\n";
		cout << "Password: " << user.password << "\n\n";
	}

	infile.close();
}

int main() {
	int choice;

	do {
		cout << "\nUser Registration System\n";
		cout << "1. Register a new user\n";
		cout << "2. Display registered users\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			registerUser();
			break;
		case 2:
			displayRegisteredUsers();
			break;
		case 3:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Please enter again.\n";
			break;
		}
	} while (choice != 3);

	return 0;
}
