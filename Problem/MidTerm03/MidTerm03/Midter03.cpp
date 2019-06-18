#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 20

int cost[SIZE][SIZE], saving[SIZE][SIZE];
int n[SIZE];
int total = 0;
bool tri = false;

int compare(int src, int dst) {
	int temp = 0;
	temp = src < dst ? dst : src;
	return temp;
}

void calculate(int index, int money, int reduce, int M, int C) {
	
	if (index > M || money >= C)
		return;

	if (tri == false) {
		tri = true;
		calculate(index += 1, money, reduce, M, C);
	}
		
	else {
		total = compare(reduce, total);
		for (int i = 0; i < n[index]; i++) {
			tri = false;
			calculate(index + 1, money + cost[index][i], reduce + saving[index][i], M, C);
		}
	}
}

int main() {
	
	clock_t start, end;
	int T, C, M;

	start = clock();
	FILE *fp = fopen("input3.txt", "r");

	if (fp == NULL)
		return -1;

	fscanf(fp, "%d", &T);

	while (!feof(fp)) {

		fscanf(fp, "%d", &M);
		
		for (int i = 0; i < M; i++) {
			fscanf(fp, "%d", &n[i]);
			
			for (int j = 0; j < n[i]; j++)
				fscanf(fp, "%d %d", &cost[i][j], &saving[i][j]);
			
		}
		fscanf(fp, "%d", &C);
		calculate(0, 0, 0, M, C);
		printf("최대 절감량 : %d\n", total);
	}

	end = clock();

	fclose(fp);
	printf("소요시간 %.3f", (double)(end - start) / 1000);
	return 0;
}

