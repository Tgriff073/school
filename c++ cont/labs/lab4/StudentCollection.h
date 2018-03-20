#ifndef StudentCollection_H
#define StudentCollection_H

#include "StudentProfile.h"

class StudentCollection
{
private:
  vector<StudentProfile> V;
public:
  void setInfo();
  void print();
};

#endif
