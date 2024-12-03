#include <iostream>
using namespace std;

int main() {
    int balance = 1000;  // Initial balance
    int option;          // User's menu option
    int amount;          // Amount for deposit/withdrawal
    int pin = 1234;      // Predefined PIN for user authentication
    int enteredPin;      // To store the PIN entered by the user

    // Ask for PIN authentication before accessing the ATM menu
    cout << "Enter your PIN to access the ATM: ";
    cin >> enteredPin;

    // Check if the entered PIN matches the predefined PIN
    if (enteredPin == pin) {
        cout << "\nPIN is correct! Access granted." << endl;

        // Main loop for ATM operations
        do {
            // Display ATM Menu
            cout << "\n------------------------" << endl;
            cout << "         ATM Menu       " << endl;
            cout << "------------------------" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl;
            cout << "------------------------" << endl;
            cout << "Choose an option: ";
            cin >> option;

            // Handling user choices using a switch statement
            switch (option) {
                case 1:  // Check Balance
                    cout << "\nYour balance is: Rs." << balance << endl;
                    break;

                case 2:  // Deposit Money
                    cout << "\nEnter amount to deposit: Rs.";
                    cin >> amount;

                    // Ensure amount is positive before adding to balance
                    if (amount > 0) {
                        balance += amount;
                        cout << "You have successfully deposited Rs." << amount << endl;
                        cout << "New balance is: Rs." << balance << endl;
                    } else {
                        cout << "Invalid amount! Deposit amount must be positive." << endl;
                    }
                    break;

                case 3:  // Withdraw Money
                    cout << "\nEnter amount to withdraw: Rs.";
                    cin >> amount;

                    // Check if the withdrawal amount is valid
                    if (amount > 0 && amount <= balance) {
                        balance -= amount;
                        cout << "You have successfully withdrawn Rs." << amount << endl;
                        cout << "Remaining balance is: Rs." << balance << endl;
                    } else if (amount > balance) {
                        cout << "Insufficient balance! You only have Rs." << balance << " available." << endl;
                    } else {
                        cout << "Invalid amount! Withdrawal amount must be positive." << endl;
                    }
                    break;

                case 4:  // Exit
                    cout << "\nThank you for using the ATM. Goodbye!" << endl;
                    break;

                default:  // Invalid option
                    cout << "Invalid option. Please try again." << endl;
            }

            // Additional line for readability between operations
            cout << "\n------------------------" << endl;

        } while (option != 4);  // Loop until the user chooses to exit
    } else {
        // If the PIN entered is incorrect
        cout << "\nIncorrect PIN! Access denied." << endl;
    }

    return 0;
}
