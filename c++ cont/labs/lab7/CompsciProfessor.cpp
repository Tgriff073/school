#include "CompsciProfessor.h"

string CompSciProfessor::getEmail()
{
  return email;
}
  
string CompSciProfessor::getName()
{
  return name;
}
  
long CompSciProfessor::getfacultyId()
{
  return facultyId;
}
  
void CompSciProfessor::setEmail(string e)
{
  email=e;
}
  
void CompSciProfessor::setFacultyId(long f)
{
  facultyId=f;
}
  
void CompSciProfessor::setName(string n)
{
  name=n;
}

CompSciProfessor::CompSciProfessor()
{
name="Blank";
email="Blank@blank";
facultyId=0;
}
