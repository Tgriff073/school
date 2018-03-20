#ifndef Course_C
#define Course_C

#include<iostream>

using namespace std;
#include "Course.h"


void Course::setInfo(long cNum,string cName)
{
  CourseNum=cNum; 
  CourseName=cName;
}

void Course::print()
{
cout<<"Course Number: "<<CourseNum<<endl;
cout<<"Course Name: "<<CourseName<<endl;
}

#endif //end course.cpp
