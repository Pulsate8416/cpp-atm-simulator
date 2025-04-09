#include <iostream>
using namespace std;

// Function prototypes
void displayMenu();
void checkBalance(double balance);
void deposit(double &balance, double amount);
void withdraw(double &balance, double amount, double &dWithdrawn);

const double dLIMIT = 1234.0;

int main() {
    double balance = 0.0;
    double dWithdrawn = 0.0; // Tracks the total withdrawn for the day
    int choice;
    double amount;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            deposit(balance, amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw(balance, amount, dWithdrawn);
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "------------------" << endl;
    cout << "---Jeff Davis-----" << endl;
    cout << "----ITSE-1302-----" << endl;
    cout << "Welcome to the ATM" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
    cout << "------------------" << endl;
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << endl;
}

void deposit(double &balance, double amount) {
    if (amount < 0) {
        cout << "Cannot deposit a negative amount." << endl;
    } else {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }
}

void withdraw(double &balance, double amount, double &dWithdrawn) {
    if (amount < 0) {
        cout << "Cannot withdraw a negative amount." << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds." << endl;
    } else if (dWithdrawn + amount > dLIMIT) {
        cout << "Withdrawal denied. Daily limit of $" << dLIMIT << " exceeded." << endl;
    } else {
        balance -= amount;
        dWithdrawn += amount;
        cout << "Withdrew: $" << amount << endl;
        cout << "Total withdrawn today: $" << dWithdrawn << endl;
    }
}