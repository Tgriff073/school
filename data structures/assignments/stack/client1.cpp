//INSTRUCTION:
//Look for **.

// =========================================================

//HW1P1 stack client
//Your name: Thomas Griffin
//Complier:  g++
//File type: **

//================================================================

#include <iostream>
#include <string>
#include "vstack.h"
using namespace std;

int main()
{
	stack postfixstack;  // integer stack
	string expression;
  
	cout << "type a postfix expression: " ;
	cin >> expression;
  
	int i = 0;  // character position within expression
	char item;
	int result;  
	int box1;  // receive things from pop
	int box2;  // receive things from pop
  
	while (expression[i] != '\0')
	{
      try
	  {
	    //1.  read an item.
	    //2.  if it is an operand (number), 
	    //push it (you might get Overflow exception)
	    //3.  else if it is an operator,
	    //    pop the two operands (you might get Underflow exception), and
	    //	 apply the operator to the two operands, and
	    //    push the result.
	    item = expression[i];
        if(expression.length()==1)
	      throw stack::Underflow();
 	  	i++;
	 	if(item >= '0' && item <= '9') 
		  postfixstack.push(item-48);
        else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
          if(!postfixstack.isEmpty())		
	        postfixstack.pop(box1);
	        
	      else
		    throw stack::Underflow();
		    
	      if(!postfixstack.isEmpty())
            postfixstack.pop(box2);
            
          else
		    throw stack::Underflow();
          // a whole bunch of cases
          if (item == '-') 
		    result = box2-box1;
		    
          else if (item == '+') 
		    result = box2+box1;
		    
	      else if (item == '*') 
		    result = box2*box1;
		    
	      postfixstack.push(result);
	     // also do the + and * cases 
	     // push the result
	    }
	 	else 
		{
          throw "invalid item";
        }
        

	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
	catch (stack::Overflow)
	{
	  cout << "Error: Stack is Full!" << endl;
	  exit(1); 
	}
    
	catch (stack::Underflow)
	{
	  cout << "Error: Too few Operands!" << endl;
	  exit(1); 
	}
    
	catch (char const* errorcode) // for invalid item
	{
	  cout << errorcode<<endl;
	  exit(1);
	}
      // go back to the loop
      
   }// end of while
   
   postfixstack.pop(result);
   
   if(postfixstack.isEmpty())
     cout<<"The result is : " << result << endl;
   
   else
     cout<<"Error: Incomplete Expression"<<endl;
   
   return 0;
  //  After the loop successfully completes: 
  //  The result will be at the top of the stack. Pop it and show it.
  //  If anything is left on the stack, an incomplete expression was found
  // inform the user.
//  **
    
    
}
