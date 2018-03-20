// ====================================================

//HW3P3ec slist with overloading
//Your name: Thomas Griffin
//Compiler:  g++
//File type: client file for slist with overloading of comparison operator

//=====================================================
#include <iostream>
#include "slist.h"
using namespace std;
//=======================================================================================
//purpose: This client file test to make sure the the overloading of the comparison operator
//is working for the slist class. 
//How to compile: Compile with llist.cpp and slist.cpp, make sure llist.h and slist.h are in 
//the same directory.
//design: Program test different cases to see if the comparison operator is working. It tests
//if both lists are empty, one list is empty while the other isn't, if they both have the same
//elements, if they have the same number of elements but the elements are different, and if one
//list has more elements than the other.
//=======================================================================================
int main()
{
	int temp;
	slist L1;
	slist L2;
	L1.displayAll();
	L2.displayAll();
	
	if(L1==L2)//display that the lists are equal if they are, otherwise display they arent equal
        cout<<"Lists are equal"<<endl;
	else
        cout<<"Lists aren't equal"<<endl;

	L2.addRear(1);
	L2.addRear(2);
	L1.displayAll();
	L2.displayAll();
	
	if(L1==L2)//display that the lists are equal if they are, otherwise display they arent equal
   		cout<<"Lists are equal"<<endl;
	else
        cout<<"Lists aren't equal"<<endl;

	L2.addRear(3);

	for(int i=1; i<4;i++)//populate L1 with the numbers 1,2,3
		L1.addRear(i);
	
	L1.displayAll();
	L2.displayAll();

	if(L1==L2)//display that the lists are equal if they are, otherwise display they arent equal
	    cout<<"Lists are equal"<<endl;
	else
        cout<<"Lists aren't equal"<<endl;

	L2.deleteRear(temp);	
	L1.displayAll();
	L2.displayAll();
	
	if(L1==L2)//display that the lists are equal if they are, otherwise display they arent equal
        cout<<"Lists are equal"<<endl;
	else
        cout<<"Lists aren't equal"<<endl;

	L2.addRear(3);
	L2.addRear(4);
	L1.displayAll();
    L2.displayAll();

	if(L1==L2)//display that the lists are equal if they are, otherwise display they arent equal
     	cout<<"Lists are equal"<<endl;
	else
        cout<<"Lists aren't equal"<<endl;

	L2.deleteIth(3, temp);
	L1.displayAll();
    L2.displayAll();
	
	if(L1==L2)//display that the lists are equal if they are, otherwise display they arent equal
        cout<<"Lists are equal"<<endl;
	else
        cout<<"Lists aren't equal"<<endl;

	return 0;
}	




