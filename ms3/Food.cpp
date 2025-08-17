/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 22/11/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Food.h"
#include "Utils.h"
#include <fstream>
using namespace std;

namespace seneca {
    Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}


    Food::~Food() {
        delete[] m_customize;
    }

    Food::Food(const Food& other) : Billable(other) {
        m_child = other.m_child;
        m_ordered = other.m_ordered;
       
        ut.alocpy(m_customize, other.m_customize);
    }

    Food& Food::operator=(const Food& other) {
        if (this != &other) {

            Billable::operator=(other);
            m_ordered = other.m_ordered;

            m_child = other.m_child;
            ut.alocpy(m_customize, other.m_customize);
        }
        return *this;
    }

 

    std::ostream& Food::print(std::ostream& ostr) const {
        const char* Fname = (const char*)*this;
        if (Fname) {
            ostr << Fname;
            for (int i = ut.strlen(Fname); i < 28; i++) {
                ostr << '.';
            }


            if (ordered()) {
                ostr << (m_child ? "Child" : "Adult");
            }



            else {
                ostr << ".....";
            }
            ostr << " ";
            char strPrice[10];
            sprintf(strPrice, "%6.2f", price());


            ostr << strPrice;
            if (m_customize && &ostr == &cout) {
                ostr << " >> " << m_customize;
            }
        }
        return ostr;
    }


    bool Food::order() {
        std::cout << "         Food Size Selection\n"
            << "          1- Adult\n"
            << "          2- Child\n"
            << "          0- Back\n"
            << "         > ";
        int Userchoice = ut.getInt(0, 2);
        if (Userchoice != 0) {
            m_ordered = true;
            m_child = (Userchoice == 2);

            cout << "Special instructions\n> ";
            char* temp{ nullptr };
            ut.read(temp, cin);

            delete[] m_customize;
            m_customize = nullptr;

            if (temp && temp[0]) {
                ut.alocpy(m_customize, temp);
            }
            delete[] temp;
        }
        else {

            m_ordered = false;

            m_child = false;
            delete[] m_customize;
            
        }
        return m_ordered;
    }

    bool Food::ordered() const {

        return m_ordered;
    }


    double Food::price() const {
        double base = Billable::price();
        return (ordered() && m_child) ? base * 0.5 : base;
    }

    ifstream& Food::read(ifstream& file) {
        char fname[1024]{};

        double priceValue;

        file.getline(fname, 1024, ',');
        if (file) {

            file >> priceValue;
            file.ignore(1000, '\n');

            if (file) {
                this->name(fname);

                Billable::price(priceValue);

                m_child = false;

                m_ordered = false;
                delete[] m_customize;
                
            }
        }
        return file;
    }

    
}

