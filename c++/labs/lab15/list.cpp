//******************************************************************
// IMPLEMENTATION FILE (list.cpp)
// This file implements the List class member functions
// List representation: a one-dimensional array and a length
//                      variable
//******************************************************************
#include "list.h"
#include <iostream>

using namespace std;

// Private members of class:
//    int      length;               Length of the list
//    ItemType data[MAX_LENGTH];     Array holding the list items

//******************************************************************

List::List()

// Constructor

// Postcondition:
//     length == 0

{
    length = 0;
}

//******************************************************************

bool List::IsEmpty() const

// Reports whether list is empty

// Postcondition:
//     Function value == true, if length == 0
//                    == false, otherwise

{
    return (length == 0);
}

//******************************************************************

bool List::IsFull() const

// Reports whether list is full

// Postcondition:
//     Function value == true, if length == MAX_LENGTH
//                    == false, otherwise

{
    return (length == MAX_LENGTH);
}

//******************************************************************

int List::Length() const

// Returns current length of list

// Postcondition:
//     Function value == length

{
    return length;
}

//******************************************************************

void List::Insert( /* in */ ItemType item )

// Inserts item into the list

// Precondition:
//     length < MAX_LENGTH
//  && item is assigned
// Postcondition:
//     data[length@entry] == item
//  && length == length@entry + 1

{
    data[length] = item;
    length++;
}

//******************************************************************

void List::Delete( /* in */ ItemType item )

// Deletes item from the list, if it is there

// Precondition:
//     length > 0
//  && item is assigned
// Postcondition:
//     IF item is in data array at entry
//           First occurrence of item is no longer in array
//        && length == length@entry - 1
//     ELSE
//           length and data array are unchanged

{
    int index = 0;    // Index variable

    while (index < length && item != data[index])
        index++;

    if (index < length)
    {                                 // Remove item
        data[index] = data[length-1];
        length--;
    }
}

//******************************************************************

bool List::IsPresent( /* in */ ItemType item ) const

// Searches the list for item, reporting whether it was found

// Precondition:
//     item is assigned
// Postcondition:
//     Function value == true, if item is in data[0..length-1]
//                    == false, otherwise

{
    int index = 0;    // Index variable

    while (index < length && item != data[index])
        index++;
    return (index < length);
}

//******************************************************************

  void List::Reset()
        // Postcondition:
        //     Iteration is initialized
  {
      currentPos = 0;
  }
            
//******************************************************************
         
 ItemType List::GetNextItem()
 // Precondition:
 //     Iteration has been initialized by call to Reset;
 //     No transformers have been invoked since last call
 // Postcondition:
 //     Returns item at the currentPos@entry in the list and
 //     resets current to next position or first position if
 //     last item is returned
  {
       ItemType item;
       item = data[currentPos];
       if (currentPos == length - 1)
           currentPos = 0;
       else
           currentPos++;
       return item;    
  }     
              
//******************************************************************

void List::SelSort()

// Sorts list into ascending order

// Postcondition:
//     data array contains the same values as data@entry, rearranged
//     into ascending order

{
    ItemType temp;               // Temporary variable
    int      passCount;          // Loop control variable
    int      searchIndx;         // Loop control variable
    int      minIndx;            // Index of minimum so far

    for (passCount = 0; passCount < length - 1; passCount++)
    {
         
        minIndx = passCount;

        // Find the index of the smallest component
        // in data[passCount..length-1]

        for (searchIndx = passCount + 1; searchIndx < length;
                                                       searchIndx++)
            if (data[searchIndx] < data[minIndx])
                minIndx = searchIndx;

            // Swap data[minIndx] and data[passCount]

         temp = data[minIndx];
         data[minIndx] = data[passCount];
         data[passCount] = temp;
   }
}

//******************************************************************


