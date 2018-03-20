#include <iostream>
#include <fstream>
#include "list.h"
using namespace std;

void fileIO(ifstream&, List&);
bool openFile(ifstream&);
void closeFile(ifstream&);
void display(List&);
void displayNewFormat(List&);
void addLineToList(ifstream&, List&);
string convertMonth(string);
int main()
{

ifstream fin;
List list;
fileIO(fin,list);
display(list);
list.Reset();
list.SelSort();
displayNewFormat(list);

return 0;
}//end of main

void fileIO(ifstream& fin,List& list)
{
  openFile(fin);
  while(!fin.eof())
  {
    addLineToList(fin,list);
  }
  closeFile(fin);

}//end fileIO

bool openFile(ifstream& fin)
{
  fin.open("input.dat");
  if(fin.fail())
    return true;
}

void closeFile(ifstream& fin)
{
fin.close();
}

void addLineToList(ifstream& fin,List& list)
{
string str="";
getline(fin,str);
list.Insert(str);
}

void displayNewFormat(List& list)
{
  for(int i=0;i<list.Length();i++)
  {
  string date=list.GetNextItem();
  string year=date.substr(0,4);
  string month=date.substr(4,2);
  string day=date.substr(6,2);
  cout<<date<<" is "<<convertMonth(month)<<" "<<day<<", "<<year<<endl;
  }
   
}
void display(List& list)
{
  list.Reset();
  for(int i=0;i<list.Length();i++)
  {
  cout<<list.GetNextItem()<<endl;
  }
}

string convertMonth(string m)
{
if(m=="01")
return "January";
else if(m=="02")
return "February";
else if(m=="03")
return "March";
else if(m=="04")
return "April";
else if(m=="05")
return "May";
else if(m=="06")
return "June";
else if(m=="07")
return "July";
else if(m=="08")
return "August";
else if(m=="09")
return "September";
else if(m=="10")
return "October";
else if(m=="11")
return "November";
else if(m=="12")
return "December";


}
