/*
Thomas Griffin
All of the operations for the family class are listed here.
The only input it has is the transactionfile which will be
processed in the ReadTransactionFile each function corrseponds
with a command.
5/7/15
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Family.h"
#include <fstream>
using namespace std;
bool Family::success=true;
bool Family::failure=false;
typedef Husband* Dadptr;

//------------------------------------------
 		//Destructor	5/7/15
//------------------------------------------
Family::~Family()
{
  if(top==NULL)
   return;
  Husptr husband=top;
  Wifeptr wife=husband->myWife;
  Childptr child=wife->myChild;
  while(husband!=NULL)
  { 
    delete wife;
    delete husband;;
    while(child!=NULL)//traverses child list
    {
     delete child;
     child=child->mySibling;   
    }//end inner
    wife=husband->myWife;
    husband=husband->nextFamily;;
  }//end outter
}//end destructor
//------------------------------------------


//------------------------------------------
/* 5/7/15	SearchHus
  function takes in a long that holds the 
  value of an id for a husband. The function
  looks for a husband in the linked list 
  that has the same id. If there is a match
  a pointer to that husband is returned, 
  otherwise the function returns NULL
*/
//------------------------------------------
Husptr Family::searchHus(long id)
{
Husptr p=top;
  while(p!=NULL)
  {
    if(p->ssn==id)
      return p;
    p=p->nextFamily;
  }
  return NULL;

}//end searchHus
//------------------------------------------

//------------------------------------------
/* 5/7/15	searchDad
  Function calls the searchHus function. Only
  here to make the code for the child related
  functions to make more sense.
*/
//------------------------------------------
Husptr Family::searchDad(long id)
{
  return searchHus(id);
}
//------------------------------------------


//------------------------------------------
/* 5/7/15	AddHusband
  Function takes in a long holding a ssn and
  two longs one holding the first name the 
  second holding the last name. With the 
  info passed it makes a new Husband node and
  adds it to the top of the list.The only Local 
  variable is p which is a temporary pointer
  to the new husband created.
*/		
//------------------------------------------
bool Family::AddHusband(long id,string fn,string ln)
{
  Husptr p=searchHus(id);
  if(p!=NULL)
    return Family::failure;
  p=new Husband(id,fn,ln);
  p->nextFamily=top;
  top=p;
  return Family::success;
}//emd AddHusband
//------------------------------------------


//------------------------------------------
/* 5/7/15	AddWife
  Function adds wife to linked list to a husband
  that corresponds to the id passed to the function.
  The function is also passed another long
  that holds the wife's snn and two strings,
  one that holds her first name and one that
  holds her last name. Local variables are p
  and w. P is a temp pointer to the husband
  and W is a temp pointer to the wife being 
  created.
*/
//------------------------------------------
bool Family::AddWife(long id,string fn, string ln, long husId)
{
  Husptr p=searchHus(husId);
  if(p==NULL)
    return Family::failure;
  Wifeptr w=new Wife(id,fn,ln);
  p->myWife=w;
  return Family::success;
}//end AddWife
//------------------------------------------

//------------------------------------------
/*  5/7/15	AddAChild
  Function is passed two longs, one for the
  childs ssn and another for his fathers.
  function creates a child node and adds it
  to the linked list via the mom. Local 
  variables are p,w,t, and c. P is a pointer
  to the father of the child, w is a pointer
  to the mother of the child and c and t are
  pointers to children. The new child being 
  added is pointed to by c.
*/
//------------------------------------------
bool Family::AddAChild(long id, string fn,string ln,long dadId)
{
  Dadptr p=searchDad(dadId);
  if(p==NULL)
    return Family::failure;
  Wifeptr w=p->myWife;
  Childptr t =w->myChild;
  Childptr c= new Child(id,fn,ln);
  w->myChild=c;
  c->mySibling=t;
  return Family::success;
}
//------------------------------------------

