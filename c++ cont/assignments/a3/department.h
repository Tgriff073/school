#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
using namespace std;

class Department
{
	friend class University; 
	protected:
		long id;
		string name;
		string location;
		long chairId;
		static long nextDepartId;


	public:
		Department(string,string,long);
		void print() const;
};
#endif//DEPARTMENT_H
