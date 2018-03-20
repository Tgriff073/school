#include "winning.h"
bool checkDownDiag(char board[6][7], POS curr) 
{
	if (threeRightD(board, curr))
		return true;
	else if (oneLeftTwoRightD(board, curr))
		return true;
	else if (twoRightOneLeftD(board, curr))
		return true;
	else if (threeLeftD(board, curr))
		return true;
	else
		return false;
}

bool checkUpDiag(char board[6][7], POS curr)
{
	if (threeRightU(board, curr))
		return true;
	else if (oneLeftTwoRightU(board, curr))
		return true;
	else if (twoRightOneLeftU(board, curr))
		return true;
	else if (threeLeftU(board, curr))
		return true;
	else
		return false;
}

bool checkSide(char board[6][7], POS curr)
{
	if (threeRightS(board, curr))
		return true;
	else if (oneLeftTwoRightS(board, curr))
		return true;
	else if (twoRightOneLeftS(board, curr))
		return true;
	else if (threeLeftS(board, curr))
		return true;
	else
		return false;
}

bool threeRightD(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y + 1][curr.x + 1] && piece == board[curr.y + 2][curr.x + 2] && piece == board[curr.y + 3][curr.x + 3]);
}

bool oneLeftTwoRightD(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y - 1][curr.x - 1] && piece == board[curr.y + 1][curr.x + 1] && piece == board[curr.y + 2][curr.x + 2]);
}

bool twoRightOneLeftD(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y - 2][curr.x -2] && piece == board[curr.y - 1][curr.x - 1] && piece == board[curr.y + 1][curr.x + 1]);
}

bool threeLeftD(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y - 3][curr.x - 3] && piece == board[curr.y - 2][curr.x - 2] && piece == board[curr.y - 1][curr.x - 1] );
}

bool threeRightU(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y - 1][curr.x + 1] && piece == board[curr.y - 2][curr.x + 2] && piece == board[curr.y - 3][curr.x + 3]);
}

bool oneLeftTwoRightU(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y + 1][curr.x - 1] && piece == board[curr.y - 1][curr.x + 1] && piece == board[curr.y - 2][curr.x + 2]);
}

bool twoRightOneLeftU(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y + 2][curr.x - 2] && piece == board[curr.y + 1][curr.x - 1] && piece == board[curr.y - 1][curr.x + 1]);
}

bool threeLeftU(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y + 3][curr.x - 3] && piece == board[curr.y + 2][curr.x - 2] && piece == board[curr.y + 1][curr.x - 1]);
}

bool threeRightS(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y][curr.x + 1] && piece == board[curr.y][curr.x + 2] && piece == board[curr.y][curr.x + 3]);
}


bool oneLeftTwoRightS(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y][curr.x - 1] && piece == board[curr.y][curr.x + 1] && piece == board[curr.y][curr.x + 2]);
}


bool twoRightOneLeftS(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y][curr.x - 1] && piece == board[curr.y][curr.x - 2] && piece == board[curr.y][curr.x + 1]);
}


bool threeLeftS(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];
	return (piece == board[curr.y][curr.x - 1] && piece == board[curr.y][curr.x - 2] && piece == board[curr.y][curr.x - 3]);
}

bool checkDown(char board[6][7], POS curr)
{
	char piece = board[curr.y][curr.x];

	return (board[curr.y + 1][curr.x] == piece && board[curr.y + 2][curr.x] == piece && board[curr.y + 3][curr.x] == piece);
		
}