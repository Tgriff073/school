
//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp

// =======================================================

// HW1P1
// Your name: Thomas Griffin
// Compiler:  g++ 
// File type: headher file stack.h

//=======================================================

const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef int  el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        el_t     el[MAX];       // el is  an array of el_t's
        int      top;           // top is index to the top of stack

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};//exception for when the stack is overflowing(full)
        class Underflow{};//exception for when the stack is underflowing(empty)

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL: ***
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

        // ************ add good comments for each function *****
        
		//function returns a boolean value
        //Purpose:if the top currently equals negative one that means the stack is empty and true will be returned
        //otherwise false will be returned
      	bool isEmpty();
      	
      	//function returns a boolean value
        //Purpose: if the top currently equals max size that means the stack is full and true will be returned
        //otherwise false will be returned
      	bool isFull();
      
	  	//Purpose:function goes through the stack and displays all items that are currently in it
      	//will display [empty] if the stack is currently empty
        void displayAll();
      
	    //Purpose: Function clears the entire stack by setting the top back to -1
        void clearIt();
        
  };  

// Note: semicolon is needed at the end of the header file

