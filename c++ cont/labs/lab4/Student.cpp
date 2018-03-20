#ifndef Student_C
#define Student_C
#include <iostream>
using namespace std;
#include "Student.h"
#include "Course.h"

void Student::setInfo(long vStNo,long cNum1,string cName1,long cNum2,string cName2,long cNum3,string cName3)
{
StNo=vStNo;

course1.setInfo(cNum1,cName1);
course2.setInfo(cNum2,cName2);
course3.setInfo(cNum3,cName3);
}  

void Student::print()
{
cout<<"Student Number: "<<StNo<<endl;
course1.print();
course2.print();
course3.print();
cout<<"\n";
}
#endif
