#include <iostream>
#include <iomanip>
using namespace std;

//function will 3 values from user and the find the average of those 3 numbers
void averageTest()
{
double test1=0.0;
double test2=0.0;
double test3=0.0;
double ave=0.0;
bool perfect;
//prompt user for input of test scores
  cout<<"Enter 3 test scores seperated by spaces:";
  cin>>test1>>test2>>test3;
//formula for average
  ave=(test1+test2+test3)/3;
 // i had just an eqauls and got an incorrect answer and switched it to == 
if(ave==100)
    perfect = true;

  if(perfect)
{  
   cout<<"fabulous!\n";
   cout<<"your score was the best possible!\n";
   
}
  else
    cout<<"\n Your average is "<<setprecision(4)<<fixed<<ave<<endl;
}//end of testAverage











//function checks answers from partone b
void answerCheck()
{
int int1=10;
int int2=16;
int int3=19;

if(int1<int2&&int2<int3)
cout<<"yes\n";
else
cout<<"no\n";

if(int1<=int2-6)
cout<<"yes\n";
else
cout<<"no\n";

if ((int2<=int1 +5) ||(int3>=int2+5))
cout<<"yes\n";
else
cout<<"no\n";


if (!(int2==int1 && int3==int1))
cout<<"yes\n";
else
cout<<"no\n";

if(int3=12)
cout<<"yes\n";
else
cout<<"no\n";

if(!(int1<30))
cout<<"yes\n";
else
cout<<"no\n";
}//end of answer check 











int main ()
{
answerCheck();
averageTest();
}
