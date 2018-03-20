#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//prototypes
void processARow(vector<string>&,ifstream&);
void insertV(vector<string>&,string,int);
void deleteV(vector<string>&,int);
void printV(const vector<string>);

int main()
{
  ifstream fin;
  fin.open("data.txt");  
  vector<string> v;
  while(!fin.eof())
  {
                 
  processARow(v,fin);
  
  }
  fin.close();
  system("PAUSE");

return 0;
}

void processARow(vector<string>& v,ifstream& fin)
{
  string action="";
  string word="";
  int index=0;
  fin>>action;
  
  for(int i=0;i<action.size();i++)
  {
    action[i]=toupper(action[i]);
  }

  if(action=="INSERT")
  { 
                      
                      
//  cout<<action<<endl;
    fin>>word;
    fin>>index;
    insertV(v,word,index);
  }
  else if(action=="DELETE")
    {
 //   cout<<endl;                       
    fin>>index;
    deleteV(v,index);
    }
  else if(action=="PRINT")
  {
   // cout<<action<<endl;   
    printV(v);
  } 
  else
    cout<<"Action not valid";
}//end of processARow

void insertV(vector<string>& v,string word, int index)
{
  v.insert(v.begin()+index,word);
}//end of insert

void deleteV(vector<string>& v,int index)
{
  v.erase(v.begin()+index);
}//end of delete

void printV(const vector<string> v)
{
  for(int i=0;i<v.size();i++)
  {
   cout<<v[i]<<endl;
  }
}//end of print
