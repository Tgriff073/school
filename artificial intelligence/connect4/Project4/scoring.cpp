#include "scoring.h"
#include <vector>
using namespace std;

int scoreChart[6][7] = { 1, 2, 3, 4, 3, 2, 1,
						 2, 3, 4, 5, 4, 3, 2,
						 3, 4, 5, 6, 5, 4, 3,
						 3, 4, 5, 6, 5, 4, 3,
					 	 2, 3, 4, 5, 4, 3, 2,
					  	 1, 2, 3, 4, 3, 2, 1 };

int checkDiagPos(char board[6][7], POS curr)
{
	vector<POS> locs;//store the location of all the pieces in the chain
	char piece = board[curr.y][curr.x];
	int chain = 0;
	int score = 0;
	int farthest = curr.x;
	int sum = 0;
	int x = curr.x;
	int y = curr.y;
	while (board[y][x] == piece)
	{
		if (board[y+1][x-1] != piece)
			break;
		farthest = x;
		y++;
		x--;
	}
	while (chain < 3)
	{
		if (board[y][x] != piece)
			break;
		sum += scoreChart[y][x];
		POS temp;
		temp.x = x++;
		temp.y = y--;
		locs.push_back(temp);
		chain++;
	}
	score = (int)pow(10, chain) * sum;
	if (chain == 1)
		return 0;
	if (board[curr.y][curr.x] == 'O')
		score *= -1;
	if (board[(locs.front().y) + 1][(locs.front().x) - 1] != ' ' && board[(locs.back().y) - 1][(locs.back().x) + 1] != ' ')//valueless chain
		return 0;
	return score;
}

int checkDiagNeg(char board[6][7], POS curr)
{
	vector<POS> locs;//store the location of all the pieces in the chain
	char piece = board[curr.y][curr.x];
	int chain = 0;
	int score = 0;
	int farthest = curr.x;
	int sum = 0;
	int x = curr.x;
	int y = curr.y;
	while (board[y][x] == piece)
	{
		if (board[y-1][x-1] != piece)
			break;
		farthest = x;
		y--;
		x--;
	}
	while (chain < 3)
	{
		if (board[y][x] != piece)
			break;
		sum += scoreChart[y][x];
		POS temp;
		temp.x = x++;
		temp.y = y++;
		locs.push_back(temp);
		chain++;
	}

	POS front = locs.front();
	POS back = locs.back();

	score = (int)pow(10, chain) * sum;
	if (chain == 1)
		return 0;
	if (board[curr.y][curr.x] == 'O')
		score *= -1;
	if (board[front.y - 1][front.x - 1] != ' ' && board[back.y + 1][back.x + 1] != ' ')//valueless chain
		return 0;
	return score;
}

int checkDownChain(char board[6][7], POS curr)
{
	vector<POS> locs;//store the location of all the pieces in the chain
	char piece = board[curr.y][curr.x];
	int chain = 0;
	int sum = 0;
	int score;
	for (int i = curr.y; i < 6; i++)
	{
		if (board[curr.y][curr.x] != piece)
			break;
		chain++;
		POS temp;
		temp.y = i;
		temp.x = curr.x;
		locs.push_back(temp);
		sum += scoreChart[temp.y][temp.x];
	}
	score = (int)pow(10, chain) * sum;
	if (board[curr.y][curr.x] == 'O')
		score *= -1;
	if (chain == 1)
		return 0;
	return score;
}

int checkSideChain(char board[6][7], POS curr)
{
	vector<POS> locs;//store the location of all the pieces in the chain
	int score = 0;
	int chain = 0;
	int sum = 0;
	char piece = board[curr.y][curr.x];
	int farthest = curr.x;
	for (int i = curr.x; i >= 0; i--)
	{
		if (board[curr.y][i-1] != piece)
			break;
		farthest = i;
	}
	for (int i = farthest; i < 7; i++)
	{
		if (board[curr.y][i] != piece)
			break;
		chain++;
		POS temp;
		temp.x = i;
		temp.y = curr.y;
		locs.push_back(temp);
		sum += scoreChart[temp.y][temp.x];
	}
	score = (int)pow(10, chain) * sum;
	if (chain == 1)
	{
		if (board[curr.y][curr.x] == 'O')
			return scoreChart[curr.y][curr.x] * -1;
		return scoreChart[curr.y][curr.x];
	}
	if (board[curr.y][curr.x] == 'O')
		score *= -1;
	if (board[locs.front().y][locs.front().x - 1] != ' ' && board[locs.back().y][locs.back().x + 1] != ' ')//valueless chain since theres no room for expansion
		return 0;
	
	return score;
}

