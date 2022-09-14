#include <stdio.h>
#include <stdlib.h>

#define size 75
#define height 70

void rule(int state[]) {
	int state1[size] = {};
	for (int ix = 0; ix < size; ix++) {
		if (state[ix-1] == 0 && state[ix] == 0 && state[ix+1] == 0)      state1[ix] = 0;
		else if (state[ix-1] == 0 && state[ix] == 0 && state[ix+1] == 1) state1[ix] = 1;
		else if (state[ix-1] == 0 && state[ix] == 1 && state[ix+1] == 0) state1[ix] = 1;
		else if (state[ix-1] == 0 && state[ix] == 1 && state[ix+1] == 1) state1[ix] = 1;
		else if (state[ix-1] == 1 && state[ix] == 0 && state[ix+1] == 0) state1[ix] = 0;
		else if (state[ix-1] == 1 && state[ix] == 0 && state[ix+1] == 1) state1[ix] = 1;
		else if (state[ix-1] == 1 && state[ix] == 1 && state[ix+1] == 0) state1[ix] = 1;
		else if (state[ix-1] == 0 && state[ix] == 1 && state[ix+1] == 1) state1[ix] = 0;
	}
	for (int i = 0; i < size; i++) {
		state[i] = state1[i];
	}
}

int main(int argc, char **argv) {
	int state[size] = {};
	state[size -1] = 1;
	int i = 0;
	while (i++ < height) {
		rule(state);
		for (int j = 0; j < size; j++) {
			printf(" %c ", (state[j] == 1) ? '<' : ' ' );
		}
		printf("\n");
	}
}
