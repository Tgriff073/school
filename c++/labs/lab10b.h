using namespace std;
void test1();
void test2();
void test3();

int myFunction(ifstream&);
int test4();
int modifyString(string&);
void driver();


void driver()
{
int num=0;
test1();
test2();
test3();
ifstream fin;
fin.open("input.dat");
num=myFunction(fin);
cout<<num<<endl;
test4();
}
void test1()
{
int a=85;
int b=119;

while ((a > 0) && (b > 0)) 
{ 
if (a > b) 
a = a % b; 
else 
b = b % a; 
}//end of while loop
if (a == 0) 
cout << "the gcd is: " << b << endl; 
else 
cout << "the gcd is: " << a << endl; 
}
void test2()
{
int i = 1; 
int j; 
while (i <= 3) 
{ 
 j = 2; 
 while (j >= 1) 
 { 
 cout << "Value = "  << i * j << endl; 
 j--; 
 }//end inner LOOP 
 cout << endl; 
 i++; 
}//end outer LOOP
}

void test3()
{ 
int i;
int j; 
for (i=1; i <= 3; i++) 
{ 
  
 for (j=2; j >= 1;j--) 
 { 
 cout << "Value = " << j * i << endl; 
 }//end inner LOOP 
 cout << endl;  
}//end outer LOOP
}

int myFunction(ifstream& fin)
{
 int total =0; 
 int low = 0; 
 int myValue = 0; 
 
 fin >> myValue; 
 
 total = myValue; 
 low = myValue; 
 
 for (int i = 1; i < 12; i++) 
 { 
 fin >> myValue; 
if (myValue < low) 
 low = myValue; 
 total = total + myValue; 
 } 
 fin.close(); 
 return ( total - low ); 
}//end function 

int test4()
{
{ 
string myValue; 
cout << myValue << endl; 
myValue = "aaa bbb"; 
int x = modifyString(myValue); 
if ( x > 1 ) 
cout << myValue << endl; 
myValue = myValue + " ccc"; 
cout << myValue << endl; 
return 0; 
}//end main 
}//Function definition 

int modifyString(string & myString) 
{ 
cout << myString << endl; 
myString = "xyz"; 
return 1; 
cout << myString <<endl; 
}//end function 


