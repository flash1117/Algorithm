#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int maze[16][16];
int footprint[16][16];
bool path = false;

void print_maze(int N) {
	printf("\n");
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++)
			printf("%d ", maze[i][j]);

		printf("\n");
	}

}

void init_maze() {

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {
			maze[i][j] = 0;
			footprint[i][j] = 0;
		}

	}

}

void find_maze(int N, int i, int j) { // 동 -> 남 -> 서 -> 북
	footprint[i][j] = 1;

	if (i == N - 1 && j == N - 1)
		path = true;

	printf("footprint = (%d, %d)\n", i+1, j+1);

	if (j + 1 < N && maze[i][j + 1] != 1 && footprint[i][j + 1] == 0)
		find_maze(N, i, j + 1);
	if (i + 1 < N && maze[i + 1][j] != 1 && footprint[i + 1][j] == 0)
		find_maze(N, i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] != 1 && footprint[i][j - 1] == 0)
		find_maze(N, i, j - 1);
	if (i - 1 >= 0 && maze[i - 1][j] != 1 && footprint[i - 1][j] == 0)
		find_maze(N, i - 1, j);

}

int main() {

	int T, N; // test case
	int N_cnt = 0;
	int temp;
	char buffer[SIZE];
	clock_t start, end;

	start = clock();
	FILE *fp = fopen("input2.txt", "r");

	T = atoi(fgets(buffer, SIZE, fp));

	while (!feof(fp)) {
		init_maze();
		path = false;
		fscanf(fp, "%d", &N);

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++)
				fscanf(fp, "%d", &maze[i][j]);

		}

		print_maze(N);
		find_maze(N, 0, 0);
		if (path == true)
			printf("YES!\n");
		else
			printf("NO!\n");
	}

	fclose(fp);
	end = clock();
	printf("소요시간 = %.3f", (double)(end - start) / 1000);
	return 0;
}