#include <iostream>
#include <string>
using namespace std;
#include <fstream>

void displayMenu()
{
    cout << "\nCafeteria Menu:" << endl;
    cout << "1. Coffee - R15.00" << endl;
    cout << "2. Sandwich - R30.00" << endl;
    cout << "3. Salad - R25.00" << endl;
    cout << "4. Juice - R10.00" << endl;
    cout << "5. Muffin - R20.00" << endl;
    cout << "6. Pizza Slice - R35.00" << endl;
    cout << "7. Soup - R18.00" << endl;
    cout << "8. Burger - R40.00" << endl;
}

int getItemPrice(int item)
{
    switch (item)
    {
    case 1:
        return 15;
    case 2:
        return 30;
    case 3:
        return 25;
    case 4:
        return 10;
    case 5:
        return 20;
    case 6:
        return 35;
    case 7:
        return 18;
    case 8:
        return 40;
    default:
        return 0;
    }
}

int main()
{
    string userName, userSurname;
    int amount, totalBill = 0;

    // Prompt user for their name
    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter your surname: ";
    cin >> userSurname;

    // Display the menu
    displayMenu();
    cout << "\nHow many items would you like to order? (up to 8): ";
    cin >> amount;

    if (amount < 1 || amount > 8)
    {
        cout << "Please enter a number between 1 and 8." << endl;
        return 1;
    }

    for (int i = 1; i <= amount; i++)
    {
        int itemNumber;

        // user selects menu number to place order. for example to order coffee user should say 1
        cout << "Enter the item number from the menu to place order " << i << " (1-8) " << endl;
        cin >> itemNumber;

        if (itemNumber >= 1 && itemNumber <= 8)
        {
            int price = getItemPrice(itemNumber);
            totalBill += price;

            if (totalBill > 100)
            {
                totalBill = totalBill - (totalBill * 0.1);
                cout << "A 10 percent discount was applied" << endl;
            }
        }
        else
        {
            cout << "This item is not on the menu." << i << endl;
        }
    }

    // Output the total bill

    cout << " No discount applied" << endl; // come back and use constants

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
