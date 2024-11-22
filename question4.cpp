#include <iostream>
using namespace std;
#include <string>

// Function declarations
void showMenu();
void depositMoney(double &balance);
void withdraw(double &balance);
void checkBalance(const double &balance);
void createAccount(string &name, int &accNum, float &initialDeposit, double &balance);
void displayAccountDetails(const string &name, const int &accNum, const double &balance);

int main()
{
    double balance = 0.0;
    int choice;
    bool running = true;
    string name;
    int accNum;
    float initialDeposit;
    // 4.6 menu loop for users
    while (running)
    {
        showMenu();
        cout << "Enter your choice (1-6): " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount(name, accNum, initialDeposit, balance);
            break;

        case 2:
            depositMoney(balance);
            break;

        case 3:
            withdraw(balance);
            break;

        case 4:
            checkBalance(balance);
            break;

        case 5:
            displayAccountDetails(name, accNum, balance);
            break;
        case 6:
            cout << "Exiting the system. Goodbye." << endl;
            running = false;
            break;

        default:
            cout << "Invalid option! Please choose again." << endl;
        }
    }
    cout << endl; // Add a line break for better readability
    return 0;
}

// 4.1a Function to create new account
void createAccount(string &name, int &accNum, float &initialDeposit, double &balance)
{

    cout << "Enter your name: ";
    cin >> name;
    getline(cin, name);

    cout << "Enter your account number (6 digits) ";
    cin >> accNum;
    cout << "Enter your initial deposit (must be greater than 0): R";
    cin >> initialDeposit;
    balance = initialDeposit;

    if (balance <= 0)
    {
        cout << "Your initial deposit must be greater than 0. We are setting your balance to 0." << endl;
        balance = 0;
    }
    else
    {
        cout << "Account created successfully! \n";
    }
}

// 4.2 b Function to deposit money
void depositMoney(double &balance)
{

    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount > 0)
    {
        balance = balance + amount;
        cout << "Your deposit was successful! New balance is: R" << balance << endl;
    }
    else
    {
        cout << "Invalid amount! Deposit must be greater than R0." << endl;
    }
}
// 4.3c Function to withdraw money
void withdraw(double &balance)
{
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "Your withdrawal was successful!New balance is: R" << balance << endl;
    }
    else if (amount > balance)
    {
        cout << "Insufficient funds!Balance is: R" << balance << endl;
    }
    else
    {
        cout << "Invalid amount! Please enter a positive number." << endl;
    }
}
// 4.4d function to check balance
void checkBalance(const double &balance)
{
    cout << "Your current balance is: R" << balance << endl;
}
// 4.5e function to display account details
void displayAccountDetails(const string &name, const int &accNum, const double &balance)
{
    cout << "\n"
         << endl;
    cout << "===== Account Details =====" << endl;
    cout << "Account Holder: " << name << endl;
    cout << "Account Number: " << accNum << endl;
    cout << "Current Balance: R" << balance << endl;
    cout << "============================" << endl;
}
// 4.6 function to display banking options
void showMenu()
{
    cout << "====Bank Account Management System ====" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Display Account Details" << endl;
    cout << "6. Exit" << endl;
    cout << "======================" << endl;
}