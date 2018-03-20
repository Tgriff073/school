#ifndef HUSBAND_H
#define HUSBAND_H
#include <string>
#include "Wife.h"
using namespace std;
class Husband;
typedef Husband* Husptr;

class Husband:public Person
{
  friend class Family;
  protected:
    Husptr nextFamily;
    Wifeptr myWife;
  public:
    Husband(){ myWife=NULL;nextFamily=NULL;}
    Husband(long id,string fn,string ln):Person(id,fn,ln)
    {
      nextFamily=NULL;
      myWife=NULL;
    }
   
};
#endif//Husband_H
