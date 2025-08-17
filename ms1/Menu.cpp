/*

Keshav Callychurn
Student No: 108568247
Email Id: kcallychurn@myseneca.ca
Date: 10/11/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "constants.h"
using namespace std;
namespace seneca {



	

	MenuItem::MenuItem(const char* content, unsigned int numOfindendations, unsigned int indentationSize, int row)
	{

		if (content == nullptr) {

			setEmpty();
			return;
		}

		

		if ((ut.isspace(content)) || (ut.strlen(ut.ltrim(content)) == 0)  || (numOfindendations > 4 || indentationSize > 4) || row > int(MaximumNumberOfMenuItems))
		{
			
			if (row != -1)
			{
				
				
				setEmpty();
				return;
			}
				
		    
			
		}
		

		m_content = new char[ut.strlen(ut.ltrim(content))+1];
		ut.strcpy(m_content, ut.ltrim(content));
		m_numOfindendations = numOfindendations;
		m_indentationSize = indentationSize;
		m_row = row;
		
		
		

	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
	}

	MenuItem::operator bool() const
	{
		return isValid();

	}

	bool MenuItem::isValid() const
	{

		if (m_content == nullptr) {
			
			return false;  
		}

		if ( (ut.isspace(m_content)) || (ut.strlen(ut.ltrim(m_content)) == 0) || (m_numOfindendations > 4 || m_indentationSize > 4) || (m_row > int(MaximumNumberOfMenuItems)))
		{
			if (m_row != -1)
			{
				return false;
			}
			
		}

		return true;
	}

	void MenuItem::setEmpty()
	{
		m_content = nullptr;
		m_numOfindendations = 0;
		m_indentationSize = 0;
		m_row = 0;
	}

	ostream& MenuItem::display(ostream& ostr) const
	{
		if (m_content == nullptr || !isValid())
		{
			
			return ostr << "??????????";
		}


		for (unsigned i = 0; i < m_numOfindendations; ++i) {
			for (unsigned j = 0; j < m_indentationSize; ++j) {
				ostr << " ";
			}
		}

		if (m_row >= 0)
		{
			m_row > 9 ? ostr << m_row << "- ":ostr <<" "<<m_row << "- ";
		}

		ostr << m_content;


		return ostr;

	}
}