
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


#ifndef SENECA_UTILS_H_   // If not defined, proceed to define the header guard
#define SENECA_UTILS_H_   // Define the header guard for SENECA_UTILS_H_ to avoid multiple inclusions

#ifndef NAMESPACE_UTILS_H  // Another header guard for NAMESPACE_UTILS_H
#define NAMESPACE_UTILS_H  // Define the header guard for NAMESPACE_UTILS_H

// Start of the 'seneca' namespace
namespace seneca {
    
    // Function prototype to clear the input buffer.
    // This function is used to discard any extra input characters left in the buffer.
    void flushkeys();
    
    // Function prototype for a yes/no input checker.
    // Returns true if the user enters 'Y' or 'y', otherwise returns false.
    bool yes();

    // Function prototype to convert a string to lowercase.
    // Takes a source string (src) and copies it to a destination string (des) in all lowercase letters.
    void toLowerCase(char* des, const char* src);

}  // End of the 'seneca' namespace

#endif  // End of NAMESPACE_UTILS_H header guard
#endif // End of SENECA_UTILS_H_ header guard

