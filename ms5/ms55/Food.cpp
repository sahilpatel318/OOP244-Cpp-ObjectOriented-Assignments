
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Food.h"
#include "Utils.h"

namespace seneca {
    Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}

    Food::Food(const Food& src) : Billable(src) {
        m_ordered = src.m_ordered;
        m_child = src.m_child;
        ut.alocpy(m_customize, src.m_customize);
    }

    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_ordered = src.m_ordered;
            m_child = src.m_child;
            ut.alocpy(m_customize, src.m_customize);
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }

    std::ostream& Food::print(std::ostream& ostr) const {
        const char* name = (const char*)*this;
        if (name) {
            ostr << name;
            for (int i = ut.strlen(name); i < 28; i++) {
                ostr << '.';
            }
            if (ordered()) {
                ostr << (m_child ? "Child" : "Adult");
            }
            else {
                ostr << ".....";
            }
            ostr << " ";
            char priceStr[10];
            sprintf(priceStr, "%6.2f", price());
            ostr << priceStr;
            if (m_customize && &ostr == &std::cout) {
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
        int choice = ut.getInt(0, 2);
        if (choice != 0) {
            m_ordered = true;
            m_child = (choice == 2);

            std::cout << "Special instructions\n> ";
            char* temp = nullptr;
            ut.read(temp, std::cin);

            delete[] m_customize;
            m_customize = nullptr;

            if (temp) {
                ut.alocpy(m_customize, temp);
            }
            delete[] temp;
        }
        else {
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return m_ordered;
    }

    bool Food::ordered() const {
        return m_ordered;
    }

    std::ifstream& Food::read(std::ifstream& file) {
        char name[1024]{};
        double priceVal;
        file.getline(name, 1024, ',');
        if (file) {
            file >> priceVal;
            file.ignore(1000, '\n');
            if (file) {
                this->name(name);
                Billable::price(priceVal);
                m_ordered = false;
                m_child = false;
                delete[] m_customize;
                m_customize = nullptr;
            }
        }
        return file;
    }

    double Food::price() const {
        double basePrice = Billable::price();
        return (ordered() && m_child) ? basePrice * 0.5 : basePrice;
    }
}