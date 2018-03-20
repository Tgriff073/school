#include "random.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int i;
	/* generate 10 random number in (0, 1) with a seed = -2 */
	long seed = -2;
	for (i = 0; i < 10; i++) {
		printf("random number %d = %f\n", i, ran1(&seed));
	}

	/* generate 10 random integers between [min, max] */
	for (i = 0; i < 10; i++) {
		printf("random integer %d in [10, 50] = %d\n", i, ranInt(10, 50));
	}

	/* generate 10 random CPU bursts from Poisson distribution with average length of 13 */
	for (i = 0; i < 10; i++) {
		printf("CPU Burst %d from Poisson distribution = %d \n", i, CPUBurstRandom(13));
	}

	return 0;
}

