#include <iostream>
#include <iomanip>

using namespace std;

// Function to print colored text
void printColored(const string& text, const string& color) {
    cout << "\033[" << color << "m" << text << "\033[0m";
}

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Money {
private:
    int cash = 1000;
    int withdraw = 0;
    int deposit = 0;

public:
    void check_balance() {
        cout << "Current balance: $" << cash << endl;
    }

    void money_withdraw() {
        cout << "Enter the amount of cash to withdraw: $";
        cin >> withdraw;
        if (withdraw > cash) {
            printColored("Insufficient funds!", "31"); // Red
        } else {
            cash -= withdraw;
            printColored(to_string(withdraw) + "$ has been withdrawn successfully", "32"); // Green
            cout << "\nAccount Status:" << endl;
            cout << "Remaining: $" << cash << endl;
        }
    }

    void money_deposit() {
        cout << "Enter the amount of cash to deposit: $";
        cin >> deposit;
        cash += deposit;
        printColored(to_string(deposit) + "$ has been deposited successfully", "32"); // Green
        cout << "\nAccount Status:" << endl;
        cout << "Remaining: $" << cash << endl;
    }
};

class Security {
private:
    int pin = 1234;
    int pass = 0;

public:
    int password() {
        for (int i = 1; i <= 5; i++) {
            cout << "Enter Your Pin (1234) to confirm transaction: ";
            cin >> pass;

            if (pass == pin) {
                printColored("Pin verified successfully!", "32"); // Green
                return 1;
            } else {
                printColored("Invalid Pin. Try again.", "31"); // Red
                cout << (5 - i) << " tries remaining." << endl;
            }

            if (i == 5) {
                printColored("Too many failed attempts. Transaction blocked.", "31"); // Red
                return 0;
            }
        }
        return 0;
    }
};

void displayWelcomeScreen() {
    clearScreen();
    
    printColored("WELCOME TO OUR ATM", "33"); // Yellow
    cout << endl;
    
    printColored("_____________________", "32"); // Green
    cout << endl;
    
    printColored("Please insert your card", "36"); // Cyan
    cout << endl;
    
    printColored("Enter your PIN when prompted", "34"); // Blue
    cout << endl;
    
    printColored("_____________________", "32"); // Green
}


void displayMenu() {
    cout << "\nATM Menu:" << endl;
    cout << "1. Withdraw Money" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Check Balance" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    displayWelcomeScreen();

    Security sec;
    Money mon;

    if (!sec.password()) {
        return 0;
    }

    int choice;
    do {
        clearScreen();
        displayWelcomeScreen();
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                mon.money_withdraw();
                break;
            case 2:
                mon.money_deposit();
                break;
            case 3:
                mon.check_balance();
                break;
            case 4:
                printColored("Thank you for using the ATM. Goodbye!", "32"); // Green
                return 0;
            default:
                printColored("Invalid choice. Please try again.", "31"); // Red
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (true);

    return 0;
}
