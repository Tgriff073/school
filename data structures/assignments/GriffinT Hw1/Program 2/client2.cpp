//=====================================================
//HW#: Homework 1 queue
//Author: Thomas Griffin
//Compiler:g++
//Type: client file 
//Purpose: Program generates all possible character combinations of the letters a,b and c until the queue overflows
//Program should be compiled with g++ at the same time as queue.cpp 
//The algorithm used was to display the front item from the queue, remove it, then add three new elements to the queue. 
//The program takes the item that was just displayed and add's the letter a to it then adds that string to the queue, then it does the same for 
//the letters b and c
// =========================================================
#include <iostream>
#include "queue.h"
using namespace std;

void addStr(string, queue&);
//creates queue object and adds the strings "a", "b", and "c" to it

int main()
{
	queue myQueue;
	string temp;
	string temp2="";
	myQueue.add("a");
	myQueue.add("b");
	myQueue.add("c");
	
    //loop runs while the queue is less than 27, it'll cut out before that because of an overflow
	while(myQueue.getSize()<=79)
	{
	  try
	  {
	  	
	    myQueue.remove(temp);
	    cout<<temp<<"  ";
	    temp2=temp;
	    addStr(temp2,myQueue);
      
	  }
	  catch (queue::Overflow)
	  {
	    cout << "Error: Queue is Full!" << endl;
		exit(1); }
      catch (queue::Underflow)
	  {
	    cout << "Error: Queue is Empty!" << endl;
		exit(1); 
	  }
	}
	
	return 0;
    
    
}

void addStr(string temp,queue& q )
{
  q.add(temp+"a");
  q.add(temp+"b");
  q.add(temp+"c");
}
