#ifndef FACULTY_C
#define FACULTY_C
#include "faculty.h"
#include "person.h"
long Faculty::nextFacultyId=600;
Faculty::Faculty(string nm, string em, string add, string dob,string gen,float fSalary,int fYearOfExp,long fDepId): Person(nextFacultyId,nm, em, add, dob, gen)
{
salary=fSalary;
yearOfExp=fYearOfExp;
departId=fDepId;
nextFacultyId++;
}
#endif//FACULTY_C
         
