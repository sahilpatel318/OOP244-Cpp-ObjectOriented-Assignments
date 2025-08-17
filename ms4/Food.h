/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 03/12/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include "Billable.h"
namespace seneca {
   class Food: public Billable{
	   bool m_ordered{false};
	   bool m_child{ false };
	   char* m_customize{nullptr};


   public:
	   Food();
	   Food(const Food& other);
	   Food& operator=(const Food& other);
	   virtual ~Food();

	   bool ordered()const override;
	   std::ostream& print(std::ostream& ostr = std::cout)const override;
	   std::ifstream& read(std::ifstream& file) override;
	   double price()const override;
	   bool order() override;
	   
   };
}
#endif // !SENECA_FOOD_H


