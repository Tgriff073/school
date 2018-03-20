#ifndef CHILD_H
#define CHILD_H
#include <string>
#include "Person.h"


class Child;
typedef Child* Childptr;
using namespace std;
class Child: public Person 
{
  friend class Family;
  protected:
    Childptr mySibling;
  public:
    Child(){mySibling=NULL;}
    Child(long id, string fn, string ln):Person(id,fn,ln)
    {
      mySibling=NULL;
    }
};
#endif//CHILD
