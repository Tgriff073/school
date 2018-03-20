/*
a.This program will go through a file called zip.dat and count how many zip codes are listed, It will then count how many of those are po box zip codes and display those po box zip codes in city state zip code format. 
b. Thomas Griffin
c. CS 111 Programming Assignment
d. SEC30-50041 
e. 11/9/14 
f. 11/11/14
g. n/a
h.yes
*/
#include <iostream>
#include <fstream>
using namespace std;
enum PoBox{Pobox,Unique,APO,Blank};
#include "ZipInfo.h"
#include "functions.h"

int main()
{
  driver();

return 0;
}//end main

