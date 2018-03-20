#ifndef STATE_H
#define STATE_H
#include <vector>
using namespace std;
struct POS
{
	int x;
	int y;
};

class State
{
	public:
		State(char, POS, State*, int);//implemented, creates a new state, mirrors the previous state but adds a new piece at specified POS
		State();//implemented, initializes board to all '_'
		
		bool isEmpty(POS);
		vector<State> genSucc();
		bool operator==(State& other);//implemented, checks equality between two objects
		void displayState();//displays the board and the action state 
		int getTotal();
		void setPrevious(State*);
		void setReward();
		bool full();
		void incTotal();
		int getDepth(int);
		void operator=(State);
		State(int, State);
		bool checkWin();
		
	private:
		char board[6][7];
		POS curr;
		State *previousState;
		int total;
		char placed;
		string action;
		int depths[7];
		int reward;
};
#endif //STATE_H