
//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp

// =======================================================

// HW1P1
// Your name: Thomas Griffin
// Compiler:  g++ 
// File type: header file vstack.h

//=======================================================
#include <vector>
using namespace std; 
                      

typedef int  el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        vector <el_t> el;       // el is  vector of el_t's
        

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};//exception for when stack is empty
        class Underflow{};//exception for when stack is full, useless in vector implementation

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
        //this function returns a boolean value
        
		//if the vector size is currently at 0 then it is considered empty and returns true
        //otherwise it returns false
      	bool isEmpty();
      	
		//always returns false since a vector stack can't be filled
      	bool isFull();
        
		//displays all the values currently in the stack in a vertical fashion
		//displays [EMPTY] if it is empty
		void displayAll();
		
		//clears stack by using built in vector function clear, which deletes all current entries
		//and sets size back to 0
        void clearIt();
        
  };  

// Note: semicolon is needed at the end of the header file

