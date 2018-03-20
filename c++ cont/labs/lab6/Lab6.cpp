#include<iostream>
#include<fstream>
#include<string>
using namespace std;




class TheMatrix;

// Function Prototype Section
TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix  operator+ (const TheMatrix& M1, const TheMatrix& M2);
TheMatrix  operator* (const TheMatrix& M1, const TheMatrix& M2);
ifstream&   operator>> (ifstream& is, TheMatrix& myMatrix); 
ostream&   operator<< (ostream& is, const TheMatrix& myMatrix);

// End of prototype section

class TheMatrix
{
// MAKE ALL THE FUNCTIONS DEFINED IN THE PROTOTYPE SECTION 
// ABOVE TO BE FRIEND OF THIS CLASS
	

public:
	int  M[5][5];	// 5 by 5 matrix of integer
	
	TheMatrix();
	~TheMatrix();
	
};

//------------------------------------------
// Deconstructor
TheMatrix::~TheMatrix()
{

}

//------------------------------------------
//Default Constructor
TheMatrix::TheMatrix()
{
	for (int i=0; i< 5; i++)
		for (int j=0; j<5; j++)
			M[i][j]=0;
}

//------------------------------------------
// This routine asks the user to enter a file name and grab the
// data from there to place it into a matrix
// the matrix filled up with the data is returned
ifstream& operator>> (ifstream& is, TheMatrix& myMatrix) 
{
	string fileName;
	cout << "Enter a file name -> ";
	cin >> fileName;
	is.open(fileName.data());
	for (int i=0; i< 5; i++)
		for (int j=0; j<5; j++)
			is >> myMatrix.M[i][j];
	return is;

}

//------------------------------------------
// Implement this routine to print the matrix to 
// the output stream (in this case screen). 
// Print in a form of 5 rows by 5 columns  

ostream& operator<< (ostream& os, const TheMatrix& myMatrix) 	
{
for(int i=0;i<5;i++)
{
  for(int j=0;j<5;j++)
  {
  os<<myMatrix.M[i][j]<<" ";
  }
  os<<endl;
}
os<<endl;
return os;



}
//------------------------------------------
// This routine adds two matrices and creating a new matrix 
// of the addition of the two matrices M1 and M2
TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2)
{
	TheMatrix Result;
	for (int i=0; i< 5; i++)
		for (int j=0; j<5; j++)
			Result.M[i][j] = M1.M[i][j]+M2.M[i][j];
	return(Result);
}

//------------------------------------------
// Implement the following routine to subtract two Matrices
TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2)
{

TheMatrix Result;
	for (int i=0; i< 5; i++)
		for (int j=0; j<5; j++)
			Result.M[i][j] = M1.M[i][j]-M2.M[i][j];
	return(Result);



}

//------------------------------------------
// Implement the following routine to multiply two matrices
TheMatrix  operator* (const TheMatrix& M1, const TheMatrix& M2)
{
TheMatrix Result;
	for (int i=0; i< 5; i++)
		for (int j=0; j<5; j++)
			Result.M[i][j] = M1.M[i][j]*M2.M[i][j];
	return(Result);



}

//------------------------------------------
// Implement the following routine to divide two matrices
// set the result value to zero if the division by zero occurs
TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2)
{
TheMatrix Result;
	for (int i=0; i< 5; i++)
		for (int j=0; j<5; j++)
		{
            if(M1.M[i][j]==0||M2.M[i][j]==0)
              Result.M[i][j]=0; 
            else 
			  Result.M[i][j] = M1.M[i][j]/M2.M[i][j];
        }
	return(Result);




}

//------------------------------------------

int main()
{
	TheMatrix A, B, AddAB, MulAB, SubAB, DivAB;
	ifstream fin1, fin2;


	fin1 >> A;   
	fin2 >> B; 
	
	AddAB=A+B;
	MulAB=A*B;
	SubAB=A-B;
	DivAB=A/B;
	
	
	cout<<"Matrix A:\n"<<A;
	cout<<"Matrix B:\n"<<B;
	cout<<"Matrix AddAB:\n"<<AddAB;
	cout<<"Matrix SubAB:\n"<<SubAB;
	cout<<"Matrix MulAB:\n"<<MulAB;
	cout<<"Matrix DivAB:\n"<<DivAB;

	
	
	return 0;
}

