
//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A
//Make sure all if-then-else are commented describing which case it is
//Make sure all local variables are described fully

// ====================================================

//HW3P1 llist
//Your name: Thomas Griffin
//Complier:  g++
//File type: class implementation for list class

//=====================================================

#include"llist.h" 
#include	<iostream>
using namespace std;

//purpose: function creates a new llist object and sets the Front and Rear pointers to NULL and sets the count to 0
llist::llist()
{
	Front=NULL;
	Rear=NULL;
	Count=0;	
}

//purpose: function destroys a llist object. 
//algorithm: loops while the list isn't empty and deletes each node from the front.
llist::~llist()
{	
	cout<<"Calling llist destructor."<<endl;
	int dummy;//local variable, only here so that theres something to pass to deleteFront
	while(!isEmpty())
		deleteFront(dummy);
}

//purpose: checks to see if the list is empty by seeing if Front and Rear both point to NULL
bool llist::isEmpty()
{
	return (Front==NULL&&Rear==NULL);
}

//purpose: Display all nodes in a llist object. If the object is empty it will display [Empty].
//algorithm: this function works by looping while the local variable curr doesn't equal NULL
//
void llist::displayAll()
{
	Node* curr= Front;//local node object which points to the front of the llist, 
	cout<<"Current list: ";
	if(isEmpty())//check if llist is empty
		cout<<" [Empty] ";
	while(curr!=NULL)
	{
		cout<<curr->Elem<<" ";//display the current value in the llist
		curr=curr->Next; //then move the pointer to the next node in the llist
	}
	cout<<endl;
}
//purpose: adds a new Node to the back of llist that holds the value that was passed to the function

void llist::addRear(el_t NewNum) 
{
	if(isEmpty())//llist is empty case
	{
		addFront(NewNum);
	}
	else //regular case
	{
	
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = NewNum;
		Rear->Next = NULL;
		Count++;
	}
}

//purpose: delete the front Node and store the value it was holding into OldNum.
void llist::deleteFront(el_t& OldNum)
{
	if(isEmpty())//empty case, throw UnderFlow error
	{
	
		throw Underflow();
		return;
	}
	else if(Front->Next==NULL)//Case if there is only one Node in the llist
	{
		OldNum=Front->Elem;
		delete Front;
		Front=NULL;
		Rear=NULL;
		Count=0;
	}
	else //regular case
		{
						
			OldNum = Front->Elem;
			Node *Second;
			Second = Front->Next;
			delete Front;
			Front = Second;
			Count--;
		}
			
}

//pupose: adds a new node to the front of a llist. The node will hold the value that was passed to the function 
void llist::addFront(el_t NewNum)
{
	if(isEmpty())//empty case
	{
		Node* temp= new Node;
		temp->Elem=NewNum;
		Front=temp;
		Rear=temp;
		Rear->Next=NULL;
		Count++;
	}
	else //regular case
	{
		Node *x;
		x = new Node;
		x->Next = Front;
		Front = x;
		Front->Elem = NewNum;
		Count++;
	}
}

//purpose: Deletes the the last node in the llist, the number stored in that node is moved to OldNum
void llist::deleteRear(el_t& OldNum)
{
	if(isEmpty())//empty case, throw UnderFlow error
		throw Underflow();
	if(Front->Next==NULL)//case if there is only one node, just call deleteFront
		deleteFront(OldNum);
	else//regular case
	{
		OldNum = Rear->Elem;
		Node *p;
		p= Front;
		
		while(p->Next!=Rear)//loop to the node before the rear node
			p=p->Next;//move pointer to the next Node
		
		delete Rear;
		Rear = p;
		Rear->Next=NULL;
		Count--;
	}
}

//purpose: delete the node that is currently at the Ith node, I is determined in the client file.
void llist::deleteIth(int I, el_t& OldNum)
{
	Node* p= Front;//local node pointer that points to the front of the llist
	
	if(I>Count||I<1)//case if I is out of range, so if i is larger than the current llist count or if it is less than 1
	{	
		throw OutOfRange();//Throw an out of range error
		return;
	}
	if(Front->Next==NULL||I==1)//Case if there is only one item in the llist, call deleteFront
	{
		deleteFront(OldNum);
		return;
	}
	
	if(isEmpty())// if the llist is empty throw an UnderFlow error
	{
		throw Underflow();
		return;
	}
	Node* temp= Front;//local node pointer which will be used to temporarily hold a node
	if(I==Count)
	{
		deleteRear(OldNum);
		return;		
	}
	
	for(int j=1;j<I-1; j++)//start count at 1 so that it starts at the first node, then go until the node before the ith node
		p=p->Next;
	

	temp=p->Next;//make temp point to the ith node
	OldNum=temp->Elem;//make OldNum equal to the value stored in the ith node
	p->Next=temp->Next;// make the ->next pointer of the node before the ith node point to the node after the ith node
	Rear->Next=NULL;	//make sure that the ->nex pointer of rear is still pointing to NULL
	delete temp;//delete the ith node
	Count--;//and decrement the count
	
	
}

//purpose: add a node to the llist before the ith node, I is determined in the client file. 
//algorithm: if the llist is empty or if the llist only has one item call addFront, if I is 1 greater than 
// the count call addRear, otherwise loop the llist until the pointer is pointing to the node before the ith node
//make a new node that holds the value passed to the function through newNum. Have the next pointer of the node before
//ith point to the new node and then have the next pointer of the new node point to the ith node.
void llist::addbeforeIth(int I, el_t newNum)
{
	Node* p;
	
	if(I>Count+1||I<1)//error case, throw outofrange error if i is larger than count+1 or less than 1
	{
		
		throw OutOfRange();
		return;
	}
	if(isEmpty())//empty case, call addfront
	{
		addFront(newNum);
		return;
	}
	
	if(I==1)//only one node, call addfront
	{
		addFront(newNum);
		return;
	}
	
	
	if(Count+1==I)//ith node is 1 behind rear, call addRear
	{
		addRear(newNum);
		return;
	}
	
	p=Front;
	int j=1;
	while((j<I-1)&&(p->Next!=Rear))//loop to node before ith node or until the next node is the rear node
	{
		p=p->Next;
		j++;
	}
		Node *x;
		x = new Node;//make a new node
		x->Elem=newNum;//give it the value that was passed to this function through newNum
		x->Next=p->Next;//have it's next pointer point to the ith node
		p->Next=x;// make the next pointer of the node that was before the ith node now point to the new node 
		Count++;//increment the count
}

