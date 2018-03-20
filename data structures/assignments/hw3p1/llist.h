
//****************************************************************************
//  CS311 Linked //  Header File  llist.h
// ** HW:HW3P1
// ** Your name:Thomas Griffin
//****************************************************************************

typedef int el_t ;

	   // list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node   *Next;  // next is the pointer to the next node
};

// I could have done class Node and add the data members under public
// but it will use too much space


class llist
{
  
 private:  // keep it private for now
  
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
 public: // ** MUST COMMENT EACH OF THE FOLLOWING
  
  class Underflow{};//exception to be thrown when list is empty and an item tries to be removed
  class OutOfRange {};
    
  llist ();                       // constructor  
  ~llist();                       // destructor
  
  //returns a boolean value, true if empty, false otherwise
  bool isEmpty();
  
  // displays all values in the nodes of the list
  void displayAll();
  
  //adds a node to the end of the list, takes an el_t which is then stored in the Elem part of the node being added
  void addRear(el_t NewNum);
 
  // deletes the front node of the list and get that element back through reference, takes an el_t by reference,
  // which holds the value from the node which was just deleted
  void deleteFront(el_t& OldNum);
  
  //adds node to the front of the list containing the value passed to it
  void addFront(el_t NewNum);
  
  //removes node at the end of the list and gives the value back through reference
  void deleteRear(el_t& OldNum);
 
 // delets the ith node in the list  
  void deleteIth(int I, el_t& OldNum);
  
  // adds a node to the list right before the ith node.  
  void addbeforeIth(int I, el_t newNum);
    
};
