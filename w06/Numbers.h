/*/////////////////////////////////////////////////////////////////////////
						 OOP Workshop - #6 (P1)
Full Name  : Aaryan Shukla
Student ID#: 166636233
Email      : ashukla20@myseneca.ca
Section    : NDD
Date  	   : 03/11/2024
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>

namespace seneca {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty() const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
        int numberCount() const;
    public:
        Numbers();
        Numbers(const char* filename);
        ~Numbers();
        double average() const;
        double max() const;
        double min() const;
        Numbers(const Numbers& other);
        Numbers& operator=(const Numbers& other);
        bool load();
        void save();
        Numbers& operator+=(double value);
        std::ostream& display(std::ostream& ostr) const;
        friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
        friend std::istream& operator>>(std::istream& istr, Numbers& N);
    };
}
#endif // !SENECA_NUMBERS_H_
