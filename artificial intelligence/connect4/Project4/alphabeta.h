#ifndef ALPHABETA_H 
#define ALPHABETA_H
int abMiniMax(int depth, int nodeIndex, bool isMaxPlayer, int values[], int alpha, int beta) {

	// Terminal condition
	if (depth == 3)
		return values[nodeIndex];

	if (isMaxPlayer) { // Max Player
		int best = MIN;

		for (int i = 0; i < 2; i++) {
			int val = abMiniMax(depth++, nodeIndex * 2 + i, false, values, alpha, beta);
			best = max(best, val);
			alpha = max(alpha, best);

			// AB Pruning occurs here
			if (beta <= alpha)
				break;
		}

		return best;
	}

	else { // Min Player
		int best = MAX;

		for (int i = 0; i < 2; i++) {
			int val = abMiniMax(depth++, nodeIndex * 2 + i, true, values, alpha, beta);
			best = min(best, val);
			beta = min(beta, best);

			// AB Pruning here
			if (beta <= alpha)
				break;
		}
		return best;
	}
}
#endif // !ALPHABETA_H 