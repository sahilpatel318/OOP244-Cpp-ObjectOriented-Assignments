/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

namespace seneca {

    class Line : public LblShape {
        // Length of the line
        int mLength{};
    public:
        // Default constructor
        Line() = default;

        // Constructor that initializes label and length
        Line(const char* label, int length);

        // Draws the line, using the label and length
        void draw(std::ostream&) const;

        // Gets specifications of the line (label and length) from input
        void getSpecs(std::istream&);
    };

}

#endif // !SENECA_LINE_H