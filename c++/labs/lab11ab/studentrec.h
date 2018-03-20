using namespace std;

enum Grades {A, Aminus, Bplus, B, Bminus, Cplus, C, D, F};

struct StudentRec
{
Grades letterGrade;
double labs;
double hw;
double quizzes;
double test1;
double test2;
double test3;
void calculateGrade(StudentRec&);
string getFinalGrade(StudentRec);
void getInput(StudentRec&);
void init();
};

string StudentRec::getFinalGrade(StudentRec finGrade)
{
string grade="";
/*switch case begins.(Returns string that corresponds with A value from enum Grade
*/
switch(letterGrade)
{
case A:
grade="You have an A";
break;
case Aminus:
grade="You have an A-";
break;
case Bplus:
grade="You have a B+";
break;
case B:
grade="You have a B";
break;
case Bminus:
grade="You have a B-";
break;
case Cplus:
grade="You have a C+";
break;
case C:
grade="You have a C";
break;
case D:
grade="You have a D";
break;
case F:
grade="You have an F";
break;
}
return grade;
}//end of getFinalGrade

void StudentRec::calculateGrade(StudentRec& finGrade)
{
double fin=0.0;
fin=((finGrade.labs*.15)+(finGrade.hw*.1)+(finGrade.test1*.15)+(finGrade.test2*.2)+(finGrade.test3*.35)+(finGrade.quizzes*.05));
/*begin of if else  in order to determine what grade the person has in the class
and assigns the corresponding value to letterGrade, which is an enum.*/

if (fin>=92)
letterGrade=A;
else if(fin>=89)
letterGrade=Aminus;
else if(fin>=86)
letterGrade=Bplus;
else if (fin>=82)
letterGrade=B;
else if (fin>=79)
letterGrade=Bminus;
else if(fin>=76)
letterGrade=Cplus;
else if(fin>=70)
letterGrade=C;
else if (fin>=60)
letterGrade=D;
else
letterGrade=F;
}//end of calculateGrade
                             
