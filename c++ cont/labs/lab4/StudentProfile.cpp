#ifndef StudentProfile_C
#define StudentProfile_C
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "StudentProfile.h"


void StudentProfile::setInfo(long vSsn,string vFname,string vLname,int vAge,char vGender,long vStNo,long cNum1,string cName1,long cNum2,string cName2,long cNum3,string cName3)
{

StdInfo.setInfo(vStNo, cNum1, cName1, cNum2, cName2, cNum3, cName3);
PersonalInfo.setInfo(vSsn,vFname, vLname, vAge, vGender);
}

void StudentProfile::print()
{
PersonalInfo.print();
StdInfo.print();

}
#endif
