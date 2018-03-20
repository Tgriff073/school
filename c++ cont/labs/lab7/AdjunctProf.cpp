#include "AdjunctProf.h" 
#include <iostream>
using namespace std;
  
char AdjunctProf::getDegree()
{
  return degree;
}

int AdjunctProf::getNoOfCourses()
{
  return NoOfCourses;
}

int AdjunctProf::getNoOfTA()
{
  return NoOfTA;
}

void AdjunctProf::setDegree(char d)
{
  degree=d;
}

void AdjunctProf::setNoOfCourses(int c)
{
NoOfCourses=c;
}

void AdjunctProf::setNoOfTA(int t)
{
  NoOfTA=t;      
}

float AdjunctProf::findSalary( ) const    
{
  float tmp=0;
  if(degree=='B')
    tmp=(1500*NoOfTA)+(3000*NoOfCourses);
  else if(degree=='M')
   tmp=(2000*NoOfTA)+(4000*NoOfCourses);
  else if (degree=='P')
    tmp=(2500*NoOfTA)+(5000*NoOfCourses);
    return tmp;
}

AdjunctProf::AdjunctProf()
{
degree='Z';
NoOfTA=0;
NoOfCourses=0;
}

void AdjunctProf::print() const
{
cout<<"Name: "<<name<<endl;
cout<<"Email: "<<email<<endl;
cout<<"Faculty Id: "<<facultyId<<endl;
cout<<"Degree: "<<degree<<endl;
cout<<"Number of Courses: "<<NoOfCourses<<endl;
cout<<"Number of Teaching Assistants: "<<NoOfTA<<endl;
}  
