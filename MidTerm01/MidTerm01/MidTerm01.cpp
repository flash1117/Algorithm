#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

int graph[SIZE][SIZE];

void print_graph(int N) {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			printf("%d " ,graph[i][j]);
		}
		printf("\n");

	}

}

void init_graph() {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) 
			graph[i][j] = 0;
			
	}

}

void complete(char buffer[], int row) {

	int temp = atoi(buffer);
	int count = 0;
	int r;

	for (int i = 0; i < SIZE; i++) {

		r = temp % 10;
		temp = temp / 10;

		if (count == r && temp == 0)
			break;

		graph[row][r] = 1;
		count++;
	}
}
int main() {

	int T, N, s, t, L;
	int T_case = 0;
	char buffer[1000];
	FILE *fp = fopen("input1.txt", "r");

	if (fp == NULL) {
		printf("file open error!\n");
		return -1;
	}

	fscanf(fp, "%d", &T);

	while (!feof(fp)) {
		init_graph();
		fscanf(fp, "%d", &N);
		printf("N = %d!\n", N);

		for (int i = 0; i <= N; i++) {

			fgets(buffer, 1000, fp);
			printf("%s\n", buffer);
			complete(buffer, i);
		}
		fscanf(fp, "%d %d %d", &s, &t, &L);
		printf("s = %d, t = %d, L = %d\n", s, t, L);
		print_graph(N);
	}

	fclose(fp);

	return 0;
}