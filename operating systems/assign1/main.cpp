#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>
#include "readyqueue.h"
using namespace std;

void testOne(vector<PCB*>);
void testTwo(vector<PCB*>);
void driver();

int main()
{
	driver();
	return 0;
}

void driver()
{
	cout << " Programmed by Jan Ocampo & Thomas Griffin\n"
	cout << "Would you like to run test 1 or test 2(type 1 or two to select)\n"
	int decision =0;
	cin >> decision;
	if(decision != 1 || decision != 2)
	{
		cout << "you didnt enter a valid choice, ending program\n";
	}
		
	vector<PCB*> pcb_table;
	for (int i = 1; i < 21; i++)
	{
		PCB* temp = new PCB();
		temp->PID = i;
		pcb_table.push_back(temp);
	}
	if (decision == 1)
		testOne(pcb_table);
	else
		testTwo(pcb_table);
}

void testOne(vector<PCB*> pcb_table)
{
	ReadyQueue q1 = ReadyQueue();
	
	q1.insertProc(pcb_table[4]);
	q1.insertProc(pcb_table[0]);
	q1.insertProc(pcb_table[7]);
	q1.insertProc(pcb_table[10]);
	
	q1.removeHighestProc();
	q1.displayQueue();
	q1.removeHighestProc();
	q1.displayQueue();
	q1.insertProc(pcb_table[2]);
	q1.insertProc(pcb_table[6]);
	q1.insertProc(pcb_table[1]);
	q1.insertProc(pcb_table[11]);
	q1.insertProc(pcb_table[8]);
	while (q1.size() > 0)
	{
		q1.removeHighestProc();
		q1.displayQueue();
	}
}
void testTwo(vector<PCB*> pcb_table)
{
	ReadyQueue q1 = ReadyQueue();
	srand(time(NULL));
	int operation = 0;
	int index = 0;
	timeval start;
	timeval end;
	gettimeofday(&start, NULL);
	for (int i = 0; i < 1000000; i++)
	{
		operation = rand() % 10;
		index = rand() % 19 ;
		if (operation % 2 || q1.size() < 1)
		{
			q1.insertProc(pcb_table[index]);
		}
		else
			q1.removeHighestProc();
	}
	q1.displayQueue();
	gettimeofday(&end, NULL);
	cout << "Elapsed time: " << end.tv_sec - start.tv_sec << endl;
}
