#ifndef Main_C
#define Main_C

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "StudentProfile.h"
#include "StudentCollection.h"


int main()
{

StudentCollection collection;
collection.setInfo();
collection.print();
system("PAUSE");
return 0;
}

#endif
