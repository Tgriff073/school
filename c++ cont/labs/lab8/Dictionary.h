/*
Thomas Griffin
Assignment 2
SEC10-20315
Dictionary.h
3/14/15
*/
#ifndef Dictionary_H
#define Dictionary_h
#include <string>
using namespace std;

class Dictionary
{
  
	private:
		const int maxWordsInDict;
		const int maxWordsPerFile;
		const int NumLettersInAlphabet;
		int	totalWordsInDict;
		int	numOfWordsInFile[26];
		static bool failure;
		static bool success;
		
	
	public:
		Dictionary();
		Dictionary(int dictMaxWords, int fileMaxWords);
		~Dictionary();
		bool SearchForWord(string word);
		bool AddAWord(string word);
		bool DeleteAWord(string word);
		bool PrintAFileInDict(string filename);
		bool SpellChecking(string fileName);
		bool InsertWordsIntoDict(string fileName);
		bool ProcessTransactionFile();		
};
#endif
