#ifndef LIST_H
#define LIST_H

#include "itemtype.h"

class List
{
public:
    bool IsEmpty() const;

        // Postcondition:
        // Return value == true, if list is empty
        //                  == false, otherwise

    bool IsFull() const;

        // Postcondition:
        //     Return value == true, if list is full
        //                  == false, otherwise

    int Length() const;

         // Postcondition:
         //     Return value == length of list
  
    void Insert( /* in */ ItemType item );

        // Precondition:
        //     NOT IsFull()
        // Postcondition:
        //     item is in list
        //  && Length() == Length()@entry + 1

    void Delete( /* in */ ItemType item );

        // Precondition:
        //     NOT IsEmpty()
        // Postcondition:
        //     IF item is in list at entry
        //         First occurrence of item is no longer in list
        //       && Length() == Length()@entry - 1
        //     ELSE
        //         List is unchanged

    bool IsPresent( /* in */ ItemType item ) const;

        // Postcondition:
        //     Return value == true, if item is in list
        //                  == false, otherwise

    void Reset();

        // Postcondition:
        //     Iteration is initialized
        
    ItemType GetNextItem();
    
        // Precondition:
        //     Iteration has been initialized by call to Reset;
        //     No transformers have been invoked since last call
        // Postcondition:
        //     Return value is the item at the current position 
        //     in the list on entry;
        //     If last item has been returned, the next call will
        //     return the first item.
            	
    void SelSort();

        // Postcondition:
        //     List components are in ascending order of value

    List();
 
        // Constructor
        // Postcondition:
        //     Empty list is created

private:
    int      length;
    int      currentPos;
    ItemType data[MAX_LENGTH];
};

#endif /*LIST_H_*/

