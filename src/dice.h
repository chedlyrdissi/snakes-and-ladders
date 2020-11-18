#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int UPPER = 6;
static int LOWER = 1;

int throw() {
	printf("Throwing the dice \n");

	// offering different seed to get different random value
	srand(time(NULL));

	int dice = (rand() % (UPPER - LOWER + 1)) + LOWER;

	return dice;
}