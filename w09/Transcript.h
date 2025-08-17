/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.0
// Date 2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name : Gopal Sapkota           Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"

namespace seneca {
    class Transcript : public Marks {
        char* m_studentName{};    // Dynamically allocated student name
        unsigned int m_studentNumber{}; // Student number

    public:
        // Constructor
        Transcript(const char* name, unsigned int studentNumber);

        // Rule of Three
        Transcript(const Transcript& other);            // Copy Constructor
        Transcript& operator=(const Transcript& other); // Copy Assignment Operator
        ~Transcript();                                  // Destructor

        // Override display function
        std::ostream& display(std::ostream& ostr = std::cout) const override;
    };
}
#endif // !SENECA_TRANSCRIPT_H
