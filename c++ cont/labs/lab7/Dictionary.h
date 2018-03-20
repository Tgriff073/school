#include <string>
using namespace std;

class Dictionary
{
	private:
		//const int maxWordsInDict;
	//	const int maxWordsPerFile;
		int	totalWordsInDict;
		int	numOfWordsInFile[26];
		
	
	public:
		Dictionary();
		Dictionary(int dictMaxWords, int fileMaxWords);
		bool AddAWord(string word);
		bool DeleteAWord(string word);
		bool SearchForWord(string word);
		bool PrintAFileInDict(string filename);
		bool SpellChecking(string fileName);
		bool InsertWordsIntoDict(string fileName);
		void ProcessTransactionFile();		
};
