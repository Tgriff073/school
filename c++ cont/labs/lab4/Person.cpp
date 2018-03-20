#ifndef Person_C
#define Person_C
using namespace std;
#include <string>
#include "Person.h"

#include <iostream>

void Person::setInfo(long vSsn,string vFname,string vLname,int vAge,char vGender)
{
  ssn=vSsn;
  fName=vFname; 
  lName=vLname;
  age=vAge;
  gender=vGender;
}

void Person::print()
{
cout<<"Social Security #: "<<ssn<<endl;
cout<<"First Name: "<<fName<<endl;
cout<<"Last Name: "<<lName<<endl;
cout<<"Age: "<<age<<endl;
cout<<"Gender: "<<gender<<endl;
}
#endif//Person
