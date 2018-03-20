#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "university.h"

using namespace std;


bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
University::University()
{

}
//----------------------------------------------------------------------------

University::~University()
{

}
//----------------------------------------------------------------------------

bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
/*
	- If the depChairId is 0, it means the chair is not known yet; otherwise, you need
	  to check if the depChairId passed to this method is a valid existing faculty.
	  print appropriate message and return failure if the chair is not valid
	  

	- create an object of department that calls appropriate constructor to assign
	  these values
	- the value of id should be assigned to the value of nextDepartId
	- Make sure to increment the value of nextDepartId by 1 in the constructor
	- insert the new object to the Departments vector
	- return success
*/
	for(int i=0;i<Departments.size();i++)
	{
		if(depChairId==Departments[i].id)
			return University::failure;
	}		

	Department dept(depName,depLoc,depChairId);
	Departments.push_back(dept);
	return University::success;
}
//----------------------------------------------------------------------------

bool University::RemoveADepartment(long depId)
{
/*
	- check if the depId passed to this method is a valid existing department id. If not
	  return failure; otherwise,
	- search and remove the department from the Departments vector only if the department has no faculty 
	  and offers no course and no student's major matches the department name 
	- return success
*/
	for(int i=0;i<Departments.size();i++)
	{
		if(depId==Departments[i].id)
		{
			for(int j=0; j<Faculties.size();j++)
			{
				if(depId==Faculties[j].departId)
					return University::failure;
			}
			for(int j=0; j<Students.size();j++)
			{
				if(Departments[i].name==Students[j].major)
					return University::failure;
			}
			for(int j=0; j<Courses.size();j++)
			{
				if(Courses[j].departId==depId)
					return University::failure;	
			}
			Departments.erase(Departments.begin()+i);
			return University::success;
		}
	}
	
}
//----------------------------------------------------------------------------

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
/*
	- If the sMajor is 0, it means the student has not chosen a major; otherwise, you need
	  to check if the sMajor passed to this method is a valid existing department name.
	  print appropriate message and return failure if this is not the case

 	- If the sAdvisorId is 0, it means the student has not chosen an advisor or does not need 
	  an advisor; otherwise, you need to check if the sAdvisorId passed to this method 
	  is a valid existing faculty id. Print appropriate message and return failure if this is not the case

	  
	- create an object of student that calls appropriate constructor to assign
	  these values
	- the value of id should be assigned to the value of nextSttId
	- Make sure to increment the value of nextStId by 1 in the constructor
	- insert the new object to the Students vector
	- return success 
	
	- Note: The vector CourseTaken should be initially empty. You can use the appropriate methods 
	  shown in the University class to add or drop a course for a student later
*/
	for(int i=0; i<Departments.size();i++)
	{
		if(Departments[i].name==sMajor||sMajor==""||true)
		{	
			for(int j=0;j<Faculties.size();j++)
			{
				if(Faculties[j].id==sAdvisorId||sAdvisorId==0)
				{	cout<<"second"<<endl;
					Student std(sName,sEmail,sAddress,sDateOfBirth,sGender,sYearOfStudy,sMajor,sAdvisorId);
					Students.push_back(std);
					return University::success;
				}
			}
		}
	}
return University::failure;
}
//----------------------------------------------------------------------------

bool University::RemoveAStudent(long sStId)
{
/*
	- check if the sStId passed to this method is a valid existing student id. If not
	  return failure; otherwise,
	- search and remove the student from the Students vector
	- make sure that before removing the student, you need to call the drop course method to drop his/her
	  courses
	- return success
*/
	for(int i=0;i<Students.size();i++)
	{
		if(Students[i].id==sStId)
		{
			long courseId=0;
			for(int j=0;j<Students[i].coursesTaken.size();j++)
			{
				courseId=Students[i].coursesTaken[j].CRN;
				DropACourseForAStudent(courseId, sStId);
			}
			Students.erase(Students.begin()+i);
			return University::success;
		}
	}	
	return University::failure;
}
//----------------------------------------------------------------------------

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
/*
	- If the cTaughtBy is 0, it means no one is assigned to teach this course. 
	  otherwise, you need to check if the cTaughtBy passed to this method is a 
	  valid existing faculty. Print appropriate message and return failure if 
	  this is not the case

    - you need to check if the cDepId passed to this method is a valid existing department. 
	  Print appropriate message and return failure if this is not the case

	- create an object of Course that calls appropriate constructor to assign these values
	- the value of assigned seats should be assigned to zero in the constructor
	- the value of CRN should be assigned to the value of nextCRN
	- Make sure to increment the value of nextCRN by 1 in the constructor
	- insert the new object to the Courses vector
	- return success
*/
	for(int i=0;i<Faculties.size();i++)
	{
		if(Faculties[i].id==cTaughtBy)
		{cout<<"fisrt check````````````````````````````````"<<endl;
			for(int j; j<Departments.size();j++)
			{
				cout<<"for for for for for for for for for for"<<endl;
				if(Departments[j].id==cDepId)
				{cout<<"Second check~~~~~~~~~~~~~~~~~~~~"<<endl;
					Course crs(cName,cDepId,cTaughtBy,cMaxSeat);
					Courses.push_back(crs);
					return University::success;
				}
			}
		}

	}
	return University::failure;
}
//----------------------------------------------------------------------------

