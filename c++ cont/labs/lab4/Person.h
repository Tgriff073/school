#ifndef Person_H
#define Person_H

class Person
{
private:
  long ssn;
  string fName; 
  string lName;
  int age;
  char gender;
  
public:
  void setInfo(long,string,string,int,char);
  void print();
};
#endif //Person_H
