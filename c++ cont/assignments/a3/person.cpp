#ifndef PERSON_C
#define PERSON_C
#include "person.h"

Person::Person(long i, string nm, string em, string add, string dob, string gen)
{
 id = i;
 name = nm;
 email = em;
 address = add;
 dateOfBirth = dob;
 gender = gen;
}


#endif
