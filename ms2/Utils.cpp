#include <iostream>
#include "Utils.h"
using namespace std;

namespace seneca {
    int getInt() {
        int value;
        bool valid = false;

        cout << " ";

        while (!valid) {
            if (cin.peek() == '\n') {
                cout << "You must enter a value: ";
                cin.ignore();
                continue;
            }

            if (!(cin >> value)) {
                cout << "Invalid integer: ";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (cin.get() != '\n') {
                cout << "Only an integer please: ";
                cin.ignore(1000, '\n');
                continue;
            }

            valid = true;
        }
        return value;
    }

    int getInt(int min, int max) {
        int value;
        bool valid = false;
        while (!valid) {
            value = getInt();
            if (value < min || value > max) {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
                continue;
            }
            valid = true;
        }
        return value;
    }
}
