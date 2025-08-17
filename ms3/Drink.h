/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 22/11/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
namespace seneca {
   class Drink: public Billable{

	   char m_size{};

   public:
	   Drink() = default;
	   std::ostream& print(std::ostream& ostr = std::cout)const override;
	   bool order()override;
	   virtual bool ordered()const override;
	   std::ifstream& read(std::ifstream& file) override;
	   double price() const override;
   };
}
#endif // !SENECA_DRINK_H


