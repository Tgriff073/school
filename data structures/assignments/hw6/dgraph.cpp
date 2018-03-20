#include "dgraph.h"
#include <fstream>
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
	Gvertex *P=Gtable;
	delete[] P;
	
}

void dgraph::fillTable()
{
	el_t temp;
	int slot=0;
	ifstream fin("table.txt");
	while (fin>>Gtable[slot].vertexName)
	{
		countUsed++;
		fin >> Gtable[slot].outDegree;
		
		for(int i=0;i<Gtable[slot].outDegree;i++)
		{
			fin>>temp;
			Gtable[slot].adjacentOnes.addRear(temp);
		}
		
		
	}
	
}
