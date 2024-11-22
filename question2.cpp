#include <iostream>
using namespace std;
#include <fstream>

int main()
{
    const double DISCOUNT_THRESHOLD = 200;
    const double DISCOUNT_RATE = 0.05;
    bool running;

    // opening text file
    ofstream myFile;
    myFile.open("shoppingCart.txt");

    // user name
    string userName;
    cout << "Welcome to Bulle Furniture. \nPlease enter your name: " << endl;
    cin >> userName;

    // writing to the text file
    myFile << "Customer Name: " << userName << endl;

    // outputting predefine list of items
    int totalItems = 7;
    string items[] = {"Bed", "Chair", "Desk", "Shelves", "Bookshelf", "Door", "Lamp"};
    double price[] = {100.00, 50.00, 300.00, 68.00, 120.00, 400.00, 99.00};

    // printing out store items
    cout << "\nThese are the items we sell: \n";
    for (int i = 0; i < totalItems; i++)
    {
        cout << i + 1 << ".";
        cout << items[i];
        cout << "--R" << price[i];
        cout << "\n";
    }

    int itemNumber, quantity, totalOrder;
    double totalCost = 0.00;

    cout << "\nHow many total orders will you make?";
    cin >> totalOrder;

    // handling the item selction
    for (int i = 0; i < totalOrder; i++)
    {
        double orderTotalCost = 0.00;
        do
        {
            cout << "\nEnter the number attached to the item you'd like to order (1-7): ";
            cin >> itemNumber;

            if (itemNumber < 1 || itemNumber > totalItems)
            {
                cout << "We don't sell that item. Please choose a valid item number between 1 and " << totalItems << ".\n";
            }
        } while (itemNumber < 1 || itemNumber > totalItems);

        cout << "Enter the quantity for " << items[itemNumber - 1] << ": ";
        cin >> quantity;

        // Calculating the total cost
        orderTotalCost = price[itemNumber - 1] * quantity;

        cout << "Order Cost: R"
             << orderTotalCost;
        totalCost = totalCost + orderTotalCost;

        // write customer order to text file
        myFile << items[itemNumber - 1] << " - Quantity: " << quantity << " - Price: R" << orderTotalCost << endl;
    }
    totalCost = totalCost;
    cout << "\n \n Total cost: R" << totalCost;

    // calculating discount
    if (totalCost > DISCOUNT_THRESHOLD)
    {
        double finalCost = totalCost - (totalCost * DISCOUNT_RATE);
        cout << "\n \nA DISCOUNT HAS BEEN APPLIED!!!!";
        cout << "\nYour final bill is: R" << finalCost;
        // writing costs to the txt file
        myFile << "\nThe total cost before the discount: R" << totalCost << endl;
        myFile << "Discount was applied" << endl;
        myFile << "The final cost after the discount: R" << finalCost << endl;
    }
    else
    {
        cout << "\n \nYour final bill is: R" << totalCost;
        myFile << "The final cost is: R" << totalCost << endl;
    }
    return 0;
}
