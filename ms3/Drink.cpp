/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 22/11/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Drink.h"
#include "Utils.h"
#include "Menu.h"

using namespace std;
namespace seneca {
	ostream& Drink::print(ostream& ostr) const
	{
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
	bool Drink::order()
	{
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


	bool Drink::ordered() const
	{
		return m_size != 0;
	}


	ifstream& Drink::read(ifstream& file)
	{
		char buffer[1024]{};
		double priceValue;

		file.getline(buffer, 1024, ',');
		if (file) {
			file >> priceValue;
			file.ignore(1000, '\n');
			if (file) {
				this->name(buffer);
				Billable::price(priceValue);
				m_size = 0;
			}
		}
		return file;

	}

	double Drink::price() const {
		double base = Billable::price();

		if (!ordered() || m_size == 'L')
		{
			return base;
		}

		if (m_size == 'S') {
			return base * 0.5;
		}
		
		if (m_size == 'M')
		{
			return base * 0.75;
		}

		if (m_size == 'X')
		{
			return base * 1.5;
		}
			
			        
		return base;
	}






}


