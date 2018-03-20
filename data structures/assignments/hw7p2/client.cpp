// =========================================================

//HW7p2 Graph
//Your name: Thomas Griffin
//Compiler:  g++
//File type: client file for graph class

//================================================================
#include <iostream>
#include <iomanip>
#include "dgraph.h"
#include "stack.h"
using namespace std;

//purpose: Program is meant to test all the methods inside of the
//graph class. A depth first search is performed on the graph to make sure
//that everything was properly stored.
//compile with g++ and with the required files. 
//like g++ llist.cpp slist.cpp stack.cpp dgraph.cpp client.cpp
//make sure the header for files the classes are also in the same directory
//algorithm: The main loop runs while the stack is not empty. This loop is performing
//the dfs. It pops a vertex off the stack then checks if it is marked. If it isn't marked
//it's adjacency list is pushed onto the stack. Stack contents is displayed at the end of each
//iteration. Loop iterates until all vertices are off the stack. The graph with the new visit numbers
//is displyed at the end.

int main()
{
	dgraph t1;
	t1.fillTable();
	t1.displayGraph();
	int visitNo=1;
	t1.visit(visitNo++, 'A');
	stack s1;
	slist l1=t1.findAdjacency('A');
	char temp=' ';
	cout<<"Pushing: ";
	l1.displayAll();
	while(!l1.isEmpty())// while the adjacency list of a isn't empty
	{
		l1.deleteRear(temp);
		s1.push(temp);
	}
	
	cout<<"Visited: A"<<endl;
	cout<<"\nCurrent Stack:\n_____________"<<endl;
	s1.displayAll();
	cout<<setfill('_')<<setw(15)<<" "<<endl;
	while(!s1.isEmpty())//while the stack isn't empty
	{
		s1.pop(temp); //pop the top of the stack 
		cout<<"Visited: "<< temp << endl;
		if(!t1.isMarked(temp))//check if the vertex that was just popped has been visited
		{
			t1.visit(visitNo++, temp);//if it hasn't been visited, then visit it
			l1=t1.findAdjacency(temp);//push it's adjacency list onto the stack
			cout<<"Pushing  ";
			l1.displayAll();//display it's adjacency list
			while(!l1.isEmpty())//while it's adjacency list is not empty
        		{
                		l1.deleteRear(temp);//delete a vertex from the list
                		s1.push(temp);//and add it to the top of the stack
        		}
			
			cout<<"\nCurrent Stack:\n_____________"<<endl;
	                s1.displayAll();//and finally display the new stack
			cout<<setfill('_')<<setw(15)<<" "<<endl;


		}
		else//otherwise
		{
			cout<<"\nCurrent Stack:\n_____________"<<endl;
                        s1.displayAll();//just display the new stack
			cout<<setfill('_')<<setw(15)<<" "<<endl;


		}
		
	}
	t1.displayGraph();//dispaly the final graph
	return 0;
}

