#include "State.h"
#include <queue>
#include <stdlib.h> 
#include <iostream>
#include <time.h>

using namespace std;
void displaySucc(vector<State> );
State getPlayermove(State);

int main()
{
	srand(time(NULL));
 
	State currentBoard = State(); // initial state of the board, all pieces are '_' and total = 0
	
	//init.displayState();
	//queue<State> frontier;
	//frontier.push(init);
	while (true)
	{
	if (currentBoard.full())
	{
		cout << "Tie game!" << endl;
		break;
	}
	currentBoard = getPlayermove(currentBoard);
	if (currentBoard.checkWin())
	{
		system("CLS");
		currentBoard.displayState();
		cout << "You win!" << endl;
		break;
	}
	vector<State> successors;
	successors = currentBoard.genSucc();
	//displaySucc(successors);
	currentBoard = successors[(rand() % successors.size())];
	currentBoard.checkWin();
	system("CLS");
	currentBoard.displayState();
	if (currentBoard.checkWin())
	{
		cout << "You lose!" << endl;
		break;
	}
	}
	/*
	while (true)
	{
		if (frontier.empty())
			break;
		State  currState = frontier.front();
		vector<State> successors;
		frontier.pop();
		if (currState.getTotal() < 4)
			successors = currState.genSucc();
		for (int i = 0; i < successors.size(); i++)
		{
			frontier.push(successors[i]);
			//cout << successors[i].getTotal() <<endl;
		}
		displaySucc(successors);
		
		if (successors.empty())
			break;
	}
	*/

	system("PAUSE");
	return 0;
}

void displaySucc(vector<State> successors)
{
	for (int i = 0; i < successors.size(); i++)
	{
		successors[i].displayState();
	}
}

State getPlayermove(State currentBoard)
{
	int col = 0;
	bool full = false;
	cout << "Current board: \n";
	system("CLS");
	currentBoard.displayState();
	while (true)
	{
		full = false;
		cout << "Which column would you like to place your piece in?\n";
		cin >> col;
		if (col > 7 || col < 0)
			cout << "Invalid location\n";
		else if (currentBoard.getDepth(col -1) <- 0 )
			cout << "Column is full\n";
		else
			break;
	}
	State move = State(col -1, currentBoard);
	return move;
}