bool University::RemoveACourse(long cCRN)
{
/*
	- check if the cCRN passed to this method is a valid existing course id. If not
	  return failure; otherwise,
	- search and remove the course from the Courses vector only if no student is currently taking 
	  this course 
	- return success
*/
	for(int i=0;i<Courses.size();i++)
	{
		if(cCRN==Courses[i].CRN)
		{	
			for(int j=0;j<Students.size();j++)
			{
				for(int k=0;k<Students[j].coursesTaken.size();k++)
				{
					if(Students[j].coursesTaken[k].CRN==cCRN)
						return University::failure;
					
				}
			}
			Courses.erase(Courses.begin()+i);
			return University::success;
		}	
	}
}
//----------------------------------------------------------------------------

bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
								  float fSalary, int fYearOfExp, long fDepId)
{
/*
    - you need to check if the fDeptId passed to this method is a valid existing department. 
	  Print appropriate message and return failure if this is not the case

	- create an object of Faculty that calls appropriate constructor to assign these values
	- the value of faculty id should be assigned to the value of nextFacultyId
	- Make sure to increment the value of nextFacultyId by 1 in the constructor
	- insert the new object to the Faculties vector
	- return success
*/
	for(int i=0;i<Departments.size();i++)
	{
		if(Departments[i].id==fDepId)
		{
			Faculty fac(fName,fEmail,fAddress,fDateOfBirth,fGender,fSalary,fYearOfExp,fDepId);
			Faculties.push_back(fac);
			return University::success; 

		}
	}
return University::failure;
}
//----------------------------------------------------------------------------

bool University::RemoveAFaculty(long fFactId)
{
/*
	- check if the fFactId passed to this method is a valid existing faculty id. If not
	  return failure; otherwise,
	- search and remove the faculty from the Faculties vector only if this faculty is not 
	  teaching a course nor advising any student, nor chairing any department
	- return success
*/
	for(int i=0;i<Faculties.size();i++)
	{
		if(Faculties[i].id==fFactId)
		{
			Faculties.erase(Faculties.begin()+i);
			return University::success;
		}
	}	
return University::failure;
}
//----------------------------------------------------------------------------

bool University::ListCoursesTaughtByFaculty(long facultyId)
{
/*
	- This routine should list all the courses (courseId and CourseName)
	  that are currently being taught by a particular faculty 
	- make sure that the facultyId passed to this method is a valid existing 
	  faculty id. If this is not the case print appropriate message and return failure; 
	  otherwise, return success

*/
	for(int i=0;i<Faculties.size();i++)
	{
		if(Faculties[i].id==facultyId)
		{
			for(int j=0;j<Courses.size();j++)
			{
				if(Courses[j].isTaughtBy==facultyId)
				{
					cout<<"Course name: "<<Courses[j].name<<endl;
					cout<<"Course number: "<<Courses[j].CRN<<endl;
				}
			
			}
		return University::success;
		}
	
	}
	
return University::failure;
}
//----------------------------------------------------------------------------

bool University::ListCoursesTakenByStudent(long studentId)
{
/*
	- This routine lists all the courses (courseId and CourseName) 
	  that currently taken by a particular student
	- make sure that the studentId passed to this method is a valid existing 
	  student id. If this is not the case print appropriate message and return failure; 
	  otherwise, return success

*/
	for(int i=0;i<Students.size();i++)
	{
		if(studentId==Students[i].id)
		{
			for(int j=0;j<Students[i].coursesTaken.size();j++)
			{
				cout<<"Course name: "<<Students[i].coursesTaken[j].name<<endl;
				cout<<"Course number: "<<Students[i].coursesTaken[j].CRN<<endl;
			}
		return University::success;
		}
		
	}
	return University::failure;
}
//----------------------------------------------------------------------------

