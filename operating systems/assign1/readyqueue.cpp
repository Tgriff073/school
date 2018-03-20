/*      readyqueue CPP
 *      Jan Ocampo & Thomas Griffin
 *      CS 433 - Xiaoyu Zhang
 *      February 13, 2017
 *
 *      This file describes all the possible method calls for the readyqueue data structure, which contains an array of 50 queues
 *      the array is divided up into 3 different levels of priority, low, medium, and high. High priority process have a pid of 15 and lower
 *      medium priorit processes have a pid between 16 and 32, and low priority processes have a priority of 33 to 50
 *      the highest value in each range is kept track of and so is the amount of items in each region
 */                                      

#include "readyqueue.h"
#include <iostream>
using namespace std;
//ctor initializes the overall count and the count of each priority region to 0 and makes the cached priorites all 51
//they are set to 51 since no matter what the first process that is added will always have a higher priority than that
ReadyQueue :: ReadyQueue()
{
	count = 0;
	cachedHigh = 51;
	cachedMedium = 51;
	cachedLow = 51;
        highCount = 0;
        mediumCount = 0;
        lowCount = 0;
	
}
//returns the total amount of processes in the ready queue
int ReadyQueue :: size()
{
	return count;
}
// displays the pid of all current processes in the readyqueue
//the function just loops throught the array of queues and calls the display function of the class queue
void ReadyQueue :: displayQueue()
{
	cout << "Current Processes in queue:\n";
	for(int i = 0; i < 49; i++)
	{
		readyQ[i].display();
	}
}
//inserts the process passed to the function in the parameters into the ready queue
//also sets the status of the new process to ready
//since the parameter is a pointer this also effects the process from the function that called this
//if the priority of the proccess is higher than the cached priority for that processes priority range 
//then the cached priortity for that range is updated, for instance if the cachedHigh is currently 5 and 
//a process with a pid of 4 is added , the cachedHigh is changed to 4
void ReadyQueue :: insertProc(PCB* temp)
{	
	temp->status = "READY";
	readyQ[temp->PID-1].push(temp);
	count++;
	if(temp->PID < 16)//checks to see if the process is of high priority
	{
		highCount++;
		if(temp->PID < cachedHigh)// if the new process has higher priority than the current high for this priority leve, change the current high
			cachedHigh = temp->PID;
	}
	else if(temp->PID < 33)// checks to see if the process if of medium priority
	{
		mediumCount++;
		if(temp->PID < cachedMedium)// if the new process has higher priority than the current high for this priority leve, change the current high
			cachedMedium = temp->PID;
	}
	else // otherwise the process is of low priority
	{
		lowCount++;
		if(temp->PID < cachedLow)// if the new process has higher priority than the current high for this priority leve, change the current high
			cachedLow = temp->PID;
	}
}
//function removes the highest priority process from the queue and returns the pid of that removed process
//function first makes sure that the queue isnt empty and then checks each priority level(high, medium, or low)
//if a process is removed from a range the new highest priority process in the range will be set to the cached priority
//the count for that range is also decremented
//example: the are two processes in the high priority range, meaning they have a pid of 16 or lower. One process has a pid of 10 and the other has
//a pid of 3. When this function is called 3 will be removed from the ready queue and returned to the caller function, the cachedHigh will be updated to 
//10 and the both the overall count and the highCount will be decremented by 1.
int ReadyQueue :: removeHighestProc()
{
	int temp = 0;// holds the pid to be returned, its value will be the return value of the pop fucntion form the queue class
	int tempCache = 0;// temporary place holder to keep track of the current high 
	
	if(size() != 0)
	{
		if(cachedHigh != 0)
		{	
			tempCache = cachedHigh;//keep track of current high
			temp = readyQ[tempCache - 1].pop();//get pid of process being removed
			updateCache(0);//update the cachedHigh value
	 		highCount--;//decrement the amount of process that have high priority
		
		}
		else if(cachedMedium != 0)
		{	
			tempCache = cachedMedium;//keep track of the current highest priority in the medium range
			temp = readyQ[tempCache-1].pop();//get pid of the medium priority process being removed
			updateCache(1);//update to the new highest priority in the medium range
			mediumCount--;//decrement the amount of process that have medium priority
		}
		else if(cachedLow != 0)
		{
			tempCache = cachedLow;//keep track of the current highest priority process in the low range
			temp = readyQ[tempCache-1].pop();//get pid of the low priority process being removed
			updateCache(2);//uodate new highest priority in the low range
			lowCount--;//decrement the amount of processes that have low priority
		}
	}//if readyqueue isnt empty removed the highest priority process from its range and update the highest priority for that range
	else
	{
			
	}//otherwise alert display that the queue is empty
	count--;
	return temp;
}
//function updates the current highest priority process in the specified priority level(ie 0 for high priority, 1 for medium priority, and 2 for low)
//the level to be updated is specified by the parameter passed to the fucntion
//it works by starting at the index of the current highest priority process and looping throught the array of queues and then sets the cached value
//for that region to the index + 1 of the first queue that isnt empty after the current high, if it cant find any queues that have processes, it will
//set the high for that priority level to 51
void ReadyQueue :: updateCache(int priorityLevel)
{
	switch(priorityLevel)
	{
	 	case 0: // high level priority needs to be updated
			if (highCount < 51)
			{

				for (int i = cachedHigh; i < 16; i++)
				{
					if (readyQ[i].size() != 0)
					{
						cachedHigh = i + 1;
						break;
					}
				}

			}
			else 
				cachedHigh = 51;
		case 1: // medium level priority needs
			if (mediumCount < 51)
			{

				for (int i = cachedMedium; i < 34; i++)
				{
					if (readyQ[i].size() != 0)
					{
						cachedMedium = i + 1;
						break;
					}
				}

			}
            else
				cachedMedium = 51;

		case 2: //low level priority cache needs to be updated 
			if (lowCount < 51)
			{

				for (int i = cachedMedium; i < 34; i++)
				{
					if (readyQ[i].size() != 0)
					{
						cachedLow = i + 1;
						break;
					}
				}

			}
			else 
				cachedLow = 51;

	};
}

