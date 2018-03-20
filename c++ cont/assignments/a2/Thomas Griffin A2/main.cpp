/*
Thomas Griffin
Assignment 2
SEC10-20315
main.cpp
3/14/15
Description:
Program Creates an object of type Dictionary and calls  
the processTransactionFile function. From there it will
call different functions based on commands in transaction file.
It can add words to the dictionary, delete words, print a file
from the dictionary, and check to see if words from a file match
words in the dictionary. All words will be outputted to their 
respective file. The errors will be displayed on-screen.
*/
#ifndef Main_C
#define Main_C
#include "Dictionary.h"
using namespace std;

int main() 
{
	Dictionary  DictForCS211;
	DictForCS211.ProcessTransactionFile();
	return 0;
}
#endif
