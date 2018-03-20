#include <iostream>
using namespace std;

/*
Name:void designOne
Purpose:prints out design based of pattern a from lab paper
Parameters:none
Return:void
Pre-Condition:n/a
Post-Condition:n/a
Last Modification:10/15/14
*/

void designOne();
/*
Name:void designTwo
Purpose:prints out design based of pattern c from lab paper
Parameters:none
Return:void
Pre-Condition:n/a
Post-Condition:n/a
Last Modification:10/15/14
*/

void designTwo();
/*
Name:void designThree
Purpose:prints out design based of pattern b from lab paper
Parameters:none
Return:void
Pre-Condition:n/a
Post-Condition:n/a
Last Modification:10/15/14
*/

void designThree();
int main()
{
designOne();
//these cout statements are putting breaks betweem the designs
cout<<"\n";
designTwo();
cout<<"\n";
designThree();
}

void designOne()
{
for(int i=0; i<7; i++)
   {
     for (int j=0; j<i; j++)
       {
         cout<<"*";
            
       }
       cout<<endl;   
}
}//end of designOne

void designTwo()
{
for(int i =0; i<7;i++)//controls columns of design
   {
    for(int j=6; j>i; j--)//controls the rows of the design
     {cout<<"*";//prints out actual content of design
       }
        cout<<" "<<endl;
}
}//end of designTwo

void designThree()
{
for(int i=1; i<7; i++)
 {
   cout<<i<<" ";
        for(int j=0; j<1; j++)
          {
            cout<<j;
          }
 
      
cout<<endl;
}

       
}//end of designThree

