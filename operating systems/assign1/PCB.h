/* 	PCB Header File
	Jan Ocampo & Thomas Griffin
	CS 433 - Xiaoyu Zhang
	February 13, 2017

	This is the process control block data structure that represents processes in the system.
*/

#ifndef PCB_H
#define PCB_H
#include <string>

struct PCB {
	std::string status;
	int PID;
	PCB* next;
	PCB() { status = "NEW"; PID = 0; next = NULL;};
	PCB(int x) { status = "NEW"; PID = x; next = NULL;};
};

#endif // PCB
