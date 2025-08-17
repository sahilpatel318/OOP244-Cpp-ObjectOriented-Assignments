/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 03/12/2024

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



	Menu::Menu (const char* title, const char* exit, unsigned int indentation , unsigned int size ):
		me_numOfindendations(indentation),
		me_indentationSize (size),

		
		m_title(title, indentation, size, -1), 
		m_exitOption(exit, indentation, size, 0),
		m_selection("> ", indentation, size ,-1),
		m_numMenuItem(0)
	{
		
		
		
		for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
			m_menuItems[i] = nullptr;
		}
		
	}

	Menu& Menu::operator<<(const char* content)
	{
		if (m_numMenuItem < MaximumNumberOfMenuItems)
		{
			m_menuItems [m_numMenuItem] = new MenuItem(content, me_numOfindendations, me_indentationSize, m_numMenuItem + 1);
			m_numMenuItem++;
		}
		return *this;
	}

	Menu::~Menu()
	{
		for (size_t i = 0; i < m_numMenuItem; i++) {
			
				delete  m_menuItems[i];
				m_menuItems[i] = nullptr;

		}
	}

	size_t Menu::select() const
	{
		if (m_title)
		{
			m_title.display() << endl;
		}

		for (size_t i = 0; i < m_numMenuItem; i++) {
			if (m_menuItems[i] != nullptr)
			{
				m_menuItems[i]->display() << endl;
				
			}

	    }

		
		m_exitOption.display() << endl;
		
		m_selection.display();
		
	
		return ut.getInt(0, m_numMenuItem);
	}

	


	 size_t operator<<(ostream& ostr, const Menu& m)
	 {
		 if (&ostr == &cout)
		 {
			 return m.select();
		 }
		 return 0;
		 
	 }


}