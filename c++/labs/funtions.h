using namespace std;

void driver();
void init(string[]);
void readIn(string&,string&,ifstream&);
void compare(string,string,string[]);
void initS(string[]);
void initF(float[],float[]);
int compareF(float[],int,int);
void driver2();
void initArray(double[][6]);
void displayArrayR(double[][6]);
void displayArrayC(double[][6]);
void part6();
void part7();
void displaySum(double[][6]);
//controls everything for part two
void driver()
{
  cout<<"This program will compare the strings stored in an array to two strings stored in input.dat\nhere are the results:\n\n";
  ifstream fin;
  int nCompare=0;
  int size=5;
  int greaterThan=0;
  string fOne="";
  string fTwo="";
  string myArray[5];
  float fArray[5];
  float ftArray[8];
  fin.open("input.dat");
  readIn(fOne,fTwo,fin);
  initS(myArray);
  compare(fOne,fTwo,myArray);
  fin.close();
  cout<<"\n\nThe program will now comapare a number you enter to numbers stored in an\narray\n";
  cout<<"Please enter a number to compare:\n";
  cin>>nCompare;
  initF(fArray,ftArray);
  greaterThan=compareF(fArray,size,nCompare);
  cout<<"There are "<<greaterThan<<" numbers in the first array that were larger than the number you entered"<<endl; 
  size=8;
  greaterThan=compareF(ftArray,size,nCompare);
  cout<<"and there are "<<greaterThan<<" numbers in the second array that were larger than the number you entered"<<endl;
 //Part three
 cout<<"\n\nPart Three:\n\n";
 driver2();
}//end of driver

//controls everything for part 3
void driver2()
{
  const int Num_Rows=6;
  const int Num_Cols=4;
  double array[Num_Cols][Num_Rows];
  initArray(array);
  displayArrayR(array);
  displayArrayC(array);
  part6();
  part7();
  displaySum(array);
}//end of driver2

//initializes myArray to hold 5 different string values
void initS(string myArray[])
{
  myArray[0]="Horse";
  myArray[1]="Pig";
  myArray[2]="Dog";
  myArray[3]="Cat";
  myArray[4]="Goat";
}//End of initS

//void readIn grabs the first two lines in the file and stores them to two string variables
void readIn(string& one,string& two,ifstream& fin)
{
  getline(fin, one);
  getline(fin, two);
}//end of readIn

//void compare checks to see if any of the strings in a file match any strings in an array
void compare(string one,string two,string myArray[])
{
  for(int i=0;i<5;i++)
   {
     if(one==myArray[i])
       cout<<myArray[i]<<" matches the string stored in index #"<<i<<endl;
     else if(two==myArray[i])
       cout<<myArray[i]<<" matches the string stored in index #"<<i<<endl;
     else
       cout<<"The word stored in index #"<<i<<" does not match any strings in the file"<<endl;
   }
}//end of compare

//initF initializes the values in two float arrays to different values
void initF(float one[], float two[])
{
  one[0]=5.67;
  one[1]=6.78;
  one[2]=9.86;
  one[3]=10.34;
  one[4]=3.22;
 
  two[0]=1.22;
  two[1]=2.34;
  two[2]=5.66;
  two[3]=6.98;
  two[4]=7.82;
  two[5]=9.55;
  two[6]=7.32;
  two[7]=11.65;

}//end of initF

//compareF compares a user entered value to the values in an array and counts how many numbers in the array are larger then the user entered number
int compareF(float array[],int size,int compare)
{
int j=0;

for(int i=0;i<size;i++)
 {
 if(array[i]>compare)
  j++; 
 }
return j;
}//end of compareF

//PART THREE FUNCTIONS

//void initArray initializes all values in a 4x6 array to 5.0
void initArray(double array[][6])
{int value=0;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<6;j++)
    {
      value++;
      array[i][j]=value;
    }//end innerloop(controlling column)
  }//end outerloop(controlling row)
}//end of initArray


//void displayArrayR displays an array by rows
void displayArrayR(double array[][6])
{
  for(int i=0;i<4;i++)
  {
    cout<<"Row "<<i<<": ";
    for(int j=0;j<6;j++)
    {
      
      cout<<array[i][j]<<" ";
     
      
    }//end innerloop(controlling column)
    cout<<endl;
  }//end outerloop(controlling row)
}//end displaArrayR

//void displayArrayC displays a 4x6 array by column
void displayArrayC(double array[][6])
{
  
  for (int j=0;j<6;j++)
  {
    cout<<"Column"<<j<<endl;
    for(int i=0;i<4;i++)
    {
     cout<<array[i][j]<<endl;
    }//end of innerloop (control row)
  cout<<endl;
  }//end of outerloop (control column)
}//end displayArrayC  

//void part6 checks answers for part 6
void part6()
{
string myArray[10];
myArray[0]="This ";
myArray[1]="is ";
myArray[2]="my ";
myArray[3]="array ";
myArray[4]="holding ";
myArray[5]="ten ";
myArray[6]="different ";
myArray[7]="string ";
myArray[8]="values";
myArray[9]="!\n";

for(int i=0;i<10;i++)
 {
  cout<<myArray[i];
 }//end of loop
}//end part6

//void part7 checks answers for part 7
void part7()
{
  int yourArray[7];
  for(int i=0;i<7;i++)
  {
    yourArray[i]=2;
  }//end of loop
  cout<<"The values in yourArray are:\n";
  for(int i=0;i<7;i++)
  {
   cout<<yourArray[i]<<endl;
  }
}//end of part7

void displaySum(double array[][6])
{
double sum=0;

for(int i=0;i<4;i++)
 {
  for(int j=0;j<6;j++)
   {
    sum+=array[i][j];
   }
  
 }
cout<<"The sum is "<<sum;
}
