//****************************************************************************
//  CS311 Linked //  Header File  slist.h
// ** HW:HW3P2
// ** Your name:Thomas Griffin
//****************************************************************************

#include "llist.h"
class slist : public llist//inherits from the llist class publicly
{
public: 
	//consturctor
	slist();
	
	//copy constructor, allows pass by value to work properly
	slist(const slist&);	
	
	//searches the list to see if any of the values in the list are equal to 
	//the value passed to the function. Returns an int equal to the index where
	//the number was found. Zero will be returned if the value was not found in  
	//the list.
	int search(el_t);
	
	//replaces the value of the ith node with the value passed to the function.
	void replace(el_t,int);

	//Function for overloading the assignment operator, makes a deep copy so 
	//that issues aren't created when you try to assignment one objet to another
	slist& operator=(const slist&);
	
	//Function for overloading the comparison operator, manually checks each item
	//in each list being compared to see if the lists are equal. If one is empty and
	//the other is not it automatically fails.
	bool operator==(slist&);
};
