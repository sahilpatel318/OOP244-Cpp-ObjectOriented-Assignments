/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.coo
// Version 1.0
// Date 2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {

    // Constructor
    Transcript::Transcript(const char* name, unsigned int studentNumber) {
        ut.alocpy(m_studentName, name);
        m_studentNumber = studentNumber;
    }

    // Copy Constructor
    Transcript::Transcript(const Transcript& other) : Marks(other) {
        ut.alocpy(m_studentName, other.m_studentName);
        m_studentNumber = other.m_studentNumber;
    }

    // Copy Assignment Operator
    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) { // Avoid self-assignment
            Marks::operator=(other); // Copy base class attributes
            ut.alocpy(m_studentName, other.m_studentName); // Copy student name
            m_studentNumber = other.m_studentNumber; // Copy student number
        }
        return *this;
    }

    // Destructor
    Transcript::~Transcript() {
        delete[] m_studentName; // Free dynamically allocated memory
    }

    // Override display function
    std::ostream& Transcript::display(std::ostream& ostr) const {
        ostr << m_studentName << " (" << m_studentNumber << ")" << endl;
        ostr << "--------------------------------------------------------------------------" << endl;
        Marks::display(ostr); // Display marks using base class function
        return ostr;
    }
}
	