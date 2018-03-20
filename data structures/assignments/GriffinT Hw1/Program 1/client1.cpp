//INSTRUCTION:
//Look for **.

// =========================================================

//HW1P1 stack client
//Your name: Thomas Griffin
//Complier:  g++
//File type: **
//Purpose:This program will evaluate postfix expressions using a stack.
//It will only work with the mathematical operators + - and *.
//It also only works if the input is single digit numbers and no blank spaces.
//The program runs through the expression entered by the user and if it is an integer it gets
//aded to the stack and if it is an operator it pops the top two elements of the stack and 
//performs the corresponding operation on them and then pushes the result onto the stack.
//This occurs until the entire expression has been evaluated or an error occurs like an invalid
//item or a stack overflow or underflow occurs.
//================================================================

#include <iostream>
#include <string>
#include "stack.h"
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
  
  while (expression[i] != '\0')//run the loop as long as the current item is not a null character
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
	 if(item >= '0' && item <= '9') //checks if the current item from user input is an integer between 0 an 9 if it is it get pushed onto the stack
	 	postfixstack.push(item-48);// item -48 converts the character from it ascii value to it's actual integer value
           
         else if ( (item == '+') || (item == '-') || (item == '*'))//checks if current item from user input is an operator
	   {
             if(!postfixstack.isEmpty())//as long as the stack isn't empty take the top off the stack and store it in box1		
	     	   postfixstack.pop(box1);
	     	 else//throw underflow if stack is empty
		 	   throw stack::Underflow();
	     	 if(!postfixstack.isEmpty())//as long as the stack isn't empty take the new top off the stack and store it in box2
               postfixstack.pop(box2);
             else//throw underflow if stack is empty
			   throw stack::Underflow();
             if (item == '-') //if current item is a - sign then subtract what's in box1 from box2 and store the value in result
			   result = box2-box1;
             else if (item == '+') //if current item is a + sign add the items in box1 and box2 and store the value in result
			   result = box2+box1;
	    	 else if (item == '*') //if current item is a * sign the multiply the two items in box1 and box2 and then store the value in result
			   result = box2*box1;
	         postfixstack.push(result);//push the result onto the stack
	     
	   }
	 else {
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
