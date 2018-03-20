#include "CompsciProfessor.h"
using namespace std;

class AdjunctProf:public CompSciProfessor
{
private:
  char degree;
  int NoOfTA;
  int NoOfCourses;
public:
  AdjunctProf();
  void print() const;  
  char getDegree();
  int getNoOfTA();
  int getNoOfCourses();
  void setDegree(char);
  void setNoOfTA(int);
  void setNoOfCourses(int);
  float findSalary() const;  
};
