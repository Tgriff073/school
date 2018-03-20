#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void welcome();

int getNum(string);

void getRandom(int);

string getString(string);

int getMon(string);

void display(int);

int main()
{
string prompt="\nEnter the max number\n";
int maxNum=0;
string date="";
int month=0;
welcome();
maxNum=getNum(prompt);
getRandom(maxNum);
prompt="Please enter the date in mm//dd/yyyy format";
date=getString(prompt);
month=getMon(date);
display(month);
return 0;
}

int getNum(string prompt)
{
int num=0;
cout<<prompt;
cin>>num;
return num;
}

void welcome()
{
cout<<"Welcome to the random number generator. This program will generate ten\nnumbers between the number between 1 and the number you enter.\n";
} 

void getRandom(int num)
{
int i=0;
const int NUMBERS = 10;
double randomNum;
srand(time(NULL));
for(i=1;i<=NUMBERS; i++)
{
randomNum=1+(rand()%num);

cout<<setw(20)<<randomNum<<endl;
}

}

string getString(string prompt)
{
string userString="";
cout<<prompt;
cin>>userString;
return userString;
}

int getMon(string date)
{
string month=date.substr(0,2);
int mon=atoi(month.c_str());
return mon;
}

void display(int month)
{
switch(month)
{case 1:
cout<<"The month is January, the previous month was December and the next month is February\n";
break;
case 2:
cout<<"The month is February, the previous month was January, and the next month is March\n";
break;
case 3:
cout<<"The month is March, the previous month was February, and the next month is April\n";
break;
case 4:
cout<<"The month is April , the previous month was March, and the next month is May\n";
break;
case 5:
cout<<"The month is May, the previous month was April, and the next month is June\n";
break;
case 6:
cout<<"The month is June, the previous month was May, and the next month is July\n";
break;
case 7:
cout<<"The month is July, the previous month was June, and the next month is August";
break;
case 8:
cout<<"The month is August, the previous month was July, and the next month is September\n";
break;
case 9:
cout<<"The month is September, the previous month was August, and the next month is October\n";
break;
case 10:
cout<<"The month is October, the previous month was September, and the next month is November\n";
break;
case 11:
cout<<"The month is November, the previous month was October, and the next month is December\n";
break;
case 12:
cout<<"The month is December, the previous month was November, and the next month is January\n";
break;

}

}