//------------------------------------------
/*  5/7/15	Remove Husband
  Removes a husband from the linked list.
  If he has a wife and kids it will remove
  them first. Function takes one long that
  holds the value of the husbands ssn. 
*/
//------------------------------------------
bool Family::RemoveHusband(long id)
{
 Husptr h=searchHus(id);
 Husptr temp,curr;
 Wifeptr w=h->myWife;
 if(h==NULL)
   return Family::failure;
 if(w==NULL&&w->myChild==NULL)
  {
   if(h==top)
   {
      temp=top;
      top=top->nextFamily;
   }
   else
   {
     curr=top;
     while(curr->nextFamily->ssn!=id)//rebuilds list
       curr=curr->nextFamily;
     temp=curr->nextFamily;
     curr->nextFamily=curr->nextFamily->nextFamily;
   }
   delete temp;
  }//end check wife null and kids null
 else if(w!=NULL)
 {
  RemoveWife(h->ssn);
  RemoveHusband(id);
 }//end check wife !null
return Family::success; 
}//end RemoveHusband
//------------------------------------------

//------------------------------------------
/*5/7/15	RemoveWife
  Removes wife attached to the husband whose
  ssn was passed to this function. If the
  wife has kids it will remove them before
  removing here. 
*/
//------------------------------------------
bool Family::RemoveWife(long husId)
{
  Husptr h=searchHus(husId);
  Wifeptr w=h->myWife;
  Childptr c=w->myChild;
  if(w->myChild==NULL)
    delete w;
  else 
  {
    while(c!=NULL)//removes all children linked
    {             //linked to a specific mother. 
      RemoveAChild(h->ssn,c->ssn);
      c=c->mySibling;
    }//end loop
  }//end else
  return Family::success;
}//end RemoveWife
//------------------------------------------


//------------------------------------------
/*  5/7/15	RemoveAChild
  Function is passed two longs, one holding 
  the fathers ssn and the other holding the
  childs ssn. The function removes the child
  from the list.   
*/
//------------------------------------------
bool Family::RemoveAChild(long dadID,long id)
{
  Dadptr d=searchDad(dadID);
  Wifeptr w=d->myWife;
  Childptr c=w->myChild;
  cout<<c->fName<<endl;
  while(c!=NULL)
  {
  if(c->ssn==id)
  {
    if(c->mySibling==NULL)
      delete c;
    else
    {
     w->myChild= c->mySibling;//sets next child as child of mom.
     delete c;
     return Family::success;
    }//end else
    return success;
  }//end ssn check
  c=c->mySibling;
  }  //end loop
   
 return failure;

}//end RemoveAChild
//------------------------------------------

//------------------------------------------
/* 5/7/15	PrintAFamily
  Function is passed on long which holds the
  ssn of the father of a family. Function 
  then prints the info for that family. 
*/
//------------------------------------------
bool Family::PrintAFamily(long id)
{
  Husptr p=searchHus(id);
  if(p==NULL)
    return Family::failure;
  cout<<"Husband info: "<<endl;
  cout<<setfill('-')<<setw(15)<<" "<<endl;
  cout<<"SSN: "<<p->ssn<<endl;
  cout<<"First name: "<<p->fName<<endl;
  cout<<"Last name: "<<p->lName<<endl;
  cout<<setw(15)<<" "<<"\n\n";
  Wifeptr w=p->myWife;
  if(w==NULL)
    return Family::success;
  cout<<"Wife info: "<<endl;
  cout<<setw(15)<<" "<<endl;
  cout<<"SSN: "<<w->ssn<<endl;
  cout<<"First name: "<<w->fName<<endl;
  cout<<"Last name: "<<w->lName<<endl;
  cout<<setw(15)<<" "<<"\n\n";
  Childptr c=w->myChild;
  while(c!=NULL)
  {
  cout<<"Children info: "<<endl;
  cout<<setfill('-')<<setw(15)<<" "<<endl;
  cout<<"SSN: "<<c->ssn<<endl;
  cout<<"First name: "<<c->fName<<endl;
  cout<<"Last name: "<<c->lName<<endl;
  cout<<setw(15)<<" "<<"\n\n";
  c=c->mySibling;
  }
  return Family::success;

}//end PrintAFamily
//------------------------------------------


