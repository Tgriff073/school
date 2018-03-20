/* 	Ready queue header file
 * 	Jan Ocampo & Thomas Griffin
 * 	CS 433 - Xiaou Zhang
 * 	February 13, 2017
 * 	
 * 	This defines the readyqueue class, it keeps track of the count of all total process in the ready queue, the current highest priority
 * 	processes in three different priority levels(high has a pid of 1-15, medium has a pid of 16 to 32, and low has a pid of 33 to 50)
 * 	the amount of processes in each range is also kept track of
 */
#ifndef READYQUEUE_H
#define READYQUEUE_H
#include "queue.h"

class ReadyQueue
{
	public:
		void insertProc(PCB*);// adds the process that is passed in through pararmeter to the readyqueue, can modify the process
		int size();// returns the current amount of processes in the readyqueue
		void displayQueue();//displays all processes currently in the queue
		int removeHighestProc();// removes the highest priority process from the queue and will call updateCache
		void updateCache(int);//will update the highest priority process in the priority range specified by the parameter
		ReadyQueue();
	private:
		Queue readyQ[50];//an array of 50 queues kind of like a hashtable, and our key is the cachedHigh, cachedMedium, or cachedLow
		int count;//total amount of items in the queue
		int cachedHigh;//current highest priority process in the high priority range
		int cachedMedium;//current highest priority process in the medium range
		int cachedLow;// current lowest priority process in the low range
		int highCount;// current amount of processes in the high range
		int mediumCount;// current amount of processes in the medium range
		int lowCount;// current amount of processes in the low range
};
#endif
