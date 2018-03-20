#ifndef FACULTY_H
#define FACULTY_H
#include "person.h"
using namespace std;
class Faculty: public Person
{
	friend class University;
	protected:
		float salary;
		int yearOfExp;
		long departId;
		static long nextFacultyId;
	public:
		Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearofExp,long fDepId);
		
};
#endif//FACULTY_H
