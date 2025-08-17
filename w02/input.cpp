/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)

Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NDD
Date       : 18-09-2024

 Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
    int getInt() {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }

    int getInt(int minVal, int maxVal) {
        int num = 0;
        bool done = false;
        do {
            num = getInt();  // Reuse the foolproof integer entry function
            if (num < minVal || num > maxVal) {
                cout << "Invalid value, [" << minVal << "<ENTRY<" << maxVal << "]\n> ";
            }
            else {
                done = true;
            }
        } while (!done);
        return num;
    }

    bool getInt(int& num, int minVal, int maxVal) {
        num = getInt();
        if (num < minVal || num > maxVal) {
            return false;  // Invalid value
        }
        return true;  // Valid value
    }
}


