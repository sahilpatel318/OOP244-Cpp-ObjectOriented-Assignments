/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"
#include <cstring>

namespace seneca {

    class LblShape : public Shape {
        // Dynamically allocated label for the shape
        char* mLabel = nullptr;
    protected:
        // Returns the label string for derived classes to access
        const char* label() const;
    public:
        // Default constructor
        LblShape() = default;

        // Constructor with label initialization
        LblShape(const char* label);

        // Copy constructor and assignment operator are deleted to prevent copying
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

        // Reads label specifications from input stream
        void getSpecs(std::istream&) override;

        // Destructor to release dynamically allocated memory
        ~LblShape();
    };
}

#endif // !SENECA_LABELEDSHAPE_H