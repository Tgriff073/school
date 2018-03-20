#include "dgraph.h"
#include <fstream>
#include <iomanip>
using namespace std;

dgraph::dgraph()
{
	for(int i=0; i<SIZE;i++)
	{
	
		Gtable[i].vertexName = ' ';
		Gtable[i].visit=0;
	}
	countUsed=0;
}

dgraph::~dgraph()
{
	
}

void dgraph::fillTable()
{
	el_t temp;
	int slot=0;
	ifstream fin("table.txt");
	if(!fin)
		cout<<"*****ERROR COULDNT READ FILE***"<<endl;
	while (fin>>Gtable[slot].vertexName)
	{
		countUsed++;
		fin >> Gtable[slot].outDegree;
		
		for(int i=0;i<Gtable[slot].outDegree;i++)
		{
			fin>>temp;
			Gtable[slot].adjacentOnes.addRear(temp);
		}
		
		slot++;
	}
	
}

void dgraph::displayGraph()
{

	cout<<setfill(' ')<<setw(6)<<left<<"Name"<<setw(11)<<"OutDegree"<<setw(10)<<"Adjacent"<<endl;
	cout<<setfill('-')<<setw(20)<<" "<<endl;

	for (int i = 0; i < countUsed; i++)
	{  
   	 cout <<setfill(' ')<< setw(6) << Gtable[i].vertexName << setw(12) << Gtable[i].outDegree;
         Gtable[i].adjacentOnes.displayAll();
	 
	}  
}

int dgraph::findOutDegree(el_t key)
{
	for(int i=0; i<SIZE;i++)
	{
		if(Gtable[i].vertexName == key)
		  return (Gtable[i].outDegree);
	}
	return -1;//returns -1 if character is not fouind
}

slist dgraph::findAdjacency(el_t key)
{
	
	for(int i =0;i<SIZE;i++)
	{
		if(Gtable[i].vertexName == key)
		{
			return Gtable[i].adjacentOnes;
		}
	}
	slist temp;
	return temp;
}

 

