#include <iostream>
#include <vector>
using namespace std;
void combineVector(vector<int>, vector<int>, vector<int>&);
int main()
{
	vector<int> l1;
	vector<int> l2;
	vector<int> l3;
	cout<<"You will be asked to enter 3 numbers in ascending order. \n";
	int temp=0;

	for(int i=0; i<2;i++)
	{
	
		for(int j=0; j<3;j++)
		{
		
			cout<<"Enter a number: ";
		
			cin>>temp;
			if(i==0)
				l1.push_back(temp);
			else 
				l2.push_back(temp);
			
		}
		cout<<"Storing numbers into vector "<<i+1<<endl<<endl;
	}
	combineVector(l1, l2, l3);
	cout<<"The content of the new vector is: ";
	for(int i=0; i<l3.size();i++)
		cout<<l3[i]<<" ";
	

	return 0;
}

void combineVector(vector<int> a, vector<int> b, vector<int>& r)
{
	int indexA=0;
	int indexB=0;
	int indexR=0;
	
	while(indexA < a.size()&&indexB< b.size())
	{
		if(a[indexA]<b[indexB])
			r.push_back(a[indexA++]);			
		else 
			r.push_back(b[indexB++]);
		indexR++;
	}
		while(indexA<a.size())
			r.push_back(a[indexA++]);
		
		while(indexB<b.size())
			r.push_back(b[indexB++]);
	
}


