#ifndef WINNING_H
#define WINNING_H
#include "POS.h"
//function that checks if there are 4 in a row in a negative slope from the piece that was placed
//calls threeRightD, oneLeftTwoRightD, twoRightOneLeftD, and threeLeftD
//each of those functions checks a seperate possible combination of chains based on the current location of the
//last placed piece
bool checkDownDiag(char board[6][7], POS curr);

//this functions is called by checkDownDiag function. It checks to see if there are three of the same pieces 
// diagonally down from the piece that was last placed. I.e if the last piece was placed at 6,1 it would 
bool threeRightD(char board[6][7], POS curr);


bool oneLeftTwoRightD(char board[6][7], POS curr);


bool twoRightOneLeftD(char board[6][7], POS curr);


bool threeLeftD(char board[6][7], POS curr);


bool checkSide(char board[6][7], POS curr);


bool threeRightS(char board[6][7], POS curr);


bool oneLeftTwoRightS(char board[6][7], POS curr);


bool twoRightOneLeftS(char board[6][7], POS curr);


bool threeLeftS(char board[6][7], POS curr);


bool checkUpDiag(char board[6][7], POS curr);


bool threeRightU(char board[6][7], POS curr);


bool oneLeftTwoRightU(char board[6][7], POS curr);


bool twoRightOneLeftU(char board[6][7], POS curr);


bool threeLeftU(char board[6][7], POS curr);

bool checkDown(char board[6][7], POS curr);
#endif