//------------------------------------------
/* 5/7/15    PrintAllFamilies
  Function prints all the the families in the
  linked list. Function uses the function 
  PrintAFamily to print each family individually.
*/
//------------------------------------------
bool Family::PrintAllFamilies()
{

  Husptr p=top;
  while(p!=NULL)
  {
    PrintAFamily(p->ssn);
    p=p->nextFamily;
  }
  return Family::success; 
}//end PrintAllFamilies
//------------------------------------------

//------------------------------------------
/* 5/7/15     ReadTransactionFile
  Function goes through transactionfile.txt
  and takes in a command, depending on the 
  command it will add or remove someone from
  a linked list, or print the linked list.
  Fucntion dispays error if a function call
  fails.
*/
//------------------------------------------
void Family::ReadTransactionFile()
{
  ifstream fin("transactionfile.txt");
  if(!fin)
  {  
    cout<<"Failed to open file. Program exiting."<<endl;
    return;
  }
  
  string cmd,fname,lname;
  long id;
  while(fin>>cmd)
  {
    cout<<"Transaction: "<<cmd<<endl;
    cout<<setfill('*')<<setw(20)<<" "<<endl;
    
    if(cmd=="AddHusband")
    {
      fin>>id>>fname>>lname;
      if(AddHusband(id,fname,lname)==Family::success)
        cout<<"Successfully added husband: "<<fname<<endl;
      else
        cout<<"Failed to add husband: "<<fname<<endl; 
    }//end AddHusband
    else if(cmd=="AddWife")
    {
      long husId=0;
      fin>>id>>fname>>lname>>husId;
      if(AddWife(id,fname,lname,husId)==Family::success)
        cout<<"Successfully added wife: "<<fname<<endl;
      else
        cout<<"Failed to add wife: "<<fname<<endl;
    }//end AddWife
    else if(cmd=="AddAchild")
    {
     long dadId;
     fin>>id>>fname>>lname>>dadId;
     if(AddAChild(id,fname,lname,dadId)==Family::success)
       cout<<"Successfully added child: "<<fname<<endl;
     else 
       cout<<"Failed to add child: "<<fname<<endl;
    }//end AddAchild
    else if(cmd=="RemoveHusband")
    {
      fin>>id;
      if(RemoveHusband(id)==Family::success)
        cout<<"Successfully removed husband: "<<id<<endl;
      else 
        cout<<"Failed to remove husband: "<<id<<endl;
    }//end RemoveHusband
    else if(cmd=="RemoveWife")
    {
      fin>>id;
      if(RemoveWife(id)==Family::success)
        cout<<"Successfully added wife :"<<id<<endl;
      else 
        cout<<"Failed to add wife: "<<id<<endl;
    }//end RemoveAWife
    else if(cmd=="RemoveAchild")
    {
      long dadId;
      fin>>dadId>>id;
      if(RemoveAChild(dadId,id)==Family::success)
        cout<<"Successfully removed child: "<<id<<endl;
      else 
        cout<<"Failed to remove child: "<<id<<endl;
    }//end RemoveAChild
    else if(cmd=="PrintAFamily")
    {
      fin>>id;
      if(PrintAFamily(id)!=Family::success)
        cout<<"Failed to print family of Husband: "<<id<<endl;  
    } //end PrintAFamily
    else if(cmd=="PrintAllFamilies")
    {
      PrintAllFamilies();
    }
    cout<<setfill('*')<<setw(20)<<"\n\n";
   }//end PrintAllFamilies
     
}//end ReadATransactionFile
//------------------------------------------
