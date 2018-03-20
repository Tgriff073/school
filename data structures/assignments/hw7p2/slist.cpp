// ====================================================

//HW3P2 slist
//Your name: Thomas Griffin
//Compiler:  g++
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
//copy constructor: copies the object that was passed to the function into the object that called the 
//constructor. Makes a copy of everything except the memory location of the object being passed.
slist::slist(const slist& Original)
{
	//initialize the new objects values
	this->Front=NULL;
 	this->Rear=NULL;
    this->Count=0;
	//local pointer pointing to the front of the slist object that was passed to the constructor
	Node* P= Original.Front;
	while(P!=NULL)//run till the end of the slist object
	{
		this->addRear(P->Elem);// add the current element in the original slist to the new slist through the rear
		P=P->Next;	// move the pointer to the next node
	}
	
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



//operator=: overload of the assignment operator since the default assignment operator makes bad copies of
//objects. As long as the two slist don't have the same pointer it will empty the slist object that calls this
//function and then copy all the data from the slist that was passed to the function. This function takes an slist object
//by reference but it is constant so it can't be changed. The reason it is passed by reference is so it doesn't have to make
//new space by passing a copy of the object.
slist& slist::operator=(const slist& OtherOne)
{
   
	if (&OtherOne != this)  //check to see if the memory pointers are the same
	{
		char  dummy;//local integer, only purpose is to be passed to deleteRear because it requires an int
		     
		while (! this->isEmpty() )//if the slist object being pointed to by this isn't empty
			this->deleteRear(dummy);  //delete til it is empty
		       
		Node* P= OtherOne.Front; //local Node pointer pointing to the front of the slist object passed to the function
		
		while (P != NULL)  //Run until the end of the slist object
		{
			this->addRear(P->Elem); //add the current element in Node p to the rear of the slist pointed at by this.
			P = P->Next; //move the pointer to the next node
		} //end loop
		         
	}//end if
	return *this;   
}
//operator==: manually compares each node of two slists objects. First checks if either slist is empty, if both are empty it will return true,
//if both aren't empty it will move on to the next step, and if one is empty and the other isn't then it will return false. This function allows
//the comparison of two different slist objects since there is no default comparison operator for objects.
bool slist::operator==( slist& otherOne)
{
	if((this->isEmpty())^(otherOne.isEmpty()))//xor comparison of the two slists, will return false if one of the lists is empty while the other is not
		return false;
	else //otherwise more things need to be checked
	{	if(otherOne.Count!=Count)//if the counts don't match then the slists aren't going to be equal, return false
			return false;
		Node* P = otherOne.Front;// local Node pointer pointing at the Front of the slist object passed to the function
		Node* q = this->Front;// local Node pointer pointing at the Front of the slist object that called the function
		while(q!=NULL)//run until the end of the slist object that called the function
		{
			if(P->Elem!=q->Elem)//if the current items of both slists don't match
				return false;//return the boolean value false
			P=P->Next;//otherwise move both of the pointer
			q=q->Next;//to the next Node of their respective slists.
			
		}//end while
		return true;// if it makes it through the while loop without returning false then return true
	}//end else
}
	
