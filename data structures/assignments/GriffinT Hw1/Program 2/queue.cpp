//=====================================================
//INSTRUCTION
//Update comments
//Fill in the function body

// =========================================================

//HW1P1 queue
//Your name: Thomas Griffin
//Compiler:  g++
//File type: implementation of the Queue class

//================================================================
#include <iostream>
#include "queue.h" 
using namespace std;
  // constructor 
  //rear starts at negative one in order for the wrap around to occur
queue::queue()
{
count =0;
front=0;
rear=-1;
}

//destructor 
//Array is being used to implement the queue so memory is automatically freed
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	return((front+1)==rear);
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
      	return((rear-MAX_SIZE)==front);
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void queue::add(el_t elm)
{
	if(isFull())//throws an overflow exception since we can't add to the queue when it's full
	  throw Overflow();
	else
	{ 
	  rear++;
          el[(rear+1)%MAX_SIZE]=elm;//rear+1 is modded so thaat it raps around once it reaches max_size-1	
	  count++;
	}
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& elm)
{
	if(isEmpty())//will throw an underflow exception since the queue can have an item removed if it is already empty
          throw Underflow();
        else
	{
	  elm = el[((front+1) %MAX_SIZE)];
	  front++;
	  count--; 
	}

}

// PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& elm)
{
	if(isEmpty())//underflow thrown if empty because there wouldn't be a first element to access.
	  throw Underflow();
        else 
	  elm=el[front];
	
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return count;
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
//function loops through the entire queue and displays each item currently located in the queue
void queue::displayAll()
{
	if(isEmpty())
	{
	  cout<<" [ EMPTY ] "<<endl;
	  return; 
	}
	cout<<"[ ";

	for(int i=front;i<MAX_SIZE;i++)//starts at wherever the front is
	{
	  cout << el[((i)%MAX_SIZE)]<<"  ";// and displays all items in queue
 	   
	}
        cout<<" ]"<<endl;
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue::goToBack()
{
	if(isEmpty())//underflow thrown if empty since there would be nothing to move
	  throw Underflow();
	if(getSize()==1)//if there is only one item in queue it does nothing since the front would technically be at the back
	  return;
	else
	rear=front;
	front=(front+1)%MAX_SIZE;
}




