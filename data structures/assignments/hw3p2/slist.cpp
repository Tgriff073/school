// ====================================================

//HW3P2 slist
//Your name: Thomas Griffin
//Complier:  g++
//File type: class implementation for slist class

//=====================================================
#include "slist.h"
#include <iostream>
using namespace std;
//constructor
//does the same thing as the constructor for the parent class
slist::slist()   
{
	Front=NULL;
	Rear=NULL;
	Count=0;
}
//search: Takes an el_t by value and uses it as a key. The key is checked against the current values in the list.
//if the key if found then the index where it is found is returned, otherwise 0 is returned.
int slist::search(el_t key)
{
	Node* p=Front;//local pointer set to the front of the list
	int ind=0;//value to be returned 
	while(p!=NULL)//while loop runs until the key is found or the pointer is pointing to NULL
	{
		ind++;
		if(p->Elem==key)//if the current node has an element equal to key
			return ind;//return the index of current node
		p=p->Next;
	}

		return 0;//if the number isn't found 0 will be returned
}
//replace:Takes an el_T and an int by value. The el_t holds the new value to be put into the list and
//the int holds the value of the index where the new number should be put. As long as the index is greater
//than one and less than count it will replace the value of the node at index I with the value that was passed
//to the function through newNum
void slist::replace(el_t newNum,  int I)
{
	Node* p=Front;//local pointer to the front of the list
	if(I<1||I>Count)//if the requested index is less than one or greater than the current size of the list.
	{
		throw OutOfRange();//throw an OutOfRange exception
		return;
	}
	for(int j=1;j<I;j++)//loop until the ith Node
		p=p->Next;
	p->Elem=newNum;//ith Node element is changed to the value passed
	Rear->Next=NULL;//Rear->Next is set to NULL in case something weird happened to the list 
}




slist& slist::operator=(const slist& OtherOne)
  {
    cout<<"What";
     if (&OtherOne != this)  
      {
     int dummy;
     cout<<"the";
        while (! this->isEmpty() )
                   this->deleteRear(dummy);  
        cout<<"heck";
        Node* P;  
        cout<<"is";
        P = OtherOne.Front;
        cout<<"Going";
        while (P != NULL)  
        {
        	cout<<"\n"<<P->Elem<<"                    element"<<endl;
           this->addRear(P->Elem);    
           P = P->Next;                
         } 
         cout<<"\nhere";
      }          
     return *this;   
  } 

