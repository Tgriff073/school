// ====================================================

//HW3P1 llist
//Your name: Thomas Griffin
//Complier:  g++
//File type: client file for a llist class

//=====================================================
#include <iostream>
#include "llist.h"
using namespace std;

//=======================================================================================
//purpose: The program will manipulate a llist object depending on which case the user 
//chooses. Each case tests different parts of the llist class to make sure it functions
//properly.
//Compile: This client file needs to be compiled with llist.cpp and make sure llist.h is in the
//same directory
//algorithm: Runs a loop while the user choice is less than 5, the choice is then checked
//and a test case is run based on the number they enter. For example if the user enters a
//one it will run test case 1. When the user enters a number that is greater than or equal 
//to 5 it will end the program 
//=======================================================================================
int main()
{
	llist L;
	int choice=0;
	int old;
	while(choice<5)
	{
		cout<<"Enter the corresponding number to your choice, enter 5 or higher to quit:\n\n1)Case 1\n2)Case 2\n3)Case 3\n4)Case 4\n";
		cin>>choice;
		switch(choice)
		{
			case 1:	
				cout<<"\n";
				if(L.isEmpty()==1)//if llist is empty display that it is empty otherwise display that it isn't empty
					cout<<"List is empty."<<endl;
				else
					cout<<"List isn't empty."<<endl;
				
				L.displayAll();
				
				
					
				for(int i=1;i<4;i++)//add the numbers 1 through 3 to the llist from the back
					L.addRear(i);
				
				L.displayAll();
				
				for(int i=0;i<2;i++)//delete the first two numbers from the list and display which numbers were deleted
				{
					L.deleteFront(old);
					cout<<old<<" has been deleted"<<endl;
				}
				
				if(L.isEmpty()==1)//if llist is empty display that it is empty otherwise display that it isn't empty
					cout<<"List is empty."<<endl;
				else
					cout<<"List isn't empty."<<endl;
				
				L.deleteRear(old);//delete the rear node and display what number was deleted
				cout<<old<<" has been deleted"<<endl;
				
				if(L.isEmpty()==1)//if llist is empty display that it is empty otherwise display that it isn't empty
					cout<<"List is empty."<<endl;
				else
					cout<<"List isn't empty."<<endl;
				
				L.displayAll();
				cout<<"\n\n";
				break;
				
				case 2:
					L.addFront(5);
					L.addFront(4);
					L.deleteFront(old);
					L.addRear(6);
					L.addRear(8);
					L.addRear(9);
					L.displayAll();
					L.addbeforeIth(1, 4);
					L.addbeforeIth(4, 7);
					L.addbeforeIth(7, 10);
				try//error producing results
					{
						L.addbeforeIth(9, 12);
						
					}
					catch(llist::OutOfRange)
					{
						cout<<"Requested element is out of range"<<endl;
					}
					try
					{
						
						L.addbeforeIth(0, 0);
					}
					catch(llist::OutOfRange)
					{
						cout<<"Requested element is out of range"<<endl;
					}
					L.displayAll();
					L.deleteIth(1,old);
					cout<<old<<" has been removed from the list."<<endl;
					L.deleteIth(6,old
					);
					cout<<old<<" has been removed from the list."<<endl;
					L.deleteIth(3,old);
					cout<<old<<" has been removed from the list."<<endl;
					
					try
					{
						L.deleteIth(5, old);
					}
					
					catch(llist::OutOfRange)
					{
						cout<<"Error: Requested element is out of range"<<endl;
					}
					
					try
					{
						L.deleteIth(0, old);
					}
					
					catch(llist::OutOfRange)
					{
						cout<<"Error: Requested element is out of range"<<endl;
					}
					
					L.displayAll();
					
					while(L.isEmpty()!=true)
					{
						L.deleteRear(old);
						cout<<old<<" has been removed from the list."<<endl;
					}
					L.displayAll();
					break;
					
				case 3:
					try
					{
						L.addbeforeIth(0, old);
					}
					
					catch(llist::OutOfRange)
					{
						cout<<"Error: Requested element is out of range"<<endl;
						
					}
					try
					{
						L.deleteFront(old);
					}
						catch(llist::Underflow)
					{
						cout<<"Error: List is empty, cannot delete from list while it is empty. "<<endl;
					}
				case 4:
					try
					{
						L.deleteIth(0,old);
					}
					catch(llist::OutOfRange)
					{
						cout<<"Error: Requested element is out of range"<<endl;
					}
					
					try
					{
						L.deleteRear(old);
					}
					catch(llist::Underflow)
					{
						cout<<"Error: List is empty, cannot delete from list while it is empty. "<<endl;
					}
				
					break;
			
				
				
		}	
	} 
	return 0;
}
