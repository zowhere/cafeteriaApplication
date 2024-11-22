#include <iostream>
#include <string>
using namespace std;
#include <fstream>

const double DISCOUNT_RATE = 0.10;
const double DISCOUNT_THRESHOLD = 100.00;

const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;

// functions
void displayMenu();
double getItemPrice(int item);

void displayMenu()
{
    cout << "\n"
         << endl;
    cout << "Cafeteria Menu:" << endl;
    cout << "1. Coffee - R15.00" << endl;
    cout << "2. Sandwich - R30.00" << endl;
    cout << "3. Salad - R25.00" << endl;
    cout << "4. Juice - R10.00" << endl;
    cout << "5. Muffin - R20.00" << endl;
    cout << "6. Pizza Slice - R35.00" << endl;
    cout << "7. Soup - R18.00" << endl;
    cout << "8. Burger - R40.00" << endl;
}

double getItemPrice(int item)
{
    switch (item)
    {
    case 1:
        return COFFEE_PRICE;
    case 2:
        return SANDWICH_PRICE;
    case 3:
        return SALAD_PRICE;
    case 4:
        return JUICE_PRICE;
    case 5:
        return MUFFIN_PRICE;
    case 6:
        return PIZZA_PRICE;
    case 7:
        return SOUP_PRICE;
    case 8:
        return BURGER_PRICE;
    default:
        return 0.00;
    }
}

int main()
{
    string userName, userSurname;
    int amount = 0;
    double totalBill = 0.00;
    double price = 0.00;

    // Prompt user for their name
    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter your surname: ";
    cin >> userSurname;

    // Display the menu
    displayMenu();
    cout << "\nHow many items would you like to order? (up to 8): ";
    cin >> amount;

    while (amount < 1 || amount > 8)
    {
        cout << "Please enter a number between 1 and 8." << endl;
        cin >> amount;
    }

    for (int i = 1; i <= amount; i++)
    {
        int itemNumber;

        // user selects menu number to place order. for example to order coffee user should say 1
        do
        {
            cout << "Select item " << i << " (1-8): ";
            cin >> itemNumber;

            if (itemNumber < 1 || itemNumber > 8)
            {

                cout << "Please select a number on the menu(1-8). Invalid choice" << endl;
                i--;
            }
        } while (amount < 1 || amount > 8);

        price = getItemPrice(itemNumber);
        totalBill = totalBill + price;
    }

    if (totalBill > DISCOUNT_THRESHOLD)
    {
        totalBill = totalBill - (totalBill * DISCOUNT_RATE);
        cout << "A 10 percent discount was applied" << endl;
    }
    else
    {
        cout << "No discount was applied" << endl;
    }

    // Output the total bill

    cout << "Final bill: R" << totalBill << endl;

    // writing to a text file CafeteriaBill.txt
    ofstream myFile;
    myFile.open("CafeteriaBill.txt");

    if (myFile.is_open())
    {
        myFile << "Customer Name: " << userName << " " << userSurname << endl;
        myFile << "Total Bill: R" << totalBill << endl;
        myFile.close();
        cout << "The bill has been written to CafeteriaBill.txt" << endl;
    }
    else
    {
        cout << "Error opening the file for writing!" << endl; // message if file does not open
    }

    return 0;
}