bool University::ListFacultiesInDepartment (long departId)
{
/*
	- This routine lists all the faculties (facultyId, facultyName) in a particular 
	  department
	- make sure that the departId passed to this method is a valid existing 
	  department id. If this is not the case print appropriate message and return failure; 
	  otherwise, return success

*/
	for(int i=0;i<Departments.size();i++)
	{	
	
		if(Departments[i].id==departId)
		{
			
	
			for(int j=0;j<Faculties.size();j++)
			{
				if(Faculties[j].departId==departId)
				{
					cout<<"Name: "<<Faculties[j].name<<endl;
					cout<<"Id: "<<Faculties[j].id<<endl;
				}
			}
		
		return University::success;	
		}
	}
return University::failure;
}
//----------------------------------------------------------------------------

bool University::ListStudentsOfAFaculty(long facultyId)
{
/*
	- This routine lists all the students (studentId and studentName) of a particular 
	  faculty
	- make sure that the facultyId passed to this method is a valid existing 
	  faculty id. If this is not the case print appropriate message and return failure; otherwise, 
	  return success
	  
*/
	for(int k=0;k<Faculties.size();k++)
	{
		if(Faculties[k].id==facultyId)
		{ 
			for(int i=0;i<Students.size();i++)
			{
				for(int j;j<Students[i].coursesTaken.size();j++)
				{
					if(Students[i].coursesTaken[j].isTaughtBy==facultyId)
					{
						cout<<"Student name: "<<Students[i].name<<endl;
						cout<<"Student id: "<<Students[i].id<<endl;
					}
				}
			}
		return University::success;
		}
	}
	return University::failure;
}
//----------------------------------------------------------------------------

bool University::ListCoursesOfADepartment(long departId)
{
/*
	- This routine lists all the courses offered by a particular department
	- make sure that the departId passed to this method is a valid existing 
	  department id. If this is not the case print appropriate message and return failure; otherwise, 
	  return success
*/
	 for(int i=0;i<Departments.size();i++)
        {
                if(Departments[i].id==departId)
                {
			for(int j=0;j<Courses.size();j++)
			{
				if(Courses[i].departId==departId)
				{
					cout<<"Course Name: "<<Courses[i].name<<endl;
					cout<<"Course Id: "<<Courses[i].CRN<<endl;
				}
			}
		return University::success;
		}
	}
return University::failure;
}
//----------------------------------------------------------------------------

bool University::AddACourseForAStudent(long courseId, long stId)
{
/*
	- This routine adds a course for a student
	- When you add a course for a student, you need to ensure that there is enough seat in that class
	  Increment the number of assigned seats if you could enroll the student for this course
	- make sure that the courseId and stId passed to this method are both valid 
	  If this is not the case print appropriate message and return failure; otherwise, 
	  return success
*/
	for(int i=0;i<Courses.size();i++)
	{
		if(Courses[i].CRN==courseId&&(Courses[i].assignedSeats<Courses[i].maxAvailableSeats))
		{
			for(int j=0;j<Students.size();j++)
			{
				if(Students[j].id==stId)
				{
					for(int k=0;k<Courses.size();k++)
					{
						if(Courses[k].CRN==courseId)
						{
							Courses[k].assignedSeats++;
							Students[j].coursesTaken.push_back(Courses[k]);
							return University::success;
						}
					}
				}
			}
		}	
	}
	return University::failure; 
}
//----------------------------------------------------------------------------

bool University::DropACourseForAStudent(long courseId, long stId)
{
/*
	- This routine drops a course for a student
	- When you drop a course for a student, you need to decrement the number of assigned 
	  seats for that course
	- make sure that the courseId and stId passed to this method are both valid 
	  If this is not the case print appropriate message and return failure; otherwise, 
	  return success
*/

 for(int i=0;i<Courses.size();i++)
        {
                if(Courses[i].CRN==courseId)
                {
                        for(int j=0;j<Students.size();j++)
                        {
                                if(Students[j].id==stId)
                                {
                                        for(int k=0;k<Courses.size();k++)
                                        {
                                                if(Students[j].coursesTaken[k].CRN==courseId)
                                                {
                                                        Courses[k].assignedSeats--;
                                                        Students[j].coursesTaken.erase(Students[i].coursesTaken.begin()+k);
                                                        return University::success;
                                                }
                                        }
                                }
                        }
                }
        }
        return University::failure;
                   
}
//----------------------------------------------------------------------------

