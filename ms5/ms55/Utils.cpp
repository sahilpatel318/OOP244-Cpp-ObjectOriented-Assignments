/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.6
// Sahil 
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------

// Sahil          11-20           makeBillFileName
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"

namespace seneca {
    Utils ut;
    bool debug = false;
    const size_t AllocationBlockSize = 128;

    int Utils::getInt() const {
        int value{};
        char after;

        if (std::cin.peek() == '\n') {
            std::cin.ignore();
            std::cout << "You must enter a value: ";
            return getInt();
        }

        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid integer: ";
            return getInt();
        }

        if (std::cin.get(after) && after != '\n') {
            std::cin.ignore(1000, '\n');
            std::cout << "Only an integer please: ";
            return getInt();
        }

        return value;
    }

    int Utils::getInt(int min, int max) const {
        int value = getInt();

        if (value < min || value > max) {
            std::cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
            return getInt(min, max);
        }

        return value;
    }

    int Utils::getint(int defaultValue) const {
        int value;
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            value = defaultValue;
        }
        else {
            std::cin.ignore(1000, '\n');
        }
        return value;
    }

    char* Utils::alocpy(const char* src) const {
        char* des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::strcpy(char* des, const char* src) const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    char* Utils::strcpy(char* des, const char* src, int len) const {
        int i;
        for (i = 0; i < len && src[i]; i++) des[i] = src[i];
        des[i] = 0;
        return des;
    }

    char* Utils::strncpy(char* des, const char* src, int len) const {
        int i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i];
        return des;
    }

    int Utils::strlen(const char* str) const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch) const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    char* Utils::read(char*& toRet, std::istream& istr, char delimiter) const {
        delete[] toRet;
        toRet = nullptr;
        char* temp = new char[AllocationBlockSize];
        unsigned int size = AllocationBlockSize;
        unsigned int index = 0;
        char ch;

        // Handle first character
        if (istr.get(ch)) {
            if (ch == delimiter) {  
                delete[] temp;
                return nullptr;
            }
            temp[index++] = ch;
        }

        // Read rest of input
        while (istr.get(ch) && ch != delimiter) {
            if (index + 1 >= size) {
                size += AllocationBlockSize;
                char* newTemp = new char[size];
                strcpy(newTemp, temp);
                delete[] temp;
                temp = newTemp;
            }
            temp[index++] = ch;
        }
        temp[index] = '\0';

        // Only allocate if we have content
        if (index > 0 && !isspace(temp)) {
            toRet = new char[index + 1];
            strcpy(toRet, temp);
        }
        delete[] temp;
        return toRet;
    }

    char* Utils::makeBillFileName(char* filename, size_t billNo) const {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;
        do {
            cnt++;
            temp /= 10;
        } while (temp > 0);
        length = cnt;
        while (billNo > 0) {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }
        if (billFileName[cnt - 1] == '\0') {
            billFileName[--cnt] = '0';
        }
        for (int i = 0; ".txt"[i]; i++) {
            billFileName[length++] = ".txt"[i];
        }
        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
    }

    std::ostream& Utils::print(std::ostream& ostr, const char* cstring, size_t maxlen) const {
        if (cstring) {
            for (size_t i = 0; i < maxlen && cstring[i]; i++) {
                ostr << cstring[i];
            }
        }
        return ostr;
    }
}