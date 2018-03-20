#include "State.h"
#include <iostream>
#include <string>
#include <cmath>
#include "winning.h"
#include "scoring.h"
//notes: working on genSucc make sure new board is same as old board. then work on value  function
using namespace std;

State::State()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = '_';
		}
	}
	total = 0;
	action = "intial state";
	previousState = NULL;
	for (int i = 0; i < 7; i++)
		depths[i] = 5;
}

State::State(int x, State copy)
{
	total = copy.total;
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = copy.board[i][j];
		}
	}
	for (int i = 0; i < 7; i++)
	{
		depths[i] = copy.depths[i];
	}
	previousState = NULL;
	total++;
	board[depths[x]][x] = 'X';
	curr.x = x;
	curr.y = depths[x];
	depths[x]--;
	
}

State::State(char piece, POS loc, State* prev, int tot)
{
	curr = loc;
	placed = piece;
	total = tot;
	curr = loc;
	previousState = prev;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				board[i][j] = previousState->board[i][j];
			}
		}
		for (int i = 0; i < 7; i++)
			depths[i] = previousState->depths[i];
		depths[loc.x]--;
		
	
	board[loc.y][loc.x] = piece;
	
	
	
}

vector<State> State :: genSucc()
{
	vector<State> successors;
	POS temp;
	char piece = ' ';
	if (total % 2)
		piece = 'O';
	else
		piece = 'X';
	for (int i = 0; i < 7; i++)
	{
		if (depths[i] >= 0)
		{
			temp.x = i;
			temp.y = depths[i];
			State move = State(piece, temp, this, this->total + 1);
			move.setReward();
			successors.push_back(move);
		}
	}
	return successors;
	
}
//compares the equivalencies of states, might not be needed considering the algorithm for generating successors should be
//create only unique states.
bool State :: operator==(State& other)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (board[i][j] != other.board[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void State :: setReward()
{
	int tempReward;
	if (checkWin())
	{
		reward = 10000;
		return;
	}
	else
	{
		
	}
}
void State :: operator=(State copy)
{

	total = copy.total;
	curr.x = copy.curr.x;
	curr.y = copy.curr.y;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = copy.board[i][j];
		}
	}
	for (int i = 0; i < 7; i++)
	{
		depths[i] = copy.depths[i];
	}
	previousState = NULL;

}
//checks to see if the slot at the position specified by the parameter is occupied,
//by checking if the piece at that slot is an underscore if it is the function returns true, other wise it returns false
bool State :: isEmpty(POS check)
{
	return board[check.x][check.y] == '_';
}

void State::displayState()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << board[i][j] << " ";
		}
		cout <<  endl;
	}
	cout << curr.x << " " << curr.y << endl;
	
}

void State :: setPrevious(State* prev)
{
	//previousState = prev;
}

bool State::full()
{
	return total == 42;
}

int State::getTotal()
{
	return total;
}

void State::incTotal()
{
	total++;
}

int State :: getDepth(int x)
{
	return depths[x];
}

bool State::checkWin()
{
	
	if (checkDown(board, curr))
		return true;
	else if (checkDownDiag(board, curr))
		return true;
	else if (checkUpDiag(board, curr))
		return true;
	else if (checkSide(board, curr))
		return true;
	else 
		return false;		
	
}