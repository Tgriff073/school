#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
//Classes
class Course
{
public:
  long courseNum;
  string CourseName;
};

class Student
{
public:
  long stNo;
  Course course1;
  Course course2;
  Course course3;
};

class Person
{
public:
  long ssn;
  string fName;
  string lName;
  int age;
  char gender;
};

class StudentProfile
{
public:
  Person PersonalInfo;
  Student StdInfo;
};

//prototypes
void fileIn(vector<StudentProfile>&);
void display(const vector<StudentProfile>&);

int main()
{
  vector<StudentProfile> V(3);
  fileIn(V);
  display(V);
 
}
void fileIn(vector<StudentProfile>& V)
{
ifstream fin;
fin.open("people.txt");
if(!fin)
{
cout<<"File not found"<<endl;
return;
}
 for(int i=0;i<V.size();i++)
  {
   
    fin>>V[i].PersonalInfo.ssn;
    fin>>V[i].PersonalInfo.fName;
    fin>>V[i].PersonalInfo.lName;
    fin>>V[i].PersonalInfo.age;
    fin>>V[i].PersonalInfo.gender;
    fin>>V[i].StdInfo.stNo;
    fin>>V[i].StdInfo.course1.courseNum;
    fin>>V[i].StdInfo.course1.CourseName;
    fin>>V[i].StdInfo.course2.courseNum;
    fin>>V[i].StdInfo.course2.CourseName;
    fin>>V[i].StdInfo.course3.courseNum;
    fin>>V[i].StdInfo.course3.CourseName;
  }//end loop
fin.close();
}//end fileIn

void display(const vector<StudentProfile>& V)
{
  for(int i=0;i<V.size();i++)
  {
    cout<<"Student "<<i+1<<"\n******************************\n";
    cout<<"SSN: "<<V[i].PersonalInfo.ssn<<endl;
    cout<<"First Name: "<<V[i].PersonalInfo.fName<<endl;
    cout<<"Last Name: "<<V[i].PersonalInfo.lName<<endl;
    cout<<"Age: "<<V[i].PersonalInfo.age<<endl;
    cout<<"Gender: "<<V[i].PersonalInfo.gender<<endl;
    cout<<"Student Number: "<<V[i].StdInfo.stNo<<endl;
    cout<<"Course 1 Number: "<<V[i].StdInfo.course1.courseNum<<endl;
    cout<<"Course 1 Name: "<<V[i].StdInfo.course1.CourseName<<endl;
    cout<<"Course 2 Number: "<<V[i].StdInfo.course2.courseNum<<endl;
    cout<<"Course 2 Name: "<<V[i].StdInfo.course2.CourseName<<endl;
    cout<<"Course 3 Number: "<<V[i].StdInfo.course3.courseNum<<endl;
    cout<<"Course 3 Name: "<<V[i].StdInfo.course3.CourseName<<endl;
    cout<<"\n";
  }//end loop
}//end display
