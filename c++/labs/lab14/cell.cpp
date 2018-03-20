#include <iostream>
#include "cell.h"
using namespace std;
void getInfo(Cell&);
void displayC1(Cell);
void displayBoth(Cell,Cell);
void popArray(Cell[]); 
void displayArray(Cell[]);
void changeArray(Cell[]);
int main()
{
  Cell cell;
 // cout<<cell.getColor();
 // cell.changeColor();
 // cout<<cell.getColor();
 // cell.changeColor();
 // cout<<cell.getColor();
 // cell.changeColor();
 // cout<<cell.getColor();
  getInfo(cell);
  displayC1(cell);
  Cell cell2;
  Cell("7608289229","Cricket",1);
  cell=cell2;
  displayBoth(cell,cell2);
  Cell cellar[6];
  popArray(cellar);
  displayArray(cellar);
  changeArray(cellar); 
  displayArray(cellar);
 //system("PAUSE");
}

void Cell::setNumber(string num)
{
  phoneNumber=num;
}

void Cell::setCarrier(string carr)
{
  carrier=carr;
}

void Cell::changeColor(int col)
{
  if(color!=2)
    col++;
 
   else
    col=0;
color=col;
}

string Cell::getNumber() const
{
  return phoneNumber;
}

string Cell::getCarrier() const
{
  return carrier;
}

string Cell::getColor() const
{
  string col="";
  switch(color)

 {
  case 0:
    col="Cyan";
    break;
 
  case 1:
    col="Yellow";
    break;
 
  case 2:
    col="Magenta";
    break;
 }
return col;
}

Cell::Cell()
{
  carrier="ATT";
  phoneNumber="7608886622";
  color=0;
}

Cell::Cell(string num, string carr, int cl)
{
phoneNumber=num;
carrier=carr;
color=cl;
}

void getInfo(Cell& cell)
{
  string phone="";
  string carr="";
  cout<<"Please enter the carrier you have for your cellphone"<<endl;
  cin>>carr;
  cout<<"Now please enter your phone number"<<endl;
  cin>>phone;
  cell.setCarrier(carr);
  cell.setNumber(phone);
}

void displayC1(Cell cell)
{
  cout<<"The carrier for this cellphone is: ";
  cout<<cell.getCarrier()<<endl;
  cout<<"The phone number currently registered for cellphone one is: ";
  cout<<cell.getNumber()<<endl;
  cout<<"The phone is "<<cell.getColor()<<endl;

}

void displayBoth(Cell cell, Cell cell2)
{

  cout<<"The carrier for cellphone one is: ";
  cout<<cell.getCarrier()<<endl;
  cout<<"The phone number currently registered for cellphone one is: ";
  cout<<cell.getNumber()<<endl;
  cout<<"The phone is "<<cell.getColor()<<endl;
  cout<<"The carrier for cellphone two is: ";
  cout<<cell2.getCarrier()<<endl;
  cout<<"The phone number currently registered for cellphone two is: ";
  cout<<cell2.getNumber()<<endl;
  cout<<"The phone is "<<cell2.getColor()<<endl;
}

void popArray(Cell cell[6])
{
  for(int i=0;i<6;i++)
  {
     Cell cell2("7608929292","Tmobile",2);
     cell[i]=cell2;

  }
}

void displayArray(Cell cell[6])
{

  for(int i=0;i<6;i++)
  {
    cout<<"The carrier of cell "<<i+1<<" is "<<cell[i].getCarrier()<<endl;
    cout<<"The number of cell "<<i+1<<" is "<<cell[i].getNumber()<<endl<<endl;
  }
}

void changeArray(Cell cell[6])
{
cell[1].setCarrier("Cricket");
cell[2].setNumber("7608912343");
cell[3].changeColor(1);
cell[5].setCarrier("ATT");
cell[4].setNumber("58948593489");
cell[0].changeColor(0);
}
