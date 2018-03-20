/*      Queue Header File
 *      Jan Ocampo & Thomas Griffin
 *      CS 433 - Xiaoyu Zhang
 *      February 13, 2017
 *
 *      This defines the queue class, a queue is used to store processes that have the same PID
 *                                      
 */

#ifndef	QUEUE_H
#define QUEUE_H
#include "PCB.h"

class Queue{

private:

	PCB *rear; //points to the rear of the queue, when the queue is empty it will be null, otherwise it points to the last processes added to it
	PCB *front; //points to the front of the queue, when the queue is empty it will be null, otherwise it points to the first process added to it
	int count; // keeps track of the amount of processes in the queue
public:

	Queue(); //ctor for queue, initializes all the members
	void push(PCB*); //adds the process that is passed to it to the queue
	int pop(); // removes the front of the queue and returns the PID of the process that was removed, return value will be between 0-50
	void display();// displays all the process in this queue
	int size(); //returns the amount of processes in this queue
};
#endif // QUEUE_H
