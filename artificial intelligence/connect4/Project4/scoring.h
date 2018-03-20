#ifndef SCORING_H
#define SCORING_H
#include "POS.h"



int checkDiagPos(char board[6][7], POS curr);
int checkDiagNeg(char board[6][7], POS curr);
int checkDownChain(char board[6][7], POS curr);
int checkSideChain(char board[6][7], POS curr);
int checkBlockSide(char board[6][7], POS curr, int tot);
int checkBlockDiagPos(char board[6][7], POS curr, int tot);
int checkBlockDiagNeg(char board[6][7], POS curr, int tot);
int checkBlockDown(char board[6][7], POS curr, int tot);
#endif