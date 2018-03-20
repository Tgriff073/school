#include <iostream>
using namespace std;

void functionOneA()
{

int extraMoney=300;
cout<<"The recommended choice is:";
if(extraMoney >500) 
cout<<"celebrate"<<endl;
if (extraMoney > 300)
cout<<"pay down debt"<< endl;
if (extraMoney > 150)
cout<<"buy gasoline"<<endl;
if (extraMoney>0)
cout<<"save"<<endl;
cout<<"if you have $"<<extraMoney<<endl;

}
void functionOneB()

{
int aValue;
cout<<aValue<<endl;
aValue =100;
if (aValue=50)
   cout<<aValue<<endl;
aValue+=100;
cout<<aValue<<endl;

}
void functionOneC()
{
cout<<(20+2*3%7-7/3.5);

}

int main()
{
functionOneA();
functionOneB();
functionOneC();
}