bool University::AssignDepartmentChair(long facultyId, long departId)
{
/*
	- This routine assigns a chair to a department
	- make sure that the facultyId and departId passed to this method are both valid 
	  If this is not the case print appropriate message and return failure; otherwise, 
	  return success
*/
	for(int i=0;i<Faculties.size();i++)
	{
		if(Faculties[i].id==facultyId)
		{
			for(int j=0;j<Departments.size();j++)
			{
				if(Departments[j].id==departId)
				{
					Departments[j].chairId=facultyId;
					return University::success;
				}
			}
		}
	return University::failure;
	}
}
//----------------------------------------------------------------------------

bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
/*
	- This routine assigns a course to an instructor to teach
	- make sure that the courseId and facultyId passed to this method are both valid.
	  If this is not the case print appropriate message and return failure; otherwise, 
	  return success
*/
	for(int i=0;i<Faculties.size();i++)
	{
		if(Faculties[i].id==facultyId)
		{
			for(int j=0;j<Courses.size();j++)
			{
				if(Courses[j].CRN==courseId)
				{
					Courses[j].isTaughtBy=facultyId;
					return University::success;
				}
			}
		}
	}
	return University::failure;
}
//----------------------------------------------------------------------------
bool University::ListDepartments()
{
/*
	- This method should list the department id's and department names only
*/
	for(int i=0;i<Departments.size();i++)
	{
		cout<<"Department name: "<<Departments[i].name<<endl;
		cout<<"Department Id: "<<Departments[i].id<<endl;
	}
	return University::success;
}
//----------------------------------------------------------------------------

bool University::ListStudents()
{
/*
	- This method should list the student id's and student names only
*/
	for(int i=0;i<Students.size();i++)
	{
		cout<<"Student name: "<<Students[i].name<<endl;
		cout<<"Student id: "<<Students[i].id<<endl;
	}
	return University::success;
}
//----------------------------------------------------------------------------
bool University::ListCourses()
{
/*
	- This method should list the course id's and course names only
*/
	for(int i=0;i<Courses.size();i++)
	{
		cout<<"Course name: "<<Courses[i].name<<endl;
		cout<<"Course Id: "<<Courses[i].CRN<<endl;	
	}
	return University::success;
}
//----------------------------------------------------------------------------
bool University::ListFaculties()
{
/*
	- This method should list the faculty id's and faculty names only
*/
	for(int i=0;i<Faculties.size();i++)
	{	
		cout<<"Faculty name: "<<Faculties[i].name<<endl;
		cout<<"Faculty Id: "<<Faculties[i].id<<endl;

	}
	return University::success;
}

