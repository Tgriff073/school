#ifndef MAIN_C
#define MAIN_C
#include <iostream>
#include "university.h"
using namespace std;
//----------------------------------------------------------------------------

int main() 
{
	University csusm;
	csusm.ProcessTransactionFile("TransactionFile.txt");
}
//----------------------------------------------------------------------------
#endif
