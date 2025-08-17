/***********************************************************************
// OOP244 Workshop 7 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/11/07
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include "Professor.h"
using namespace std;
using namespace seneca;

void prnProf();

int main() {
   Professor P( "Edna Krabappel", "OOP345 - Object-Oriented Software Development Using C++", 3, 11222, 76543.0 );
   P.title() << endl;
   P.write() << endl;
   cout << "Enter the following:" << endl;
   cout << "John Doe,IPC144 - Introduction to Programming Using C, 3, 12312, 65432<ENTER>\n> ";
   cin >> P;
   cin.ignore( 1000, '\n' );
   cout << "You enterd:" << endl;
   P.title() << endl;
   cout << P << endl;
   prnProf();
   return 0;
}
void prnProf() {
   ifstream file("professors.csv");
   Professor P;
   cout << "List of professors in file!" << endl;
   P.title() << endl;
   while (file) {
      P.read(file).ignore(1000, '\n');
      if (file) cout << P << endl;
   }
}