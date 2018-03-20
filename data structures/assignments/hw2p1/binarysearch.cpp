/*
HW#: HW2 Analysis
Author: Thomas Griffin
Date: 9/29/2015
Compiler:g++
*/

#include <iostream>
using namespace std;
int binarySearch(int[],int, int, int);


/*Program Description: The program wiil ask the user to enter a number they would like to search for,
then the binary search function is called to look for that value in the array of hard coded values.
If it is found in the array the index where it was found will be returned to main and displayed for the 
user to see. If the value returned is less than or equal to 0 it will display an error that the integer was
not found in an array. After the index or error has been displayed the user will be asked if they would like to 
search for another value, if the enter either 'y' or 'Y' it will loop through again, any other value entered will 
end the program.*/
// Program can be compiled by itself simply with g++ binarysearch, there are no class files needed to compile
//The alogorithm of the search basically functions by cutting the list in half each time, which works since the list is ordered.
//the middle of the list is always determined by the index of the first element + the index of the last element divided by 2
//then the list is cut in half, unless the middle number is equal to the number being looked for then the function just returns the middle index.
// If the middle isn't the value being looked for then the new array is determined by whether the value being searched for is greater than or less than the middle.
//If it is greater than the middle then the first index is shifted 1 to the righ of the middle index. If the value being searched for is less than the middle the last index is
//shifted 1 to the left of the middle, thus cutting the array in half. This process continues until the value being searched for is found or when first=last. If it is found then that
//value is returned, otherwise it says the value was not found.
int main()
{
	char choice='Y';// initial choice is 'Y' so the loop will go through atleast once
	int myList[10]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int myfirst = 0; //first index of array
	int mylast = 9; //  set up initial indices 
	int resultloc =0;
	int findthis=0;
	while(choice=='Y')// while loop runs as long as the user enters 'y' or 'Y' at the end of each search, this will run atleast once since choice was initialized to 'Y'
	{
		cout<<"What number would you like to look for?"<<endl;
		cin>>findthis;
		resultloc = binarySearch(myList, findthis, myfirst, mylast)+1;//the value of the location is equal to one plus the index of the array where the number was found
		if(resultloc>0)//make sure the location is greater than 0, if it is less than or equal to 0 than we know it wasn't found
			cout<<"Found in slot: "<<resultloc<<"."<<endl;
		else //value wasn't found
			cout<<"Result not found in array." <<endl;
		cout<<"Would you like to look for another item? (Y/N)"<<endl;
		cin>>choice;
		choice=toupper(choice);// change the user value to uppercase so that it works if they enter 'y' or 'Y'
	}
	
    
	
	return 0;
}

int binarySearch(int L[], int x, int first, int last) 
{
	if(first<=last)//make sure the last index is greater than the first other wise the value wasn't found
	{
		
	
	int middle=(first+last)/2 ;
	if (x == L[middle]) // if the value being looked for is the middle, return the middle value
		return middle;  
   else if (x < L[middle]) //els if the value being looked for is less than the middle switch to the first half of the array
   		last  = middle - 1; 
   else if (x > L[middle]) //else if the value being looked is greater than the middle switch to the second half of the array 
   		first = middle + 1; 
   return binarySearch(L, x, first, last); //recursively call this function with new values
	}
	else //if it turns out that first is greater than or equal to last then -1 is returned and it will be handled in main
		return -1;

}
