#ifndef Student_H
#define Student_H


#include "Course.h"


class Student
{
private:
  long StNo; 
  Course course1;
  Course course2;
  Course course3;
public:
  void setInfo(long,long,string,long,string,long,string);
  void print();
};
#endif//Student_H