int checkBlockSide(char board[6][7], POS curr, int tot)
{
	int score = 0;
	char piece;
	if (board[curr.y][curr.x] == 'X')
		piece = 'O';
	else
		piece = 'X';
	if (board[curr.y][curr.x + 1] == piece && board[curr.y][curr.x + 2] == piece && board[curr.y][curr.x + 3] == piece)
	{
		score = 1000 * (scoreChart[curr.y][curr.x + 1] + scoreChart[curr.y][curr.x + 2] + scoreChart[curr.y][curr.x + 3]);
	}
	else if (board[curr.y][curr.x - 1] == piece && board[curr.y][curr.x + 1] == piece && board[curr.y][curr.x + 2] == piece)
	{
		score = 1000 * (scoreChart[curr.y][curr.x - 1] + scoreChart[curr.y][curr.x + 1] + scoreChart[curr.y][curr.x + 2]);
	}
	else if (board[curr.y][curr.x - 2] == piece && board[curr.y][curr.x - 1] == piece && board[curr.y][curr.x + 1] == piece)
	{
		score = 1000 * (scoreChart[curr.y][curr.x - 2] + scoreChart[curr.y][curr.x - 1] + scoreChart[curr.y][curr.x + 1]);
	}
	else if (board[curr.y][curr.x - 1] == piece && board[curr.y][curr.x - 2] == piece && board[curr.y][curr.x - 3] == piece)
	{
		score = 1000 * (scoreChart[curr.y][curr.x - 1] + scoreChart[curr.y][curr.x - 2] + scoreChart[curr.y][curr.x - 3]);
	}
	if (tot % 2)
		score *= -1;
	return score;
}

int checkBlockDiagPos(char board[6][7], POS curr, int tot)
{
	int score = 0;
	char piece;
	if (board[curr.y][curr.x] == 'X')
		piece = 'O';
	else
		piece = 'X';
	if (board[curr.y - 1][curr.x + 1] == piece && board[curr.y - 2][curr.x + 2] && board[curr.y - 3][curr.x + 3])
		score = 1000 * (scoreChart[curr.y - 1][curr.x + 1] && scoreChart[curr.y - 2][curr.x + 2] && scoreChart[curr.y - 3][curr.x + 3]);
	else if(board[curr.y + 1][curr.x - 1] == piece && board[curr.y - 1][curr.x + 1] && board[curr.y - 2][curr.x + 2])
		score = 1000 * (scoreChart[curr.y + 1][curr.x - 1] && scoreChart[curr.y - 1][curr.x + 1] && scoreChart[curr.y - 2][curr.x + 2]);
	else if(board[curr.y + 2][curr.x - 2] == piece && board[curr.y + 1][curr.x - 1] && board[curr.y - 1][curr.x + 1])
		score = 1000 * (scoreChart[curr.y + 2][curr.x - 2] && scoreChart[curr.y + 1][curr.x - 1] && scoreChart[curr.y - 1][curr.x + 1]);
	else if(board[curr.y + 1][curr.x - 1] == piece && board[curr.y + 2][curr.x - 2] && board[curr.y + 3][curr.x - 3])
		score = 1000 * (scoreChart[curr.y + 1][curr.x - 1] && scoreChart[curr.y + 2][curr.x - 2] && scoreChart[curr.y + 3][curr.x - 3]);
	if (tot % 2)
		score *= -1;
	return score;
}

int checkBlockDiagNeg(char board[6][7], POS curr, int tot)
{
	int score = 0;
	char piece;
	if (board[curr.y][curr.x] == 'X')
		piece = 'O';
	else
		piece = 'X';
	if (board[curr.y + 1][curr.x + 1] == piece && board[curr.y + 2][curr.x + 2] == piece && board[curr.y + 3][curr.x + 3] == piece)
		score = 1000 * (scoreChart[curr.y + 1][curr.x + 1] + scoreChart[curr.y + 2][curr.x + 2] + scoreChart[curr.y + 3][curr.x + 3]);
	else if(board[curr.y - 1][curr.x - 1] == piece && board[curr.y + 1][curr.x + 1] == piece && board[curr.y + 2][curr.x + 2] == piece)
		score = 1000 * (scoreChart[curr.y - 1][curr.x - 1] + scoreChart[curr.y + 1][curr.x + 1] + scoreChart[curr.y + 2][curr.x + 2]);
	else if(board[curr.y - 2][curr.x - 2] == piece && board[curr.y - 1][curr.x - 1] == piece && board[curr.y + 1][curr.x + 1] == piece)
		score = 1000 * (scoreChart[curr.y - 2][curr.x - 2] + scoreChart[curr.y - 1][curr.x - 1] + scoreChart[curr.y + 1][curr.x + 1]);
	else if(board[curr.y - 1][curr.x - 1] == piece && board[curr.y - 2][curr.x - 2] == piece && board[curr.y - 3][curr.x - 3] == piece)
		score = 1000 * (scoreChart[curr.y - 1][curr.x - 1] + scoreChart[curr.y - 2][curr.x - 2] + scoreChart[curr.y - 3][curr.x - 3]);
	if (tot % 2)
		score *= -1;
	return score;
}

int checkBlockDown(char board[6][7], POS curr, int tot)
{
	int score = 0;
	char piece;
	if (board[curr.y][curr.x] == 'X')
		piece = 'O';
	else
		piece = 'X';
	if(board[curr.y - 1][curr.x] == piece && board[curr.y - 2][curr.x] == piece && board[curr.y - 3][curr.x] == piece)
	{
		score = 1000 * (scoreChart[curr.y - 1][curr.x] + scoreChart[curr.y - 2][curr.x] + scoreChart[curr.y - 3][curr.x]);
	}
	if (tot % 2)
		score *= -1;
	return score;
	
}