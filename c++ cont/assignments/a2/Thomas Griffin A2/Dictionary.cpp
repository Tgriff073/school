/*
Thomas Griffin
Assignment 2
SEC10-20315
Dictionary.cpp
3/14/15
*/
#ifndef Dictionary_C
#define Dictionary_C
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dictionary.h"
using namespace std;
bool Dictionary::failure = false;
bool Dictionary::success = true;


//------------------------------------------------------------------
					//default constructor
//------------------------------------------------------------------
Dictionary::Dictionary():maxWordsInDict(10000),maxWordsPerFile(100),NumLettersInAlphabet(26)
{

		
		totalWordsInDict = 0;
		
        for (int i=0;i<NumLettersInAlphabet;i++)
        {
        	numOfWordsInFile[i]=0;
        }
		


}//end default constructor
//------------------------------------------------------------------


//------------------------------------------------------------------
					//constructor 2 parameters
//------------------------------------------------------------------
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords),NumLettersInAlphabet(26)
{

		
		totalWordsInDict = 0;	
		for (int i=0;i<NumLettersInAlphabet;i++)
        {
        	numOfWordsInFile[i]=0;
        }


}//end constructor with 2 paramaters	
//------------------------------------------------------------------


//------------------------------------------------------------------
					//Deconstructor
//------------------------------------------------------------------
Dictionary::~Dictionary()
{
	totalWordsInDict = 0;
	for (int i=0;i<NumLettersInAlphabet;i++)
        {
        	numOfWordsInFile[i]=0;
        }
}

//------------------------------------------------------------------
					//SearchForWord
	//Takes a string and checks to see if it exists in respective
	//file. Returns true if word is found and false if not.
//------------------------------------------------------------------
bool Dictionary::SearchForWord(string word)
{
		string fileName = " .txt";
		string test="";
		
	
		for(int i=0;i<word.length();i++)//changes word to lowercase to in order to
			word[i]=tolower(word[i]);// match format in file

		fileName[0] = toupper(word[0]);     
		ifstream fin(fileName.data());

		while(fin>>test)
		{
			
			if(test==word)
			return Dictionary::success;

		}		

	return Dictionary::failure;
}//end SearchForWord
//------------------------------------------------------------------


//------------------------------------------------------------------
					//AddAWord
	//Takes a string and opens the respective file and adds the
	//word to that file as long as it doesn't already exist 
	//and the maxwords in file or in dict have been reached
	//returns false if those conditions fail
	
//------------------------------------------------------------------
bool Dictionary::AddAWord(string word)
{
		string fileName = " .txt";
		if((SearchForWord(word)==Dictionary::failure)&&numOfWordsInFile[toupper(word[0])-65]<maxWordsPerFile&&totalWordsInDict<maxWordsInDict)
		{

			fileName[0] = toupper(word[0]);     
			ofstream fout;
			fout.open(fileName.data(), ios::app);
			for(int i=0;i<word.length();i++)
			word[i]=tolower(word[i]);
			fout << word << endl;
			numOfWordsInFile[toupper(word[0])-65]++;
			totalWordsInDict++;
			return (Dictionary::success);
		}
		else
			return (Dictionary::failure);

}//end of AddAWord
//------------------------------------------------------------------


//------------------------------------------------------------------
					//DeleteAWord
	//Grabs words frome a file one at a time and compares them to 
	// the word passed to the function. If the word being read in 
	//matches the word being passed in it wont be added back in to
	//the file. Returns false if word wasn't found in dictionary
	
//------------------------------------------------------------------
bool Dictionary::DeleteAWord(string word)
{
		string fileName = " .txt";
		string test="";
		vector<string> V(0) ;
		if(SearchForWord(word))
		{
			fileName[0] = toupper(word[0]);     
			ifstream fin(fileName.data());
    		while(fin>>test)
			{
				if(test!=word)
					V.push_back(test);
			}
				fin.close();
				fin.clear();
				ofstream fout(fileName.data());
				for(int i=0;i<V.size();i++)
					fout<<V[i]<<endl;
				numOfWordsInFile[toupper(word[0])-65]--;
				totalWordsInDict--;
				return Dictionary::success;
		}	
		else 
			return Dictionary::failure;
}//end DeleteAWord
//------------------------------------------------------------------


//------------------------------------------------------------------
					//PrintAFileInDict
	//Opens file with the name that was passed to it. Prints all of 
	//the words in that file 5 words per line.
//------------------------------------------------------------------
bool Dictionary::PrintAFileInDict(string filename)
{
		
		
		int count=0;
		ifstream fin(filename.data());
		string tmp;
		if(fin.fail())
			return (Dictionary::failure);
		while(fin>>tmp)
		{
			if(count<5)
			{
				cout<<tmp<<" ";
				count++;
			}
			else
			{
				count=0; 
				cout<<endl;
			}
		}//end while
		if(count>0)
			cout<<endl;
		
		return (Dictionary::success);
}
//------------------------------------------------------------------


