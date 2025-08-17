/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 22/11/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/



#include "Billable.h"
#include "Utils.h"

namespace seneca {

	Billable::Billable()
	{
		m_price = 0.0;
		m_name = nullptr;
	}
	Billable::Billable(const Billable& other)
	{
		m_price = other.m_price;
		ut.alocpy(m_name, other.m_name);
	}

	Billable& Billable::operator=(const Billable& other)
	{
		if (this != &other) {  

			m_price = other.m_price;
			ut.alocpy(m_name, other.m_name);
		}

		return *this;
		
	}
	Billable::~Billable()
	{
		delete [] m_name;
	}


	void Billable::price(double value)
	{
		m_price = value;
	}
	void Billable::name(const char* name)
	{
		ut.alocpy(m_name, name);
	}

	

	double Billable::price() const
	{
		return m_price;
	}




	Billable::operator const char* () const
	{
		return m_name;
	}

	double operator+(double money, const Billable& B)
	{
		return money + B.price();
	}
	double& operator+=(double& money, const Billable& B)
	{
		money += B.price();
		return money;
	}
	
	
}