//----------------------------------------------------------------------------
bool University::ProcessTransactionFile (string fileName)
{
/*
	- open the transaction file and process it one by one
	- If the file could not be opened, print appropriate message and return failure; 
	  otherwise, return success
*/
	ifstream fin(fileName.data());
	string cmd;
	while(fin>>cmd)
	{	cout<<setfill('=')<<setw(30)<<" "<<endl;
		cout<<cmd<<endl;
		cout<<setw(30)<<" "<<endl;
		if(cmd=="CreateNewDepartment")
		{
			string depName="";
			string	depLoc="";	
			long depChairId=0;
			fin>>depName>>depLoc>>depChairId;
			if(CreateNewDepartment(depName,depLoc,depChairId))
				cout<<"Department "<<depName<<" successfully created!"<<endl;
			else
				cout<<"Failed to create department "<<depName<<endl;
		}
		else if(cmd=="CreateNewFaculty")
		{
			string name,email,address,dob,gender;
			long salary,depId;
			int year;
			fin>>name>>email>>address>>dob>>gender>>salary>>year>>depId;
			if(CreateNewFaculty(name,email,address,dob,gender,salary,year,depId))
				cout<<"Faculty member "<<name<<" successfully added!"<<endl;
			else 
				cout<<"Failed to add faculty member "<<name<<"!"<<endl;
		}
		else if(cmd=="RemoveADepartment")
		{
			long depId=0;
			fin>>depId;
			if(RemoveADepartment(depId))
				cout<<"Department "<<depId<<" successfully removed!"<<endl;
			else 
				cout<<"Failed to delete department "<<depId<<endl;
			
		}
		else if(cmd=="CreateNewStudent")
		{
			string name,email,address,dob,gender,major;
			int year=0;
			long advisorId=0;
			fin>>name>>email>>address>>dob>>gender>>year>>major>>advisorId;
			if(CreateNewStudent(name,email,address,dob,gender,year,major,advisorId))
				cout<<"Student "<<name<<" was successfully created!"<<endl;
			else
				cout<<"Failed to create student named "<<name<<endl;
		}
		else if(cmd=="RemoveAStudent")
		{
			long stId;
			fin>>stId;
			if(RemoveAStudent(stId))
				cout<<"Successfully removed student "<<stId<<endl;
			else
				cout<<"Failed to remove student "<<stId<<endl;
		}
		else if(cmd=="CreateNewCourse")
		{
			string name;
			long depId,taughtBy;
			int maxSeats;
			fin>>name>>depId>>taughtBy>>maxSeats;
			if(CreateNewCourse(name,depId,taughtBy,maxSeats))
				cout<<"Course "<<name<<" was successfully created!"<<endl;
			else
				cout<<"Failed to create course "<<name<<"!"<<endl;
		}
		else if(cmd=="RemoveACourse")
		{
			long cn;
			fin>>cn;
			if(RemoveACourse(cn))
				cout<<"Successfully removed course "<<cn<<"!"<<endl;
			else
				cout<<"Failed to remove course"<<cn<<"!"<<endl;
		}
		else if(cmd=="RemoveAFaculty")
		{
			long fId;
			fin>>fId;
			if(RemoveAFaculty(fId))
				cout<<"Successfully removed faulty member "<<fId<<endl;
			else 
				cout<<"Failed to remove faculty member "<<fId<<endl;
		}
		else if(cmd=="ListCoursesTaughtByFaculty")
		{
			long fId;
			fin>>fId;
			ListCoursesTaughtByFaculty(fId);
		}
		else if(cmd=="ListCoursesTakenByStudent")
		{
			long stId;
			fin>>stId;
			ListCoursesTakenByStudent(stId);
		}
		else if(cmd=="ListFacultiesInDepartment")
		{
			long depId;
			fin>>depId;
			ListFacultiesInDepartment(depId);
		}
		else if(cmd=="ListStudentsOfAFaculty")
		{
			long fId;
			fin>>fId;
			ListStudentsOfAFaculty(fId);
		}
		else if(cmd=="ListCoursesOfADepartment")
		{
			long depId;
			fin>>depId;
			ListCoursesOfADepartment(depId);
		}
		else if(cmd=="AddACourseForAStudent")
		{
			long cId,stId;
			fin>>cId>>stId;
			if(AddACourseForAStudent(cId,stId))
				cout<<"Course "<<cId<<"was successfully added for student "<<stId<<"!"<<endl;
			else
				cout<<"Failed to add course "<<cId<<" for student "<<stId<<"!"<<endl;
		}
		else if(cmd=="DropACourseForAStudent")
		{
			long cId,stId;
			fin>>cId>>stId;
			if(DropACourseForAStudent(cId,stId))
				cout<<"Course "<<cId<<" was successfully dropped for student "<<stId<<"!"<<endl;
			else 
				cout<<"Failed to drop course "<<cId<<" for student"<<stId<<endl;
		}
		else if(cmd=="AssignDepartmentChair")
		{
			long fId,depId;
			fin>>fId>>depId;
			if(AssignDepartmentChair(fId,depId))
				cout<<fId<<" was successfully assigned as the chair of the department "<<depId<<"!"<<endl;
			else
				cout<<"Failed to assign "<<fId<<" as the chair of the department "<<depId<<"!"<<endl;
		}
		else if(cmd=="AssignInstructorToCourse")
		{
			long fId,cId;
			fin>>fId>>cId;
			if(AssignInstructorToCourse(fId,cId))
				cout<<fId<<" was successfully assigned to the course "<<cId<<"!"<<endl;
			else
				cout<<"Failed to assign "<<fId<<" as the instuctor of the course "<<cId<<"!"<<endl;
		}
		else if(cmd=="ListDepartments")
			ListDepartments();
		else if(cmd=="ListStudents")
			ListStudents();
		else if(cmd=="ListCourses")
			ListCourses();     
		else if(cmd=="ListFaculties")
			ListFaculties();	
		cout<<"\n"<<setw(30)<<" "<<endl<<endl;

	}


}
//--------------------------------------------------------------------------