//------------------------------------------------------------------
					//SpellChecking
	//Opens a file and checks if each word matches a word in the
	//dictionary. If a word in the file couldn't be found in the 
	//dictionary it will be displayed on the screen. Returns false
	//if file couldn't be opened.
//------------------------------------------------------------------
bool Dictionary::SpellChecking(string fileName)
{
		string test;
		string test2;
		ifstream dict;
		bool status=true;
		string dictF=" .txt";
		ifstream fin(fileName.data());
		if(!fin)
			return (Dictionary::failure);
		while(fin)
		{
			fin>>test;
			dictF[0]=(toupper(test[0]));
			dict.open(dictF.data());
			while(dict)
			{
				dict>>test2;
				if(test2!=test)
  				cout<<test2<<" not found in dictionary"<<endl;
  				
			}//end inner
		}//end outter
		
		return(Dictionary::success);
}
//------------------------------------------------------------------


//------------------------------------------------------------------
					//InsertWordsIntoDict
	//Opens a file and adds each word to it's respective file.
//------------------------------------------------------------------
bool Dictionary::InsertWordsIntoDict(string fileName)
{
		ifstream fin(fileName.data());
		if(fin.fail())
			return (Dictionary::failure);
		string word="";
		while(fin)
		{
			fin>>word;
			this->AddAWord(word);
		}
		return (Dictionary::success);

}
//------------------------------------------------------------------


//------------------------------------------------------------------
					//ProcessTransactionFile
	//Opens a transaction file specified by the user. Reads in command
	//and does an action that corresponds with the command. i.e if
	//the command was AddW it would take in a word and call the 
	//AddAWord function and adds that word to it's respective file.
//------------------------------------------------------------------
bool Dictionary::ProcessTransactionFile()
{
		string transFile;
		cout<<"Please enter the name of your transaction file"<<endl;
		cin>>transFile;
		ifstream fin(transFile.data());
		
		string word="";
		string cmd;
		if(fin.fail())
		{
			cout<<"failed to open transaction file"<<endl;
			
		}
  		while(fin>>cmd)
  		{
  			if(cmd=="AddW")
  			{
  				fin>>word;
				cout<<"------------Adding word:------------"<<endl;
				cout<<word<<endl;
  				if(!this->AddAWord(word))
  					cout<<"Failure! Couldn't add "<<word<<" since it already exists"<<endl;
				else
					cout<<"Success! "<<word<<" was added to the dictionary"<<endl;
				cout<<"-----------------------------------\n\n";
  			}//end Addw check
  			else if(cmd=="InsertF")
  			{
  				fin>>word;
				cout<<"-----------Inserting file:----------"<<endl;
				cout<<word<<endl;
  				if(!this->InsertWordsIntoDict(word))
					cout<<"Failure! Couldn't insert the file "<<word<<" to the dictionary."<<endl;
				else
					cout<<"Success! "<<word<<" was successfully inserted to the dictionary"<<endl;
				cout<<"-----------------------------------\n\n";
  			}//end InsertF check
  			else if(cmd=="PrintF")
  			{
  				fin>>word;
				cout<<"-----------Printing file:-----------"<<endl;
				cout<<word<<endl;
  				if(this->PrintAFileInDict(word)==(Dictionary::failure))
  			 		cout<<word<<" Failure! File couldn't be opened"<<endl;
 				 cout<<"-----------------------------------\n\n";
  			}//end PrintF Check
  			else if(cmd=="DeleteW")
  			{
  				fin>>word;
				cout<<"-----------Deleting word:----------"<<endl;
				cout<<word<<endl;
  				if(!this->DeleteAWord(word))
  					cout<<"Failure! Couldn't delete "<<word<<endl;
				else
					cout<<"Success! "<<word<<" was deleted"<<endl;
				cout<<"-----------------------------------\n\n";
  			}//end DeleteW check
  			else if(cmd=="SearchW")
  			{
  				fin>>word;
  				cout<<"-----------Searching for:---------"<<endl;
  				cout<<word<<" "<<endl;
  				if(!this->SearchForWord(word))
  					cout<<"Failure! couldn't find "<<word<<" in dictionary"<<endl;
  				else
  					cout<<"Success! "<<word<<" was found in the dictionary"<<endl;
  				cout<<"-----------------------------------\n\n";
  			}//end SearchW check
  			else if(cmd=="SpellCheck")
  			{
  				fin>>word;
				cout<<"-----------Spell Checking----------"<<endl;
				cout<<word<<endl;
  				if(this->SpellChecking(word)==Dictionary::failure)
  					cout<<"Failure! "<<word<<" Could not be opened for spell checking."<<endl;
				cout<<"-----------------------------------\n\n";
  			}//end SpellCheck check
   			else
   				cout<<cmd<<" is not a valid command."<<endl;
  		}//end while		
  
}//end ProcessTransactionFile 
//------------------------------------------------------------------
#endif
