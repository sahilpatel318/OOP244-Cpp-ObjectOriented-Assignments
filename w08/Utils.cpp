/***********************************************************************
// OOP244 Project/workshop, Utils Module
//
// File	Utils.h
// Version 0.2
// Date 2024-9-11
// started by Fardad
// Description
// utility function to be used in the project or workshops
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 0.2             11-6            added 3 argument strcpy
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Utils.h"

using namespace std;

namespace seneca {


    Utils ut;

    // It returns a pointer to the allocated memory containing the copied string.
    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    // It frees any previously allocated memory of the destination before copying.
    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des; 
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1]; 
            strcpy(des, src);                
        }
        return des;
    }

    // This is a basic copy function that does not check for buffer overflow.
    char* Utils::strcpy(char* des, const char* src) const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0); // Null-terminate
        return des;
    }

    // The function stops after copying 'len' characters or the null terminator from the source.
    char* Utils::strcpy(char* des, const char* src, int len) const {
        int i;
        for (i = 0; i < len && src[i]; i++) des[i] = src[i];
        des[i] = 0;
        return des;
    }

    // A simple implementation to count the characters manually.
    int Utils::strlen(const char* str) const {
        int len;
        for (len = 0; str[len]; len++); // Count until null terminator
        return len;
    }

    // Checks if the given character is a whitespace character (space, tab, newline, etc.).
    bool Utils::isspace(char ch) const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    // Checks if the entire C-string is whitespace. Returns true if all characters are whitespace.
    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) { 
            cstring++;
        }
        return cstring && *cstring == 0; 
    }

}
