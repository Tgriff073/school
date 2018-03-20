#ifndef StudentCollection_C
#define StudentCollection_C
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StudentCollection.h"
#include "StudentProfile.h"

void StudentCollection::setInfo()
{
  long ssn,stNo,courseNum1,courseNum2,courseNum3=0;
  string fName,lName,courseName1,courseName2,courseName3="";
  int age=0;
  char gender='f';
  ifstream fin;
  fin.open("people.txt");
  
  fin>>ssn>>fName>>lName>>age>>gender>>stNo>>courseNum1>>courseName1>>courseNum2>>courseName2>>courseNum3>>courseName3;
  while(fin)
  {
    StudentProfile stProf;
    stProf.setInfo(ssn, fName, lName, age, gender, stNo, courseNum1, courseName1, courseNum2, courseName2, courseNum3, courseName3);
    V.push_back(stProf);
    fin>>ssn>>fName>>lName>>age>>gender>>stNo>>courseNum1>>courseName1>>courseNum2>>courseName2>>courseNum3>>courseName3;
  }
}

void StudentCollection::print()
{
  for (int i=0;i<V.size();i++) 
  {
  cout<<"Student #"<<i+1 <<" :"<<endl;
  cout<<"*****************************\n";
  V[i].print();
  }
}
#endif
