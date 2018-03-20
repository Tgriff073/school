// =========================================================

//HW7p2 Graph
//Your name: Thomas Griffin
//Compiler:  g++
//File type: implementation file graph class

//================================================================
#include "dgraph.h"
#include <fstream>
#include <iomanip>
using namespace std;


//constructor
//method will initialize the names of every vertex to ' ' and the vist# of every vertex to 0
//also initializes countused to 0.
dgraph::dgraph()
{
	for(int i=0; i<SIZE;i++)
	{
	
		Gtable[i].vertexName = ' ';
		Gtable[i].visit=0;
	}
	countUsed=0;
}

//destructor
//does nothing since linked list destructor will clean stuff up
dgraph::~dgraph()
{
	
}

//fillTable
//method creates a filestream object and opens the file table.txt in the stream. 
//it reads in the content of the table and fills in Gtable array.
void dgraph::fillTable()
{
	el_t temp;
	int slot=0;
	ifstream fin("table.txt");
	if(!fin)//if the file fails to open
		cout<<"*****ERROR COULDNT READ FILE***"<<endl;
	while (fin>>temp)//while there are still things being read in
	{
		countUsed++;
		
		slot=h(temp);
		Gtable[slot].vertexName = temp;
		fin >> Gtable[slot].outDegree;
		
		for(int i=0;i<Gtable[slot].outDegree;i++)//loop for how ever many outdegrees the current node has
		{
			fin>>temp;
			Gtable[slot].adjacentOnes.addRear(temp);//add name of adjacent lists onto the adjacent linked list of current node
		}
		
		
	}
	
}

//visit
//gives the vertex that is passed to the method the visit number that is also passed 
//to the method. For example if 1 and 'A' where passed it would go to vertex 'A' and 
//set it's visit number to 1.
void dgraph::visit(int v, char n)
{
	Gtable[h(n)].visit=v;
}
//isMarked
//checks if the vertex ,that is represented by the character passed to this
//method, has been visited yet. Returns a 1 if the visit number is greater than 0,
//meaning it has been visited, or returns 0 otherwise.
bool dgraph::isMarked(char x)
{
	return (Gtable[h(x)].visit>0);
} 

//h
//method hashes the character passed to it
//A goes to 0, B goes to 1,C goes to 2 etc..
//converts the character passed to it to uppercase
//so method works if you pass either a lower case
//or upper case letter.
int dgraph::h(char h)
{
	int ascii =toupper(h);
	return ascii-'A';
}

//displayGraph
//method displays the current layout of the table. 
//calls the display all function of a linked list to display the adjacency lists.
void dgraph::displayGraph()
{

	cout<<setfill(' ')<<setw(6)<<left<<"Name"<<setw(11)<<"OutDegree"<<setw(8)<<"vistNo"<<setw(10)<<"Adjacent"<<endl;//heading for table, left sets left justification of text for the header
	cout<<setfill('-')<<setw(34)<<" "<<endl;//creates a line underneath the table heading
	int count=0,i=0;
	while(count<countUsed)//loop for however many vertices are currently in the table
	{
	if(Gtable[i].vertexName!=' ')
	 {
   	 cout <<setfill(' ')<< setw(6) << Gtable[i].vertexName << setw(12) << Gtable[i].outDegree<<setw(8)<<Gtable[i].visit;
         Gtable[i].adjacentOnes.displayAll();
	 i++;//two seperate counters were needed in case a slot was skipped in the table. We don't want to display an empty slot.
	 count++;//count only gets incremented if there was something found in the current slot.
	 }
	else
	i++;
	
	}  
}

//returns the outDegree of the vertex requested through the argument
int dgraph::findOutDegree(el_t key)
{
	
	if(Gtable[h(key)].vertexName == key)
		return (Gtable[h(key)].outDegree);
	
	return -1;//returns -1 if character is not found
}

//findAdjacency
//returns an slist object. The slist is a linked list of all the vertices that are adjacent
//to the requested vertex. Will return an empty list if there are no vertices adjacent to the 
//requested vertex.
slist dgraph::findAdjacency(el_t key)
{
	return Gtable[h(key)].adjacentOnes;
}

 

