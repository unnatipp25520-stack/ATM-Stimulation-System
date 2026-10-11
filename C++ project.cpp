#include <iostream>
using namespace std;

// Function to display ATM menu
void displayMenu()
{
    cout << "\n====================================\n";
    cout << "        ATM SIMULATION SYSTEM       \n";
    cout << "====================================\n";
    cout << "1. Check Balance\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Deposit Money\n";
    cout << "4. Change PIN\n";
    cout << "5. Exit\n";
    cout << "====================================\n";
}

// Function to check balance
void checkBalance(double balance)
{
    cout << "\nYour current balance is: Rs. " << balance << endl;
}

// Function to withdraw money
double withdrawMoney(double balance)
{
    double amount;

    cout << "\nEnter amount to withdraw: Rs. ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount! Please enter a positive amount.\n";
    }
    else if (amount > balance)
    {
        cout << "Insufficient balance!\n";
    }
    else
    {
        balance = balance - amount;

        cout << "Please collect your cash.\n";
        cout << "Withdrawal successful!\n";
        cout << "Remaining balance: Rs. " << balance << endl;
    }

    return balance;
}

// Function to deposit money
double depositMoney(double balance)
{
    double amount;

    cout << "\nEnter amount to deposit: Rs. ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount! Please enter a positive amount.\n";
    }
    else
    {
        balance = balance + amount;

        cout << "Deposit successful!\n";
        cout << "Updated balance: Rs. " << balance << endl;
    }

    return balance;
}

// Function to change PIN
int changePIN(int pin)
{
    int oldPIN;
    int newPIN;
    int confirmPIN;

    cout << "\nEnter your current PIN: ";
    cin >> oldPIN;

    if (oldPIN != pin)
    {
        cout << "Incorrect current PIN!\n";
        return pin;
    }

    cout << "Enter new 4-digit PIN: ";
    cin >> newPIN;

    if (newPIN < 1000 || newPIN > 9999)
    {
        cout << "PIN must contain exactly 4 digits.\n";
        return pin;
    }

    cout << "Confirm new PIN: ";
    cin >> confirmPIN;

    if (newPIN != confirmPIN)
    {
        cout << "PIN confirmation does not match!\n";
        return pin;
    }

    pin = newPIN;

    cout << "PIN changed successfully!\n";

    return pin;
}

int main()
{
    int pin = 1234;
    int enteredPIN;
    int attempts = 0;
    int choice;

    double balance = 10000;

    cout << "====================================\n";
    cout << "         WELCOME TO ATM             \n";
    cout << "====================================\n";

    // PIN verification
    while (attempts < 3)
    {
        cout << "\nEnter your 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == pin)
        {
            cout << "\nPIN verified successfully!\n";
            break;
        }
        else
        {
            attempts++;

            cout << "Incorrect PIN!\n";
            cout << "Attempts remaining: " << 3 - attempts << endl;
        }
    }

    // Block account after 3 wrong attempts
    if (attempts == 3)
    {
        cout << "\nToo many incorrect attempts.\n";
        cout << "Your account has been temporarily blocked.\n";
        cout << "Thank you for using our ATM.\n";

        return 0;
    }
    // ATM operations
    do
    {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = withdrawMoney(balance);
                break;

            case 3:
                balance = depositMoney(balance);
                break;

            case 4:
                pin = changePIN(pin);
                break;

            case 5:
                cout << "\nThank you for using our ATM!\n";
                cout << "Please collect your card.\n";
                cout << "Have a nice day!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
                cout << "Please select a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}
