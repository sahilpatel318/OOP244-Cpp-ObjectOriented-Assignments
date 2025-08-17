
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include <iostream>

namespace seneca {
    class Ordering {
        Food* m_foods{};                 // Dynamic array for foods
        Drink* m_drinks{};               // Dynamic array for drinks
        size_t m_foodItems{};            // Counter for food items
        size_t m_drinkItems{};           // Counter for drink items
        size_t m_billItems{};            // Counter for items in current bill
        size_t m_billNumber{ 1 };        // Bill serial number
        Billable* m_bill[MaximumNumberOfBillItems]{}; // Array of bill items

        // Private helper methods
        void billTitle(std::ostream& ostr) const;
        void printTotals(std::ostream& ostr, double total) const;
        size_t countRecords(const char* file) const;

    public:
        Ordering(const char* drinks, const char* foods);
        ~Ordering();

        // Prevent copying
        Ordering(const Ordering&) = delete;
        Ordering& operator=(const Ordering&) = delete;

        // Query methods
        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        // Menu methods
        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& ostr) const;
        void resetBill();
    };
}
#endif   // !SENECA_ORDERING_H