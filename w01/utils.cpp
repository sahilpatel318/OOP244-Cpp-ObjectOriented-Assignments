/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1 (P1)

Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NDD
Date       : 11-09-2024

 Authenticity Declaration:

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS  // Disable warnings for unsafe functions in Visual Studio
#include "utils.h"  // Include utility function declarations
#include <iostream> // For input/output operations

using namespace std;

namespace seneca {

    // flushes the keyboard
    void flushkeys() {
        while (cin.get() != '\n');  // Keep reading characters from the input buffer until a newline is found
    }

    // returns true if user enter y or Y
    bool yes() {
        char ch = cin.get();  // Get a single character from the user
        flushkeys();  // Flush the remaining characters in the input buffer (if any)
        return ch == 'y' || ch == 'Y';  // Return true if the character is 'y' or 'Y', otherwise false
    }

    // copies src Cstring to des and converts all characters to lowercase
    // at the same time.
    void toLowerCase(char* des, const char* src) {
        int i = 0;
        while (src[i]) {  // Loop through each character in the source string until the null terminator is found
            des[i] = src[i];  // Copy the character from src to des
            if (des[i] >= 'A' && des[i] <= 'Z') {  // If the character is an uppercase letter
                des[i] += ('a' - 'A');  // Convert it to lowercase by adding the difference between 'a' and 'A'
            }
            i++;  // Move to the next character
        }
        des[i] = 0;  // Null-terminate the destination string after the last character
    }
}
