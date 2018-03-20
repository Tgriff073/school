#include <iostream>
#include "department.h"
using namespace std;
long Department::nextDepartId=100;


Department::Department(string depName, string depLoc,long depChairId)
{	
	id=nextDepartId;
	nextDepartId++;
	name=depName;
	location=depLoc;
	chairId=depChairId;
}

void Department::print()const
{
	cout<<"Department Name "<< name << endl;
	cout<<"Department location "<<location<<endl;
	cout<<"Department Id "<<chairId<<endl;
}
