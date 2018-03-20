#include <iostream>
using namespace std;
//Initialized my variables
int w=5;
int x=0;
int a=10;
double celsius=0.0;
double fahrenheit=0.0;
double conversion= 0.55555555;	

//start of partone which checks answers from partone a
void partOne()
{
if(w==5)
cout<<"five\n";

if(x<=9)
cout<<"small\n";

if(a>=19)
cout<<"bigger\n";

if((x<10)==(a>x))
cout<<"equal\n";

if((a<x)||(w>10))
cout<<"jawohl\n";

if(x=5)
cout<<"true\n";

x=0;

if(a!=x)
cout<<"not equal\n";

if(a)
cout<<"a\n";
}//end of answer check
//begein part three 
void partThree()
{int div=0;
int divisor =1;
cout<<"enter a 3 digit dividend:";
cin>>div;
cout<<"\nenter a 3 digit divisor: ";
cin>>divisor;
int ans =div/divisor;
int remainder =div%divisor;
cout <<"\n       "<<ans<<" R "<<remainder<<endl;
cout<<" -------\n";
cout<< divisor << " } " << div<< endl;
cout << "\n That was division as you first learned it!\n";
cout<< "\nReal long division would give the following answer: " << div*1.0 /divisor<<endl;
} //end of part three division
//begin fahrenheit converter
void partFour ()
{
cout<<"Welcome to the fahrenheit to celsius converter\n";
cout<<"Please enter a temperature in fahrenheit:"<<endl;
cin>>fahrenheit;
celsius =(fahrenheit-32)*conversion;
cout<<"You entered: "<<fahrenheit<<endl;
cout<<"That would be: "<<celsius<<" degrees in celsius"<<endl;
if(celsius>37.77)
cout<<"Stay cool out,it's pretty hot out there!"<<endl;
else 
cout<<"Thank you and have a nice day";
}//end fahrenheit converter

int main ()
{
partOne();
//partThree();
partFour();


return 0;
}//end main

