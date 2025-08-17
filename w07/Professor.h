/*
Name: Sahil Hareshbhai Patel
Email: shpatel27@myseneca.ca
Student ID: 173793225
Date: 11/16/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Employee.h"
#include "Utils.h"
#include <iostream>

namespace seneca {

    class Professor : Employee {
        char* subjectName{};
        int numberOfSections;
    protected:
        double devPay() const;

    public:
        Professor() = default;
        Professor(const char* name, const char* subject, const int numberOfSection, size_t employeeNo, double salary);
        ~Professor();

        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& title(std::ostream& ostr = std::cout) const;

    };

    std::ostream& operator<<(std::ostream& os, const Professor& prof);
    std::istream& operator>>(std::istream& is, Professor& prof);
}

#endif // PROFESSOR_H