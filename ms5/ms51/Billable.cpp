
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Billable.h"
#include "Utils.h"

namespace seneca {
    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* name) {
        ut.alocpy(m_name, name);
    }

    Billable::Billable() : m_name(nullptr), m_price(0.0) {}

    Billable::Billable(const Billable& src) : m_name(nullptr), m_price(0.0) {
        *this = src;
    }

    Billable& Billable::operator=(const Billable& src) {
        if (this != &src) {
            m_price = src.m_price;
            ut.alocpy(m_name, src.m_name);
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money = money + B.price();
        return money;
    }
}