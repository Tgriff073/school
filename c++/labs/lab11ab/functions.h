using namespace std;
void driver();
void partB();

enum Day
{
     Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};
//dayM is for day of the month like the 7th day. DayW is for day of the week like Monday or Tuesday
struct Date
{
int dayM;
int month;
int year;
Day dayW;
};
void partBDisplay(Date);

void driver()
{
StudentRec finGrade;
partB();
void init();
//char choice is set to Y in order to go through the loop atleast once
char choice='Y';
//loops until user enters Y or y
while (choice=='Y')
{
finGrade.getInput(finGrade);
finGrade.calculateGrade(finGrade);
string myGrade=finGrade.getFinalGrade(finGrade);
cout<<myGrade<<endl;
cout<<"Would you like to try a different set of scores?(Y/N)\n";
cin>>choice;
//sets whatever user enters to uppercase
choice=(toupper(choice));
}//end of drivwer

//system("PAUSE");
}
/*
declares a variable that is type Date and initializes the variables inside to 
hold the date equal to november 7th 2013*/
void partB()
{

Date date;
date.dayM=7;
date.month=11;
date.year=2013;
date.dayW=Friday;
partBDisplay(date);
//system("PAUSE");
}

void partBDisplay(Date date)
{
cout<<date.year<<"/"<<date.month<<"/0"<<date.dayM<<endl;
}
//user enter data is taken in here. 
void StudentRec::getInput(StudentRec& finGrade)
{
cout<<"You will be prompted to enter the percent you have in each grade category in order to calculate your final grade\n";
cout<<"Labs:\n";
cin>>finGrade.labs;
cout<<"Homework:\n";
cin>>finGrade.hw;
cout<<"Quizzes:\n";
cin>>finGrade.quizzes;
cout<<"Exam one:\n";
cin>>finGrade.test1;
cout<<"Exam two:\n";
cin>>finGrade.test2;
cout<<"Final exam:\n";
cin>>finGrade.test3;
}//end of getInput


