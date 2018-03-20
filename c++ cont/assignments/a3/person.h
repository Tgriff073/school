#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
	friend class University;
	protected:
		 long id;
	 	string name;
		 string email;
		 string address;
		 string dateOfBirth;
		 string gender;
	public:
 		Person(long i, string nm, string em, string add, string dob, string gen);
		 Person();
};
#endif//PERSON_H
