#include <iostream>
#include "employee.h"
using namespace std;

//default constructor
Employee::Employee():empId(nextEmpId),officeNo(nextOfficeNo)
{
  totalNumofEmployees++;
  nextEmpId++;
  nextOfficeNo++;
  name="unknown";
  deptNo=0;
  empPosition='E';
  yearOfExp=0;
  salary=0;
}//end of default constructor

Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp):empId(nextEmpId),officeNo(nextOfficeNo)
{
  name=theName;
  deptNo=theDeptNo;
  empPosition=theEmpPosition; 
  yearOfExp=theYearOfExp;
  salary=0;
  totalNumofEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}//end constructor 4params

Employee::~Employee()
{
  totalNumofEmployees--;
  nextEmpId--;
  nextOfficeNo--;
  name="";
  deptNo=0;
  empPosition=' ';
  yearOfExp=0;
  salary=0;
}//end destructor

void Employee::Print() const
{
cout<<"Employee name: "<<name<<endl;
cout<<"OfficeNo: "<<officeNo<<endl;
cout<<"Employee Id: "<<empId<<endl;
cout<<"Department number: "<<deptNo<<endl;
cout<<"Employee position: "<<empPosition<<endl;
cout<<"Years of experience: "<<yearOfExp<<endl;
cout<<"Salary: "<<salary<<endl;
cout<<"Total number of employees: "<<totalNumofEmployees<<endl;
cout<<"Next employee id: "<<nextEmpId<<endl;
cout<<"Next office number: "<<nextOfficeNo;
}//end print

void Employee::GetInfo()
{
cout<<"Whats the employees name?"<<endl;
cin>>name;
cout<<"What's their position?(E,M,D or P)"<<endl;
cin>>empPosition;
cout<<"How many years of experience do they have?"<<endl;
cin>>yearOfExp;
}

