#include "TenureTrackPro.h"
#include <iostream>

  char TenureTrackProf::getRank()
  {
       return rank;
  }
  
  int TenureTrackProf::getYearOfExp()
  {
    return YearOfExp;
  }
  
  void TenureTrackProf::setRank(char r)
  {
    rank=r;
  }
  
  void TenureTrackProf::setYearOfExp(int y)
  {
    YearOfExp=y;
  }
  float TenureTrackProf::findSalary() const
  {
  float tmp=0;
  if(rank=='A')
    tmp=65000+(1500*YearOfExp);
  else if(rank=='S')
    tmp=65000+(1500*YearOfExp);
  else if(rank=='F')
    tmp=65000+(1500*YearOfExp);
  return tmp;
  }
  
  TenureTrackProf::TenureTrackProf()
  {
   rank='Z';
  YearOfExp=0;
  }
                   
  void TenureTrackProf::print() const
  {
    cout<<"Name: "<<name<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Faculty Id: "<<facultyId<<endl;
    cout<<"Rank: "<<rank<<endl;
    cout<<"YearOfExp: "<<YearOfExp<<endl;
  } 
