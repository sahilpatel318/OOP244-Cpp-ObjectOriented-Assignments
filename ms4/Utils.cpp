/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// Date 2024-9-11
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*

Sahil Hareshbhai Patel
Student No: 173793225
Email Id: shpatel27@myseneca.ca
Date: 03/12/2024

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/



#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }

   char* Utils::strcpy(char* des, const char* src, int len)const {
       int i;
       for (i = 0; i < len && src[i]; i++) des[i] = src[i];
       des[i] = 0; // unlike std::strncpy, this function null terminates
       return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   const char* Utils::ltrim(const char* str) const {
    
       while (str && *str && isspace(*str)) {
           str++; 
       }
       return str;  
   }

   int Utils::getInt()
   {
            int num;
           bool done = false;
           do {
               cin >> num;
               if (cin) {
                   if (cin.peek() != '\n') {
                       cout << "Only an integer please:\n> ";
                   }
                   else {
                       done = true;
                   }
               }
               else {
                   if (cin.eof()) {
                       cin.clear();
                       cout << "You must enter a value :\n";
                   }
                   else
                   {
                       cin.clear();
                       cout << "Invalid integer:\n> ";
                   }
                  
               }
               cin.ignore(100000, '\n');
           } while (!done);

           return num;
       
   }

   int Utils::getInt(int min, int max)
   {
       int num;
       bool done = false; 
       do {
           num = getInt();

           if (num < min || num > max)
           {
               cout << "Invalid value : [min <= value <= max] , try again :\n";
           }
           else
           {
               done = true;
           }
       } while (!done);

       return num;
       
   }


   char* Utils::read(char*& toRet, istream& istr, char delimiter)const {
       bool done = false;
       char* cstr = new char[128];
       toRet = cstr;
       int size = 128;
       int nullindex = 1;
       do {
           cin.getline(cstr, 128, delimiter);
           if (cin.fail()) {
               char* temp = new char[size + 128];
               strcpy(temp, toRet);
               delete[] toRet;
               toRet = temp;
               cstr = &toRet[size - nullindex++];
               size += 128;
               cin.clear();
           }
           else {
               done = true;
           }
       } while (!done);
       char* temp = new char[strlen(toRet) + 1];
       strcpy(temp, toRet);
       delete[] toRet;
       toRet = temp;
       return toRet;
   }


   char* Utils::makeBillFileName(char* filename, size_t billNo) const {
       char billName[21] = "bill_";
       size_t temporary = billNo;
       int cnt = 5;
       int length;

       do {
           cnt++;
           temporary /= 10;
       } while (temporary > 0);
       length = cnt;


       while (billNo > 0) {
           billName[--cnt] = (billNo % 10) + '0';
           billNo /= 10;
       }
       if (billName[cnt - 1] == '\0') {
           billName[--cnt] = '0';
       }
       for (int i = 0; ".txt"[i]; i++) {
           billName[length++] = ".txt"[i];
       }
       billName[length] = '\0';
       strcpy(filename, billName);
       return filename;
   }

}