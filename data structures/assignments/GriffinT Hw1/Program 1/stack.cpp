

//INSTRUCTION
//Look for **.
//Update comments, complete exception handling and finish ClearIt to make this complete - Yoshii (CS311)

// =========================================================

//HW1P1 stack
//Your name: Thomas Griffin
//Complier:  g++
//File type: implementation file for stack class

//================================================================

#include "stack.h"
#include <iostream>
using namespace std;
//** Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
	top = -1; // indicate an empty stack 
}

// ** Destructor does not have to do anything since this is a static array.
stack::~stack()
{ // nothing to do 
}
  
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ 
	if (top == -1) 
	  return true; 
	else 
	  return false; 
}
    
// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
{ 
	if (top == MAX-1 ) 
	  return true; 
	else 
	  return false; 
}
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{ 
	if (isFull())//throws overflow if stack is full since a new item can't be added then.  
	  throw Overflow();
	else 
	{ 
	  top++; //moves the top up one
	  el[top] = elem; //sets the new top equal to the element passed
	}
}
	
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{ 
	if (isEmpty()) //throws and underflow if empty because there are no elements to remove
	  throw Underflow();
    else 
	{ 
	  elem = el[top]; //set the element passed equal to the top of the stack and then passes it back
	  top--;//the top of the stack is then removed
	}
}
	  

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{ 

	if (isEmpty()) //throws an underflow if empty since there would be now element to get
	  throw Underflow();
    else 
	{ 	
	  elem = el[top]; //sets the element that was passed equal to the top element of the stack and then passes it back
	}
	
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
  
	if (isEmpty()) 	
      cout <<" [ empty ] "<< endl;
	else
    { 
      for (int i=top; i>=0; i--)//traverses stack displays all items currently in the stack
        cout << el[i] << endl; 
    }
	
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
//sets top =-1
void stack::clearIt()
{
  top=-1;                      
}
