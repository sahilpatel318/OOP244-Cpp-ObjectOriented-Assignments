
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Drink.h"
#include "Utils.h"

namespace seneca {
    std::ostream& Drink::print(std::ostream& ostr) const {
        const char* name = (const char*)*this;
        if (name) {
            ostr << name;
            for (int i = ut.strlen(name); i < 28; i++) {
                ostr << '.';
            }
            if (ordered()) {
                if (m_size == 'S') ostr << "SML";
                if (m_size == 'M') ostr << "MID";
                if (m_size == 'L') ostr << "LRG";
                if (m_size == 'X') ostr << "XLR";
                ostr << "..";
            }
            else {
                ostr << ".....";
            }
            ostr << " ";
            char priceStr[10];
            sprintf(priceStr, "%6.2f", price());
            ostr << priceStr;
        }
        return ostr;
    }
    bool Drink::order() {
        std::cout << "         Drink Size Selection\n"
            << "          1- Small\n"
            << "          2- Medium\n"
            << "          3- Larg\n"
            << "          4- Extra Large\n"
            << "          0- Back\n"
            << "         > ";
        int choice = ut.getInt(0, 4);
        if (choice == 1) m_size = 'S';
        if (choice == 2) m_size = 'M';
        if (choice == 3) m_size = 'L';
        if (choice == 4) m_size = 'X';
        if (choice == 0) m_size = 0;
        return m_size != 0;
    }

    bool Drink::ordered() const {
        return m_size != 0;
    }

    std::ifstream& Drink::read(std::ifstream& file) {
        char name[1024]{};
        double priceVal;
        file.getline(name, 1024, ',');
        if (file) {
            file >> priceVal;
            file.ignore(1000, '\n');
            if (file) {
                this->name(name);
                Billable::price(priceVal);
                m_size = 0;
            }
        }
        return file;
    }

    double Drink::price() const {
        double basePrice = Billable::price();
        if (!ordered() || m_size == 'L') return basePrice;
        if (m_size == 'S') return basePrice * 0.5;           // 50% of base price
        if (m_size == 'M') return basePrice * 0.75;         // 75% of base price
        if (m_size == 'X') return basePrice * 1.5;          // 150% of base price
        return basePrice;
    }
}