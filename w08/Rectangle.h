/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {
    class Rectangle : public LblShape {
        // Width of the rectangle
        int mWidth{};
        // Height of the rectangle
        int  mHeight{};
    public:
        // Default constructor
        Rectangle();

        // Constructor that initializes label, width, and height
        Rectangle(const char* label, int width, int height);

        // Draws the rectangle using the label, width, and height
        void draw(std::ostream&) const;

        // Gets specifications of the rectangle (label, width, height) from input
        void getSpecs(std::istream&);
    };

}

#endif // !SENECA_RECTANGLE_H#pragma once
