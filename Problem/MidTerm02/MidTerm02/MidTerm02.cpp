#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define RIGHT 2
#define BOTTOM 3
#define LEFT 4
#define TOP 5

int maze[16][16];
int copy[16][16];
int footprint[16][16];
int count = 0;
bool path = false;
bool dst = false;
int prev = 0;

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

		for (int j = 0; j < 16; j++) 
			maze[i][j] = 0;
	}

}

void init_footprint() {

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) 
			footprint[i][j] = 0;
	}
}

void copy_maze() {

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++)
			copy[i][j] = maze[i][j];
	}
}

void find_maze(int N, int i, int j, int dir) {
	footprint[i][j] = 1;

	if (i == N - 1 && j == N - 1) {
		dst = true;
		printf("%d\n", count);
		return;
	}
		
	if (j + 1 < N && copy[i][j + 1] != 1 && footprint[i][j + 1] == 0) {
		if (prev == BOTTOM) count++;
		prev = RIGHT;
		find_maze(N, i, j + 1, RIGHT);
	}
		
	if (i + 1 < N && copy[i + 1][j] != 1 && footprint[i + 1][j] == 0) {
		if (prev == LEFT) count++;
		prev = BOTTOM;
		find_maze(N, i + 1, j, BOTTOM);
	}

	if (j - 1 >= 0 && copy[i][j - 1] != 1 && footprint[i][j - 1] == 0) {
		if (prev == TOP) count++;
		prev = LEFT;
		find_maze(N, i, j - 1, LEFT);
	}
	
	if (i - 1 >= 0 && copy[i - 1][j] != 1 && footprint[i - 1][j] == 0) {
		if (prev == RIGHT) count++;
		prev = TOP;
		find_maze(N, i - 1, j, TOP);
	}
	
}

void isRightExist(int N, int i, int j, int dir) {
	
	if (i == N - 1 && j == N - 1)
		path = true;

	if (maze[i][j] == dir)
		return;
	else if (maze[i][j] == 1)
		return;

	maze[i][j] = dir;
	footprint[i][j] = dir;

	if (i >= 0 && j >= 0 && i < N && j < N) {

		if (footprint[i][j] == RIGHT) {
			isRightExist(N, i, j + 1, RIGHT);
			isRightExist(N, i + 1, j, BOTTOM);
		}
		else if (footprint[i][j] == BOTTOM) {
			isRightExist(N, i + 1, j, BOTTOM);
			isRightExist(N, i, j - 1, LEFT);
		}

		else if (footprint[i][j] == LEFT) {
			isRightExist(N, i, j - 1, LEFT);
			isRightExist(N, i - 1, j, TOP);
		}
			else if (footprint[i][j] == TOP) {
			isRightExist(N, i - 1, j, TOP);
			isRightExist(N, i, j + 1, RIGHT);
		}

		footprint[i][j] = 0;

	}
}
	
int main() {

	int T, N;
	int N_cnt = 0;
	int temp;
	char buffer[SIZE];
	clock_t start, end;

	start = clock();
	FILE *fp = fopen("input2.txt", "r");

	T = atoi(fgets(buffer, SIZE, fp));

	while (!feof(fp)) {

		init_maze();
		init_footprint();
		path = false;
		dst = false;
		count = 0;
		prev = 0;

		fscanf(fp, "%d", &N);

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++)
				fscanf(fp, "%d", &maze[i][j]);

		}
		copy_maze();
		print_maze(N);
		isRightExist(N, 0, 0, RIGHT);
		if (path == true) 
			printf("0\n");
		else
		{
			init_footprint();
			find_maze(N, 0, 0, RIGHT);
			if (dst == true);
			else
				printf("-1\n");
		}
		
	}

	fclose(fp);
	end = clock();
	printf("소요시간 = %.3f", (double)(end - start) / 1000);
	return 0;
}