// ====================================================

//HW3P2 slist
//Your name: Thomas Griffin
//Complier:  g++
//File type: client file for a slist class

//=====================================================
#include "slist.h"
#include <iostream>
using namespace std;
//=======================================================================================
//purpose: This client file is meant to test out the new functions of the slist class and
//to make sure the slist class inherited from the llist class correctly. 
//Compile: This client file need to be compiled with llist.cpp and and slist.cpp, also make
//sure llist.h and slist.h are in the same directory.
//algorithm: Program populates and slist object with values. It then performs different test
// with the new functions in slist. It looks for certain values in the list and reports whether
//or not they were found. It also replaces 2 of the numbers that were found with other numbers.
//=======================================================================================
int main()
{
	slist L;
	int search=0;
	L.addFront(4);
	try
	{
	
	for(int i=6;i<9;i++)//add the values 6,7,8 to the list through the back of the list
		L.addRear(i);
	
	L.displayAll();
	search=L.search(6);

	if(search)//if the value returned from search is greater than 0
		cout<<"Found in position "<<search<<endl;//display the index where the value was found
	else//otherwise display that it wasn't found in the list
		cout<<"Number was not found in the list"<<endl;
	
	L.replace(0,search);	
	search=L.search(8);
	if(search)//if the value returned from search is greater than 0
		cout<<"Found in position "<<search<<endl;//display the index where the value was found
	else//otherwise display that it wasn't found in the list
		cout<<"Number was not found in the list"<<endl;
	L.replace(2,search);
	L.displayAll();
	search=L.search(5);
	if(search)//if the value returned from search is greater than 0
		cout<<"Found in position "<<search<<endl;//display the index where the value was found
	else//otherwise display that it wasn't found in the list
		cout<<"Number not found in list"<<endl;
	}
	catch(llist::OutOfRange)
	{
		cout<<"Error: List is empty, cannot delete from list while it is empty. "<<endl;
	}
	return 0;
}
