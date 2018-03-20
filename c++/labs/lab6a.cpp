



#include <iostream>
using namespace std;
/*
Name:calculatePercent
Purpose:Calculate the percent correct given the number the number of questions and the number of corredt answers.
Parameters:two integers which hold the value of amount true out of amount possible
Return:double which hods the value of the percent calculated
Pre-Condition:n/a
Post-Condition:n/a
Last Modification:9/29/14 
*/
double calculatePercent(int, int);


int main()
{
int questionsRight=0;
int totalQuestions=0;
double testPercentage=0.0;
cout<<"This program will calculate your test percentage based on how many questions there were.\n";
cout<<"Please enter the amount of questions you got right:"<<endl;
cin>>questionsRight;
cout<<"Please enter the total amount of questions on the test:"<<endl;
cin>>totalQuestions;
testPercentage=calculatePercent(questionsRight, totalQuestions);
cout<<"Your percentage was: "<<testPercentage<<endl;
cout<<"Now we will use the same program to calclulate the percentage of females in a class"<<endl;
cout<<"Please enter the amount of females in you class:";
cin>>questionsRight;
cout<<"Now enter the total amount of students:";
cin>>totalQuestions;
testPercentage= calculatePercent(questionsRight, totalQuestions);
cout<<"The class is "<<testPercentage<<" percent females."<<endl;

return 0;
}//end of main

double calculatePercent(int questionsRight, int totalQuestions)
{
return ((questionsRight*1.0)/(totalQuestions*1.0))*100;
}
