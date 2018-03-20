#include <iostream>
using namespace std;
#include "AdjunctProf.h"
#include "TenureTrackPro.h"

int main()
{
  AdjunctProf ad;
  ad.setName("Adam Smith");
  ad.setFacultyId(12345);
  ad.setEmail("asmith@csusm.edu");
  ad.setDegree('M');
  ad.setNoOfCourses(1);
  ad.setNoOfTA(2);
  float salary1=ad.findSalary();
  ad.print();
  cout<<"Salary: "<<salary1<<"/n/n";
  TenureTrackProf tp;
  tp.setName("Jim Anderson");
  tp.setFacultyId(54321);
  tp.setEmail("janderson@csusm.edu");
  tp.setRank('S');
  tp.setYearOfExp(8);
  float salary2=tp.findSalary();
  tp.print();
  cout<<"Salary: "<<salary2<"/n/n";
  system("PAUSE");    
  return 0;
}
