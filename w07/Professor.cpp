/*
Name: Sahil Hareshbhai Patel
Email: shpatel27@myseneca.ca
Student ID: 173793225
Date: 11/16/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include "Professor.h"
#include "Utils.h"
#include <iostream>
namespace seneca {

    double Professor::devPay() const {
        return salary() * 0.01 * numberOfSections;
    }

    Professor::Professor(const char* name, const char* subject, const int numberOfSection, size_t employeeNo, double salary)
        : Employee(name, employeeNo, salary) {
        numberOfSections = numberOfSection;
        ut.alocpy(subjectName, subject);
    }

    Professor::~Professor() {
        delete[] subjectName;
    }


    std::istream& Professor::read(std::istream& istr) {
        char buffer[1024]{};
        Employee::read(istr);
        istr.ignore();
        istr.getline(buffer, 1024, ',');
        if (istr) ut.alocpy(subjectName, buffer);
        istr >> numberOfSections;
        return istr;
    }

    std::ostream& Professor::write(std::ostream& ostr) const {
        char subject[21]{};
        if (subjectName) ut.strcpy(subject, subjectName, 20);
        Employee::write(ostr);
        ostr << " ";
        ostr.width(20);
        ostr.setf(std::ios::left);
        ostr << subject << " | ";
        ostr.unsetf(std::ios::left);
        ostr.width(5);
        ostr.setf(std::ios::right);
        ostr << numberOfSections << " | ";
        ostr.fill(' ');
        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr.width(8);
        ostr << devPay() << " |";
        ostr.unsetf(std::ios::right);

        return ostr;
    }

    std::ostream& Professor::title(std::ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject     | Sec # | $Dev Pay |";
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const Professor& prof) {
        return prof.write(os);
    }

    std::istream& operator>>(std::istream& is, Professor& prof) {
        return prof.read(is);
    }

}