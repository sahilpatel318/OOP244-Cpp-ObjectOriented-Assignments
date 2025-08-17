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
#include "dma.h"
using namespace std;
namespace seneca {
    void reverse() {
        int count = 0;
        cout << "Enter the number of double values:\n> ";
        cin >> count;

        double* arr = new double[count];  // Dynamically allocate array
        for (int i = 0; i < count; i++) {
            cout << (i + 1) << "> ";
            cin >> arr[i];
        }

        // Print in reverse order
        for (int i = count - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }

        delete[] arr;  // Deallocate memory
    }

    Contact* getContact() {
        Contact* contact = new Contact;
        cout << "Name: ";
        cin >> contact->m_name;
        cout << "Last name: ";
        cin >> contact->m_lastname;
        cout << "Phone number: ";
        cin >> contact->m_phoneNumber;
        return contact;
    }

    void display(const Contact& C) {
        cout << C.m_name << " " << C.m_lastname << ", +" << C.m_phoneNumber << endl;
    }

    void deallocate(Contact* C) {
        delete C;  // Deallocate memory
    }

    void setEmpty(Contact& C) {
        C.m_name[0] = '\0';  // Set name to empty string
        C.m_lastname[0] = '\0';  // Set last name to empty string
        C.m_phoneNumber = 0;  // Set phone number to zero
    }
}








