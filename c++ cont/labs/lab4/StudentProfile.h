#ifndef StudentProfile_H
#define StudentProfile_H
#include "Student.h"
#include "Person.h"

class StudentProfile
{
private:
  Person PersonalInfo;
  Student StdInfo;
public:
  void setInfo(long,string,string,int,char,long,long,string,long,string,long,string);
  void print();
};


#endif
