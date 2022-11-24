#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
   int day, month, year;
public:
   Date();
    friend std::ostream& operator<<(std::ostream&, const Date&);
//         std::ostream& operator<<(std::ostream&, const Date&);
   friend std::istream& operator>>(std::istream&, Date&);

};

#endif   // DATE_H

// #include "date.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Date::Date()
{
   time_t today = time(0);
   tm *lt = localtime(&today);
   year = lt->tm_year + 1900;
   month = lt->tm_mon + 1;
   day = lt->tm_mday;
}

ostream& operator<<(ostream& os, const Date& d) {
   os << d.day << '.'<<d.month<<'.'<<d.year;
   return os;
}

istream& operator>>(istream& is, Date& d) 
{
   is >> d.day >> d.month >> d.year;
   return is;
}


 /////////////////////////////////////////////////////

using namespace std;
int main()
{
   Date d;
   Date d2;

   cout<<d<<endl;
   cout<<"Enter Date (in dd/mm/yyyy):\n";
   cin>>d2;
   cout<<d2;

   return 0;
}