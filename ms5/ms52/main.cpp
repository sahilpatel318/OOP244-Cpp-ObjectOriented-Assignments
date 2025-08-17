
#include <iostream>
#include "Menu.h"
#include "Ordering.h"

using namespace seneca;
using namespace std;

void appMain() {
    Menu mainMenu("Seneca Restaurant ", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    Ordering ordering("drinks.csv", "foods.csv");

    if (!ordering) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return;
    }

    bool done = false;
    do {
        size_t selection = mainMenu.select();

        if (selection == 1) {
            Menu orderMenu("Order Menu", "Back to main menu", 1);  
            orderMenu << "Food" << "Drink";

            bool backToMain = false;
            while (!backToMain) {
                size_t orderSelection = orderMenu.select();

                if (orderSelection == 1) {
                    ordering.orderFood();
                }
                else if (orderSelection == 2) {
                    ordering.orderDrink();
                }
                else if (orderSelection == 0) {
                    backToMain = true;
                }
            }
        }
        else if (selection == 2) {
            ordering.printBill(cout);
        }
        else if (selection == 3) {
            ordering.resetBill();
        }
        else if (selection == 4) {
            ordering.listFoods();
        }
        else if (selection == 5) {
            ordering.listDrinks();
        }
        else if (selection == 0) {
            if (ordering.hasUnsavedBill()) {
                Menu confirmMenu("You have bills that are not saved. Are you sure you want to exit?", "No");
                confirmMenu << "Yes";
                if (confirmMenu.select() == 1) {
                    done = true;
                }
            }
            else {
                done = true;
            }
        }
    } while (!done);
}

int main() {
    appMain();
    return 0;
}