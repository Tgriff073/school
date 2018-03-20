#ifndef FAMILY_H
#define FAMILY_H
#include "Husband.h"
#include <string>
using namespace std;
class Family
{
  protected: 
    Husptr top;
  public:
    bool AddHusband(long SSN, string Fname, string Lname);
    bool RemoveHusband(long SSN);
    bool AddWife(long SSN, string Fname, string Lname, long husbandSSN);  
    bool RemoveWife(long husbandSSN);
    bool AddAChild(long SSN, string Fname, string Lname, long fatherSSN);
    bool RemoveAChild(long FatherSSN, long childSSN);
    bool PrintAFamily(long fatherSSN);
    bool PrintAllFamilies();
    void ReadTransactionFile();
    static bool success;
    static bool failure;
    Husptr searchHus(long id);
    Husptr searchDad(long id); 
    Family(){top=NULL;}
    ~Family();

};
#endif//FAMILY_H

