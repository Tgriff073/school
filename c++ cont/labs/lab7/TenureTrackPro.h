#include "CompsciProfessor.h"

class TenureTrackProf:public CompSciProfessor
{
private:
  char rank;
  int YearOfExp;
public:
  TenureTrackProf();
  char getRank();
  int getYearOfExp();
  void setRank(char);
  void setYearOfExp(int);
  void print() const;
  float findSalary() const;
};
