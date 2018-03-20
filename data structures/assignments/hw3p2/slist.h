//****************************************************************************
//  CS311 Linked //  Header File  slist.h
// ** HW:HW3P2
// ** Your name:Thomas Griffin
//****************************************************************************

#include "llist.h"
class slist : public llist//inherits from the llist class publicly
{
public: 
	slist();
	slist(slist&)	
	dsfadsfadfsgsdfgsdfg
	//searches the list to see if any of the values in the list are equal to 
	//the value passed to the function. Returns an int equal to the index where
	//the number was found. Zero will be returned if the value was not found in  
	//the list.
	int search(el_t);
	
	//replaces the value of the ith node with the value passed to the function.
	void replace(el_t,int);

	slist& operator=(const slist&);
};
