#include <iostream>
#include "slist.h"
using namespace std;

void copyTest(slist);

int main()
{
	slist L1,L2;
	for(int i=1; i<6;i++)
		L1.addRear(i);
	copyTest(L1);
 	L1.displayAll();
	return 0;
}

void copyTest(slist test)
{
	test.addRear(6);
	test.displayAll();
}
