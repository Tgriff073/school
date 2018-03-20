#include <iostream>
using namespace std;

enum AcademicLevel{Freshmen, Sophmore, Junior, Senior, Graduate, Error};
int getInt(string);
void displayLevel(AcademicLevel);
AcademicLevel getYear(int);
int main()
{
int userVal=0;
char answer='c';
AcademicLevel year=Freshmen;
string prompt="Please enter an integer between 1 and 5\n1 being a freshmen and 5 being graduate:\n";
while(answer=='c'||answer=='C')
{
userVal=getInt(prompt);
year=getYear(userVal);
displayLevel(year);
cout<<"To continue type c and then hit enter, to exit type e and then hit enter:\n";
cin>>answer;
}
return 0;

}

int getInt(string prompt)
{
int userVal=0;
cout<<prompt;
cin>>userVal;
return userVal;
}
AcademicLevel getYear(int userVal)
{
switch(userVal)
{
case 1:
return Freshmen;
case 2:
return Sophmore;
case 3:
return Junior;
case 4:
return Senior;
case 5:
return Graduate;
default:return Error;
}
}
void displayLevel(AcademicLevel year)
{
switch(year)
{
case Freshmen:
cout<<"You are a Freshmen\n";
break;
case Sophmore:
cout<<"You are a Sophmore\n";
break;
case Junior:
cout<<"You are a Junior\n";
break;
case Senior:
cout<<"You are a Senior\n";
break;
case Graduate:
cout<<"You are a Graduate\n";
break;
case Error:
cout<<"Number entered was not valid\n";
break;
}
}
