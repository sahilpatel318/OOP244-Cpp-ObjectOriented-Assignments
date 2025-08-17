/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 03/12/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include <iostream>

namespace seneca {
    class Ordering {
        Food* m_foods{};              
        Drink* m_drinks{};           
        size_t m_foodItems{};            
        size_t m_drinkItems{};          
        size_t m_billItems{};          
        size_t m_billNumber{ 1 };        
        Billable* m_bill[MaximumNumberOfBillItems]{}; 
        size_t countRecords(const char* file) const;
        void billTitle(std::ostream& ostr) const;
        void printTotals(std::ostream& ostr, double total) const;

    public:
        Ordering(const char* drinks, const char* foods);
        ~Ordering();
        Ordering(const Ordering&) = delete;
        Ordering& operator=(const Ordering&) = delete;

        operator bool() const;
        bool hasUnsavedBill() const;
        size_t noOfBillItems() const;
     
        void listFoods() const;
        void ListDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& ostr) const;
        void resetBill();
    };
}
#endif   // !SENECA_ORDERING_H