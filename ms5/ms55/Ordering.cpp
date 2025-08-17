
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        if (file) {
            ifstream infile(file);
            if (infile.is_open()) {
                char ch;
                while (infile.get(ch)) {
                    if (ch == '\n') count++;
                }
            }
        }
        return count;
    }

    Ordering::Ordering(const char* drinks, const char* foods) :
        m_foods{}, m_drinks{}, m_foodItems{}, m_drinkItems{},
        m_billItems{}, m_billNumber{ 1 } {

        if (drinks && foods) {
            size_t drinkCount = countRecords(drinks);
            size_t foodCount = countRecords(foods);

            ifstream drinkFile(drinks);
            ifstream foodFile(foods);

            if (drinkFile.is_open() && foodFile.is_open()) {
                m_drinks = new Drink[drinkCount];
                m_foods = new Food[foodCount];

                bool success = true;
                size_t i;

                // Read drinks
                for (i = 0; i < drinkCount && drinkFile.good(); i++) {
                    if (!m_drinks[i].read(drinkFile)) {
                        success = false;
                        break;
                    }
                }
                m_drinkItems = i;

                // Read foods if drinks were successful
                if (success) {
                    for (i = 0; i < foodCount && foodFile.good(); i++) {
                        if (!m_foods[i].read(foodFile)) {
                            success = false;
                            break;
                        }
                    }
                    m_foodItems = i;
                }

                if (!success || m_drinkItems != drinkCount || m_foodItems != foodCount) {
                    delete[] m_drinks;
                    delete[] m_foods;
                    m_drinks = nullptr;
                    m_foods = nullptr;
                    m_foodItems = 0;
                    m_drinkItems = 0;
                }
            }
        }
    }

    Ordering::~Ordering() {
        delete[] m_drinks;
        delete[] m_foods;
        for (size_t i = 0; i < m_billItems; i++) {
            delete m_bill[i];
        }
    }

    Ordering::operator bool() const {
        return m_drinks && m_foods;
    }

    size_t Ordering::noOfBillItems() const {
        return m_billItems;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_billItems > 0;
    }

    void Ordering::billTitle(std::ostream& ostr) const {
        ostr << "Bill # ";
        ostr.width(3);
        ostr.fill('0');
        ostr << right << m_billNumber;
        ostr << " =============================" << endl;
    }
    void Ordering::printTotals(std::ostream& ostr, double total) const {
        // Calculate totals in cents to avoid floating point rounding issues
        int totalCents = static_cast<int>(total * 100);
        int taxCents = static_cast<int>(total * Tax * 100);
        int totalWithTaxCents = static_cast<int>((total + total * Tax) * 100 + 0.5);  

        ostr << "                     Total:         "
            << totalCents / 100 << "." << (totalCents % 100 < 10 ? "0" : "") << totalCents % 100 << endl;
        ostr << "                     Tax:           "
            << taxCents / 100 << "." << (taxCents % 100 < 10 ? "0" : "") << taxCents % 100 << endl;
        ostr << "                     Total+Tax:     "
            << totalWithTaxCents / 100 << "." << (totalWithTaxCents % 100 < 10 ? "0" : "") << totalWithTaxCents % 100 << endl;
        ostr << "========================================" << endl;
    }

    void Ordering::listFoods() const {
        cout << "List Of Available Meals" << endl;
        cout << "========================================" << endl;
        for (size_t i = 0; i < m_foodItems; i++) {
            m_foods[i].print() << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::listDrinks() const {
        cout << "List Of Available Drinks" << endl;
        cout << "========================================" << endl;
        for (size_t i = 0; i < m_drinkItems; i++) {
            m_drinks[i].print() << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::orderFood() {
        Menu foodMenu("Food Menu", "Back to Order", 2);
        for (size_t i = 0; i < m_foodItems; i++) {
            foodMenu << (const char*)m_foods[i];
        }

        size_t selection = foodMenu.select();
        if (selection && m_billItems < MaximumNumberOfBillItems) {
            m_bill[m_billItems] = new Food(m_foods[selection - 1]);
            if (m_bill[m_billItems]->order()) {
                m_billItems++;
            }
            else {
                delete m_bill[m_billItems];
            }
        }
    }

    void Ordering::orderDrink() {
        Menu drinkMenu("Drink Menu", "Back to Order", 2);
        for (size_t i = 0; i < m_drinkItems; i++) {
            drinkMenu << (const char*)m_drinks[i];
        }

        size_t selection = drinkMenu.select();
        if (selection && m_billItems < MaximumNumberOfBillItems) {
            m_bill[m_billItems] = new Drink(m_drinks[selection - 1]);
            if (m_bill[m_billItems]->order()) {
                m_billItems++;
            }
            else {
                delete m_bill[m_billItems];
            }
        }
    }

    void Ordering::printBill(std::ostream& ostr) const {
        double total = 0;
        billTitle(ostr);
        for (size_t i = 0; i < m_billItems; i++) {
            m_bill[i]->print(ostr) << endl;
            total += m_bill[i]->price();
        }
        printTotals(ostr, total);
    }

    void Ordering::resetBill() {
        char filename[256];
        ut.makeBillFileName(filename, m_billNumber);
        ofstream file(filename);
        printBill(file);
        cout << "Saved bill number " << m_billNumber << endl;
        cout << "Starting bill number " << m_billNumber + 1 << endl;

        for (size_t i = 0; i < m_billItems; i++) {
            delete m_bill[i];
            m_bill[i] = nullptr;
        }
        m_billNumber++;
        m_billItems = 0;
    }
}