/*/////////////////////////////////////////////////////////////////////////
						 OOP Workshop - #6 (P1)
Full Name  : Aaryan Shukla
Student ID#: 166636233
Email      : ashukla20@myseneca.ca
Section    : NDD
Date  	   : 03/11/2024
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include <iomanip>
using namespace std;

namespace seneca {

    // Default constructor initializing to an empty state and setting m_isOriginal to false
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    // Constructor that takes a filename, loads data if the file is valid, and sorts the numbers
    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;  // Marks this instance as the original one
        setFilename(filename); // Set filename for this object
        m_numCount = numberCount(); // Counts numbers in file

        // Loads data only if file has numbers; otherwise resets to empty state
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort(); // Sorts the loaded numbers
        }
    }

    // Checks if the object is in an empty state
    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    // Sets the object to an empty state, initializing members
    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    // Allocates memory for the filename and copies it
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    // Sorts the array of numbers in ascending order using bubble sort
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    // Returns the average of numbers if not empty
    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    // Returns the smallest number in the array if not empty
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    // Returns the largest number in the array if not empty
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    // Destructor to save data if the object is original, and releases allocated memory
    Numbers::~Numbers() {
        if (m_isOriginal) save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    // Copy constructor that performs a deep copy and marks the copy as non-original
    Numbers::Numbers(const Numbers& other) {
        setEmpty();
        m_isOriginal = false;
        m_numbers = new double[other.m_numCount];
        m_numCount = other.m_numCount;
        for (int i = 0; i < m_numCount; ++i) {
            m_numbers[i] = other.m_numbers[i];
        }
    }

    // Assignment operator that performs a deep copy
    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) { // Self-assignment check
            delete[] m_numbers;
            m_numbers = new double[other.m_numCount];
            m_numCount = other.m_numCount;
            for (int i = 0; i < m_numCount; ++i) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
        return *this;
    }

    // Counts the number of newline characters to determine number of numbers in the file
    int Numbers::numberCount() const {
        int count = 0;
        std::ifstream file(m_filename);
        if (file) {
            char c;
            while (file.get(c)) {
                if (c == '\n') count++;
            }
        }
        return count;
    }

    // Loads numbers from the file into m_numbers if the count matches, otherwise resets to empty
    bool Numbers::load() {
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            std::ifstream file(m_filename);
            if (file) {
                int i = 0;
                while (file >> m_numbers[i] && i < m_numCount) {
                    i++;
                }
                if (i == m_numCount) { // Check if loading was successful
                    return true;
                }
            }
            delete[] m_numbers;
            setEmpty();
        }
        return false;
    }

    // Saves the sorted numbers to the file if the object is original
    void Numbers::save() {
        if (m_isOriginal && m_numbers != nullptr) {
            std::ofstream file(m_filename);
            if (file) {
                for (int i = 0; i < m_numCount; i++) {
                    file << m_numbers[i] << std::endl;
                }
            }
        }
    }

    // Adds a new value to the numbers array, sorts, and updates the count
    Numbers& Numbers::operator+=(double value) {
        if (m_numbers != nullptr) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = value; // Add new value
            delete[] m_numbers;
            m_numbers = temp;  
            m_numCount++;
            sort(); // Sort after adding new value
        }
        return *this;
    }

    // Displays the numbers, filename, statistics, or empty message if no numbers are present
    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << std::fixed << std::setprecision(2);
            ostr << "=========================" << std::endl;
            ostr << (m_isOriginal ? m_filename : "*** COPY ***") << std::endl;
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];
                if (i < m_numCount - 1) ostr << ", ";
            }
            ostr << std::endl;
            ostr << "-------------------------" << std::endl;
            ostr << "Total of " << m_numCount << " number(s)" << std::endl;
            ostr << "Largest number:  " << max() << std::endl;
            ostr << "Smallest number: " << min() << std::endl;
            ostr << "Average:         " << average() << std::endl;
            ostr << "=========================";
        }
        return ostr;
    }

    // Overloaded insertion operator to display Numbers object
    std::ostream& operator<<(std::ostream& os, const Numbers& N) {
        return N.display(os);
    }

    // Overloaded extraction operator to add a new number to Numbers object
    std::istream& operator>>(std::istream& istr, Numbers& N) {
        double value;
        if (istr >> value) {
            N += value;
        }
        return istr;
    }

}
