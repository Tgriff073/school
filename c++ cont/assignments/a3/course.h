#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course
{
 friend class University;
	protected:
 		long CRN;
 		int maxAvailableSeats;
 		string name;
		long departId;
		long assignedSeats;
		long isTaughtBy;
		static long nextCRN;
 		
	public:
        Course(string cName ,long depId,long taughtBy,int maxSeats);
		void print();
};

#endif//Course_H
