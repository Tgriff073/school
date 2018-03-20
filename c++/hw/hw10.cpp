/*
a.This program will go through a file called zip.dat and count how many zip codes are listed, It will then count how many of those are po box zip codes and display those po box zip codes in city state zip code format. 
b. Thomas Griffin
c. CS 111 Programming Assignment
d. SEC30-50041 
e. 11/9/14 
f. 11/11/14
g. n/a
h.yes
*/
#include <iostream>
#include <fstream>
using namespace std;

enum PoBox{Pobox,Unique,APO,Blank};

 struct ZipInfo
 {
  string zip;
  string state;
  PoBox po;
  char pc;
  string city;
  void init(ZipInfo&);
  void work(ZipInfo&,int, int&);
 
 };//end of struct


void driver();
bool openFile(ifstream&);
void closeFile(ifstream&);
void getZipNum(int&, ifstream&);
void getInfo(ZipInfo&, ifstream&,int, int&);
void display(ZipInfo,int);

int main()
{
  driver();

return 0;
}//end main

void driver()
{
  int numPo=0;
  ZipInfo zp;
  ifstream fin;
  int zipNum=0;
  if (openFile(fin))
 {  cout<<"File could not be opened, please make sure it has not been deleted or moved\n";
     closeFile(fin);
     return;
 }//end of if(displays error message if file fails to open
  getZipNum(zipNum,fin);
  zp.init(zp);
  getInfo(zp,fin,zipNum,numPo);
 // cout<<zipNum<<endl;
}//end of driver

bool openFile(ifstream& fin)
{
  fin.open("zip.dat");
  if(fin.fail())
    return true;
  else 
    return false;
}//end of openFile

void closeFile(ifstream& fin)
{
fin.close();
}//end of closeFile

void getZipNum(int& num,ifstream& fin)
{
string temp="";

while(!(fin.eof()))
 {
  getline(fin, temp);
  num++;
 }//end of loop(counting lines
num-=4;
}

void ZipInfo::init(ZipInfo& zp)
{
zp.state="";
zp.city="";
zp.zip="";
zp.po=APO;
zp.pc='a';
}

void getInfo(ZipInfo& zp,ifstream& fin,int num,int& numPo)
{
  
  string temp="";
  fin.close();
  fin.open("zip.dat");
  getline(fin, temp);
  getline(fin,temp);
    for(int i=0;i<num;i++)
   {
      getline(fin,temp);
      zp.zip=temp.substr(0,5);
      zp.state=temp.substr(5,2);
      zp.city=temp.substr(7,28 );
      zp.pc=temp[35];
      zp.work(zp,num,numPo);
     
    
   }
cout<<"There are "<<num<<" valid zip codes in the file"<<endl;
cout<<numPo<<" of them are PO box zip codes"<<endl;
}

void ZipInfo::work(ZipInfo& zp,int numZip,int& numPo)
{ 
  
  if(zp.pc=='P')
 {  
    zp.po=Pobox;
    numPo++;
 } 
  else if(zp.pc=='U') 
    zp.po=Unique;
  else if(zp.pc=='M')
    zp.po=APO;
  else
    zp.po=Blank;
   
  switch(zp.po)
 {

  case APO:
  case Unique:
  case Blank:
    break;
  
  case Pobox:
    display(zp,numZip);

  
 }

}

void display(ZipInfo zp,int numZip)
{
  cout<<zp.city<<" | "<<zp.state<<" "<<zp.zip<<endl;
}
