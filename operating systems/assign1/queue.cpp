/*      Queue CPP file
 *      Jan Ocampo & Thomas Griffin
 *      CS 433 - Xiaoyu Zhang
 *      February 13, 2017
 *
 *      This file defines all the method calls for the queue data structure, methods described are 
 *      ctor, push, pop, display, and size                                    
 *
 */

#include "queue.h"
#include <iostream>
using namespace std;

//fucntion initializes a queue object, takes no input
//it modifies the front and rear pointer of the queue by setting them equal to null
//it also sets count to 0
Queue::Queue() {

	rear = NULL;
	front = NULL;
	count = 0;
}
//function adds a new process to the queue, the parameter holds the process to be added to the queue
//the function also changes the status of the process to running
//if the queue is empty it the front and rear pointers will point to the process
//otherwise only the rear pointer will point to it
//the count of process in the queue is then incremented by 1
void Queue::push(PCB* temp) 
{
	temp->next = NULL;
	temp->status = "RUNNING";
	if (front == NULL)
	{
		front = rear = temp;
		rear->next = NULL;
	}
	else
	{
		rear->next = temp;
		rear = temp;
		rear->next = NULL;
	}

	count++;

}
//pops the top of the queue off and returns the pid of the process removed
//if the queue is empty it will the function will return 0
//otherwise the output should be anywhere from 1-50
int Queue::pop() 
{
	int temp = 0;
	if (front == NULL)
		;
	else
	{
		temp = front->PID;
		front = front->next;
	}
		
	
	return temp;
}
//displays the Pid of all the processes in this queue
//the queue is not modified at all in this function
void Queue::display() {
	PCB *temp = new PCB;
	if (this->count)
	{
		temp = front;
		
		if (front == NULL);
		else {
			while (temp != NULL) {
				cout << "PID# " << temp->PID << endl;
				temp = temp->next;
			}
		}
	}
}
//returns the amount of items in the queue
//the queue is not modified at all in this function
int Queue::size()
{
	return count;
}
