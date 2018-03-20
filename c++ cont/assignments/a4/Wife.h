#ifndef WIFE_H
#define WIFE_H
#include "Child.h"
#include <string>
using namespace std;
class Wife;
typedef Wife* Wifeptr;


class Wife:public Person
{
  friend class Family;
  protected:
    Childptr myChild;
  public:
    Wife(){myChild=NULL;}
    Wife(long id, string fn, string ln):Person(id,fn,ln)
    {myChild=NULL;}
};
#endif
