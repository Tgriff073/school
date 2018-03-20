#include <iostream>
#include "course.h"
#include <string>
using namespace std;
long Course::nextCRN=200;

Course::Course(string cName,long depId,long taughtBy,int maxSeats)
{
depId=departId;
assignedSeats=0;
isTaughtBy=taughtBy;
CRN=nextCRN;
nextCRN++;
maxAvailableSeats=maxSeats;
name=cName;
}

void Course::print()
{
cout<<"Course Number: "<<CRN<<endl;
cout<<"Max available seats: "<<maxAvailableSeats<<endl;
cout<<"Name: "<<name<<endl;
}
