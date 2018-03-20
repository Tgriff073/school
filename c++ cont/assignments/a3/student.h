#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>
#include "person.h"
#include "course.h"
using namespace std;

class Student : public Person
{
	 friend class University;
	private:
 		int yearOfStudy;
 		string major;
		long advisorId;
		vector<Course> coursesTaken;// (vector of courses taken by a student)
		static long nextStId;// initialize it to 500
	public:
 		Student(string nm, string em, string add, string dob, string gen, int yr, string maj, long adv);
		 void testPrint();
};
#endif
