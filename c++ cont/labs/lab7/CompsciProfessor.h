#ifndef CompSciProfessor_H
#define CompSciProfessor_H
#include <string>
using namespace std;

class CompSciProfessor
{
protected:      
  string name;
  string email;
  long facultyId;  
public:
  CompSciProfessor();
  string getName();
  string getEmail();
  long getfacultyId();
  void setName(string);
  void setEmail(string);
  void setFacultyId(long);
};
#endif
