

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
//** Constructor does nothing since vectors don't have a top
stack::stack()
{ 
}


stack::~stack()
{ 
clearIt();
}
  
//returns true if the vector is of size 0, returns false otherwise
bool stack::isEmpty()
{ 
	return ( el.size()==0); //if the size of the vector is 0 that means the stack is empty and true is returned, otherwise false is returned
}
    
//always return false since a vector stack can't be full
bool stack::isFull()
{ 
	 return false; 
}
  
// ** pushes the element passed to the top of the stack using the built in vector function push_back
void stack::push(el_t elem)
{ 
	el.push_back(elem);
}
  

// underflow error is thrown if the stack is empty, checked by calling isEmpty
//element passed receives the value of the last item of the vector which is the top of the stack
//then pop_back removes the top of the stack, or the back of the vector
void stack::pop(el_t& elem)
{
	if(isEmpty())
	  throw Underflow();
	elem=el.back();
	el.pop_back();
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{
	if(isEmpty())
	  throw Underflow();
	elem=el.back();
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{  

	if (isEmpty()) 
	  cout <<" .[ empty ]. "<< endl;
    	else
	{ 
	  for (int i=el.size()-1; i>=0; i--)
       	    cout << el[i] << endl; 
	}
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
//????**
void stack::clearIt()
{
	el.clear();                      
}
