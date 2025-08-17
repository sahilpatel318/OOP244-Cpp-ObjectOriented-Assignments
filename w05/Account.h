#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      //Type conversion operator
      operator bool() const;
      operator int() const;
      operator double() const;

      //Unary member operator
      bool operator~() const;

      //Assignment operator
      Account& operator=(int accNumber);
      Account& operator=(Account& other);

      //Binary operator with side-effect
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& other);
      Account& operator>>(Account& other);
  
   };

   // Binary helper operator
   double operator+(const Account& left, const Account& right);
   double& operator+=(double& left, const Account& right);


}
#endif // SENECA_ACCOUNT_H_