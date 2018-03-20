#include <iostream>
#include "Date.h"
using namespace std;
void driver();
void driver2();

int main()
{
driver();
//part three implementation
driver2();

return 0;
}//end of main

void driver()

{
Date();
Date date(Wednesday,18,November,2014);
system("PAUSE");
}//end of driver

void driver2()
{

}//end of driver2

Date::Date()
{
  cout<<"In constructor"<<endl;
  day=Sunday;
  month=January;
  daym=0;
  year=0;
}

Date::~Date()
{
cout<<"In destructor"<<endl; 
}

Date::Date(Day a, int b, Month c, int d)
{
day=a;
daym=b;
month=c;
year=d;
}

int Date::getDateInt()
{

}

string Date::getDayOfWeekLong()
{
}

string Date::getDayOfWeekShort()
{
}

int Date::getMonthInt()
{
}

int Date::getYear()
{
}

string Date::getMonthShort()
{
}
