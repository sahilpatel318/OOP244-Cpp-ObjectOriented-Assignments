/*

Keshav Callychurn
Student No: 108568247
Email Id: kcallychurn@myseneca.ca
Date: 10/11/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

namespace seneca {
   class MenuItem {
	   char* m_content;
	  unsigned int m_numOfindendations;
	  unsigned int m_indentationSize;
	   int m_row;

   public:
	   
	   MenuItem(const char* content, unsigned int numOfindendations, unsigned int indentationSize, int row);
	   ~MenuItem();

	   MenuItem(const MenuItem& item) =  delete;
	   MenuItem& operator=(const MenuItem& item) = delete;

	   operator bool()const;
	   bool isValid()const;
	   void setEmpty();
	   std::ostream& display(std::ostream& ostr = std::cout) const;

	  

   };

   

}
#endif // !SENECA_MENU_H


