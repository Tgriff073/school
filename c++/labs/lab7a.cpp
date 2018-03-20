#include <iostream>
#include <fstream>

using namespace std;
int getNum();
void checkNumDisplay(int);
int lineCheck();
string getString();
void displayOdd();
void answerCheck();
enum Month {January, February, March, April, May, June, July, August, September,October, November, December};
void displayMonth(Month);

int main()

{
int userNum=0;

  string gLine="";
  userNum=getNum();
  checkNumDisplay(userNum);
  userNum=lineCheck();
  cout<<"There are "<<userNum<<" lines in the file input.dat"<<endl;
  gLine=getString();
  cout<<"The string stored on the line you requested is: "<<gLine<<endl;
  displayOdd();
  answerCheck();
  Month month=October; 
  displayMonth(month);
return 0;
}//end of main

int getNum()
{
  int userInput=0;
  cout<<"Please enter a number:"<<endl;
  cin>>userInput;
return userInput;
}//end of userInput

void checkNumDisplay(int userNum)
{
  cout<<"The even numbers between "<<userNum<<" and 0 are:\n";
  if(userNum>0)
{  while(userNum>0)
{
    if (!(userNum%2))
{
  cout<<userNum<<endl;

  userNum--;
}//end of if userNum check
  else
{

 userNum--;

}//end of else userNum check
}//end of while loop display
}
else
{
while(userNum<0)
 {
if(!(userNum%2))
{
cout<<userNum<<endl;
userNum++;
}
else
{
userNum++;
}
}
}//end of if check
}//end of checkNumDisplay

int lineCheck()
{
  int numOfLines=0;
  string gLine="";
  ifstream fin;
  fin.open("input.dat");
  if (fin.fail())
{
  cout<<"File not found, make sure input.dat has not been deleted or moved.";
  exit(1);
}
  while(!fin.eof( ))
{

  getline(fin, gLine);
  numOfLines++;
}

 

  fin.close();
return numOfLines;
}

string getString()
{
  ifstream fin;
  fin.open("input.dat");
  if (fin.fail())
{
  cout<<"File not found, make sure input.dat has not been deleted or moved.";
  exit(1);
}

  int lineNum=0;
  int counter=0;
  string fromFile="";
  cout<<"Please enter a line number that you would like to get a string from:"<<endl;
  cin>>lineNum;
  while(lineNum>counter)
{

  counter++;
  getline(fin, fromFile);

}
  getline(fin, fromFile);
  fin.close();
return fromFile;
}
void displayOdd()
{
  ifstream fin;
  fin.open("input.dat");
  if (fin.fail())
{
  cout<<"File not found, make sure input.dat has not been deleted or moved.";
  exit(1);
}

  int lineNum=0;
  int counter=0;
  string fromFile="";
  
  cout<<"The strings stored on the odd lines of input.dat are:"<<endl; 
  while((lineNum>counter&&lineNum<10))
{

  
  getline(fin, fromFile);
  if(counter%2==0)
{    counter++;
    lineNum++;
}
  else
{   cout<<fromFile<<endl;
    counter++;
    lineNum++;
}

}
  getline(fin, fromFile);

}


void answerCheck()
{
  cout<<"Part One A:\n";
  int num=0;
  while(num<=20)
{
  num++;
  cout<<num<<" ";
}

  cout<<"\nPart one C:\n1)\n";
  int i =5;
  while(i<10)
{
  cout<<i<<endl;
  i++;
}
  i=5;
  cout<<"\n2)";
while(i<=10)
{
  cout<<i<<" ";
  i++;
}
  i=5;
  cout<<"\n3)";
while (i>4)
{
cout<<i<<endl;
i--;
}

/*cout<<"\n4)";
i=0;
while(i<10)
{
cout<<i<<" ";
}
*/


 }  
void displayMonth(Month month)
{
 

switch(month)
{
case January:
cout<<"January\n";
break;
case February:
cout<<"February\n";
break;
case March:
cout<<"March\n";
break;
case April:
cout<<"April\n";
break;
case May:
cout<<"May\n";
case June:
cout<<"June\n";
break;
case July:
cout<<"July\n";
break;
case August:
cout<<"August\n";
break;
case September:
cout<<"September\n";
break;
case October:
cout<<"October\n";
break;
case November:
cout<<"November\n";
break;
case December:
cout<<"December\n";
break;
default:break;

}
}
