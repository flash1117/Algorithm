#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

int graph[SIZE][SIZE];

int main() {

	int T, N, s, t, L;
	int T_case = 0;
	char buffer[1000];
	FILE *fp = fopen("input1.txt", "r");

	fscanf(fp, "%d", &T);

	while (!feof(fp)) {

		fscanf(fp, "%d", &N);

		for (int i = 0; i < SIZE; i++) {

			for (int j = 0; j < SIZE; j++) {


			}
		}

	}



	fclose(fp);

	return 0;
}