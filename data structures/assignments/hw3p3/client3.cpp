// ====================================================

//HW3P3 slist with overloading
//Your name: Thomas Griffin
//Compiler:  g++
//File type: client file for slist with overloading

//=====================================================
#include <iostream>
#include "slist.h"
using namespace std;
//function checks to make sure that pass by value is working and that
//changing the object in this function doesn't affect the original object
void copyTest(slist);
//=======================================================================================
//purpose:The purpose of the program is to check and make sure that the overloading of the
//assignment operator is working properly and that pass by value for slist objects is also 
//functioning properly.
//How to compile: File needs to be compiled with slist.cpp and llist.cpp, slist.h and llist.h
//must also be in the same directory when compiling.
//Design: The overall design of the program is to test different cases to see that both the 
//copy constructor and the assignment overload are working properly. The program adds numbers
// to the list and then does a copy test to see if a number that was added to copy of an object
//isn't added to the original object. Then the slist object is assigned to itself to make sure
//the assignment operator is functioning. Another slist object is created with different numbers
//and the it gets assigned the values from the first slist object. The contents of the new object 
//are then displayed to see if it's the same.
//=======================================================================================
int main()
{
	slist L1,L2;
	int temp;
	for(int i=1; i<6;i++)
		L1.addRear(i);
	copyTest(L1);
 	L1.displayAll();
	L1=L1;
	L1.displayAll();
	for(int i=7;i<11;i++)
		L2.addRear(i);
	L2.displayAll();
	L2=L1;
	L2.displayAll();
	L1.deleteRear(temp);
	L1.displayAll();
	L2.displayAll();
	return 0;
}

void copyTest(slist test)
{
	test.addRear(6);
	test.displayAll();
}
