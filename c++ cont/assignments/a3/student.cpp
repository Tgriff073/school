#ifndef STUDENT_C
#define STUDENT_C

#include <iostream>
#include "student.h"
using namespace std;
long Student::nextStId = 500;

Student::Student(string nm, string em, string add, string dob, string gen, int yr, string maj, long adv) : Person(nextStId, nm, em, add, dob, gen)
{
	yearOfStudy = yr;
	major = maj;
	advisorId = adv;
	nextStId++;
}

void Student::testPrint()
{
	 cout << id << endl;
	 cout << name << endl;
	 cout << gender << endl;
	 cout << major << endl;
}
#endif/// STUDENT_C
