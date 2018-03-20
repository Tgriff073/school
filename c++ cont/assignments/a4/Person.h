#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person
{
friend class Family;
  protected:
    long ssn;
    string fName;
    string lName;
  public:
    Person(){ssn=0;fName="";lName="";}
    Person(long id, string fn,string ln)
    {
      ssn=id;
      fName=fn;
      lName=ln;
    }
};
#endif//PERSON
