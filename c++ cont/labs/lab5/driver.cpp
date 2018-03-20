#include <iostream>
#include "employee.h"
friend void SetSalary(Employee&)
int Employee::totalNumofEmployees=0;
int Employee::nextEmpId=0;
int Employee::nextOfficeNo=0;
using namespace std;

int main()
{
Employee emp1;
emp1.Print();
return 0;
}

friend void SetSalary(Employee& E)
{
if(E.empPosition=='E'&&E.yearOfExp<2)
salary=50000;
else if(E.empPosition=='E'&&E.yearOfExp>=2)
salary=55000;
else if(E.empPosition=='P'&&E.yearOfExp<4)
salary=60000;
else if(E.empPosition=='P'&&E.yearOfExp>=4)
salary=65000;
else if(E.empPosition=='M')
salary=70000;
else if (E.empPosition=='D')
salary=80000;
}
