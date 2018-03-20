#include <iostream>
using namespace std;
/*
name:getDayOfWeek
purpose:get a number which represents a day of a week
parameters:int that will get converted to a string
return:string that represents day of week
precondition:must be between 0 and 6
last modified:10/1
*/
string getDayOfWeek(int);
/*
name:minToSeconds
purpose:convert minutes to seconds
parameters:int that will be returne
return:int that represents amount of seconds
precondition:
last modified:10/1
*/

int minToSeconds(int min);
/*
name:hrToMinutes
purpose:convert the amount minutes given into seconds
parameters:int that will be multiplied by 60
return:int that represents amount of minutes
precondition:
last modified:10/1
*/

int hrToMinutes(int hours);
/*
name:daysToHours
purpose:convert amount of days given into hours
parameters:int that will be multiplied by 24
return:int that represents amount of hours
precondition:
last modified:10/1
*/

int daysToHours(int days);
/*
name:getDays
purpose:get amount of days from the user
parameters:int
return:int 
precondition:
last modified:10/1
*/

int getDays();
/*
name:getDay
purpose:get amount of days to be converted to hours to minutes to seconds
parameters:int that will be returned to main
return:int 
precondition:
last modified:10/1
*/

int getDay();

int main()
{
int days=0;
int hour=0;
int min=0;
int day=0;
int seconds=0;
day=getDay();
//display what day of the week it is based on value retuned from getDayOfWeek
cout<<"Today is "<<getDayOfWeek(day);
days=getDays();
hour=daysToHours(days);
min=hrToMinutes(hour);
seconds=minToSeconds(min);
//display how many seconds there are in the amount of days entered.
cout<<"There are "<<seconds<<" seconds in "<<days<<" day(s)"<<endl;
cout<<"Which is "<<min<<" minutes"<<endl;
return 0;

}//end of main
int getDay()
{
int day=0;
cout<<"This program will tell what day it is based on what number you enter"<<endl;
cout<<"Please enter a value between 0 and 6, 0 being Sunday and 6 being Saturday"<<endl;
cin>>day;
return day;

}//end of getDay


//start of getDayOfWeek
string getDayOfWeek(int day )
{
switch( day)
{


case 0:
return "Sunday\n";


case 1:
return "Monday\n";


case 2:
return "Tuesday\n";


case 3:
return "Wednesday\n";


case 4:
return "Thursday\n";


case 5:
return "Friday\n";


case 6:
return "Saturday\n";

default:
return "Value entered is not in valid range";
}
}


int minToSeconds(int min)
{
return (min*60);
}//end of minToSeconds


int hrToMinutes(int hour)
{
return(hour*60);
}//end of hrToMinutes


int daysToHours(int days)
{
return (days*24);
}//end of daysToHours


int getDays()
{
int days=0;
cout<<"Now the program will convert days to seconds.\nPlease enter an amount of days you would like to be converted.";
cin>>days;
return days;
}//end of getDays

