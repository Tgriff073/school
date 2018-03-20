#include <iostream>
using namespace std;

int readOneChar();

int main()
{
int ch; 
ch=readOneChar();
cout<<ch<<endl;
cin.ignore();
return 0;
}
int readOneChar()
{
int key;
cout<<"presskey";
key=getch();
return key;
}
