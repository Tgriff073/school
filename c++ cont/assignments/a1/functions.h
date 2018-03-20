/*
Thomas Griffin
A1
SEC10-20315
Functions.h
*/
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
char welcome();
void encryptRot();
void encryptCrypto();
void decryptRot();
void decryptCrypto();
vector<string> fileIO();
string getKey();
void writeOut(const vector<string>);

//*****************************************************
              //Miscellaneous methods
//*****************************************************
char welcome()
{
  
  char choice;
  do{
  cout<<"Would you like to (e)ncrypt or (d)ecrypt a file?,or (Q)uit:"<<endl;
  cin>>choice;
  choice=toupper(choice);
  if(choice=='E')
  {
    cout<<"What type of encryption would you like to perform, (R)otation or (C)ryptogram:"<<endl;
    cin>>choice;
    choice=toupper(choice);
    if(choice=='R')
    {
    encryptRot();
    }
    else if(choice='C')
    {
    encryptCrypto();
    }
}//end encryption check
  else if(choice=='D')
  {
  cout<<"What type of decryption would you like to perform, (R)otation or (C)ryptogram:"<<endl;
    cin>>choice;
    choice=toupper(choice);
    if(choice=='R')
    {
      decryptRot();   
    }
    else if(choice='C')
    {
         decryptCrypto(); 
    }
}//end decryption check
}while(choice!='Q');//end menu while
}//end welcome

//opens file and reads in returns file contents as string vector
vector<string> fileIO()
{
  ifstream fin;
  string file;
  string temp;
  cout<<"What file would you like to use: "<<endl;
  cin>>file;
  vector<string> V;
  fin.open(file.c_str());
  
  while(fin)
  {
    fin>>temp;
    V.push_back(temp);
  }//end while
  V.pop_back();//above method resulted in last string being present twice at the end of vector so a pop_back to remove last element
  fin.close();
  return V;
}//end fileIO


//opens file grabs first line as a string and returns it as a key for crypto method
string getKey()
{
  ifstream fin;
  string file;
  cout<<"Now what file would you like to use as a key for your cryptogram:"<<endl;
  cin>>file;
  fin.open(file.c_str());
  string key;
  getline(fin, key);
  fin.close();
  return key;
}//end getKey

//writes vector that was passed to it out to file designated by user
void writeOut(const vector<string> V)
{
  ofstream fout;
  string file;
  cout<<"What file would you like to write the new message out to?:"<<endl;
  cin>>file;
  fout.open(file.c_str());
  for(int i=0; i<V.size();i++) 
  {
  fout<<V[i]<<" ";
  }
  fout.close();
}//end write out
//*****************************************************


//*****************************************************
              //rot methods
//*****************************************************
void encryptRot()
{
  vector<string> V=fileIO();
  int key;
  cout<<"How much would you like to rotate by? (Enter an integer value between 1&25)"<<endl;
  cin>>key;
   for(int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[i].length();j++)
    {   
        if(V[i][j]>=97&&V[i][j]<=122)    
          V[i][j]=(((V[i][j])-97+key)%26)+97;
        else if(V[i][j]>=65&&V[i][j]<=90)
          V[i][j]=(((V[i][j])-65+key)%26)+65;
    }//end inner
    
  }//end outter
  writeOut(V);
}

void decryptRot()
{
vector<string> V=fileIO();
  int key;
  cout<<"How much would you like to rotate by? (Enter an integer value between 1&25)"<<endl;
  cin>>key;
   for(int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[i].length();j++)
    {   
        if(V[i][j]>=97&&V[i][j]<=122)//checks if uppercase
        {    
          V[i][j]-=key;//substracts key to rotate alphabet back 
          if(V[i][j]<97)//if the new value after the key is subtracted is below the value of 'a' then add 26 in order to stay within the range of the alphabet values
            V[i][j]+=26;
        }
        else if(V[i][j]>=65&&V[i][j]<=90)//checks if lowercase
        {  
          V[i][j]-=key;
          if(V[i][j]<65)
            V[i][j]+=26;//if the new value after the key is subtracted is below the value of 'a' then add 26 in order to stay within the range of the alphabet values
        }
    }//end inner
    
  }//end outter
  writeOut(V);
}//end decryptRot
//*****************************************************


//*****************************************************
              //Cryptogram methods
//*****************************************************


//encrypts a vector using cryptogram method
void encryptCrypto()
{
  vector<string> V=fileIO();
  string cKey=getKey();
  for (int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[i].length();j++)
    {
      if(V[i][j]>=97&&V[i][j]<=122)    
      {
        V[i][j]=V[i][j]-97;
        V[i][j]=cKey[V[i][j]];
      
      }
      else if(V[i][j]>=65&&V[i][j]<=90)
      {
        V[i][j]=V[i][j]-65;
        V[i][j]=cKey[V[i][j]];
        V[i][j]=toupper(V[i][j]);
      }//end if
    }//end inner
  }//end outer
  writeOut(V);
}//end encryptCrypto

//decrypts a vector using cryptogram method
void decryptCrypto()
{
   vector<string> V=fileIO();
   string cKey=getKey();
    for(int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[i].length();j++)
    {   
       if(V[i][j]>=97&&V[i][j]<=122&&V[i][j])    
       {
         V[i][j]=(cKey.find(V[i][j])+97);
       }
       else if(V[i][j]>=65&&V[i][j]<=90)
       {
         V[i][j]=tolower(V[i][j]);
         V[i][j]=(cKey.find(V[i][j])+65);
       }
    }//end inner
  }//end outter
  writeOut(V);
}//end decryptCrypto

//*****************************************************



