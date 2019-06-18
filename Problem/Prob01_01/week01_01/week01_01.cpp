#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100000

// 오름차순으로 정렬할 때 사용하는 비교함수
int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {

	int N; // chocolate number in packet
	int M; // student number and always N>=M
	int T; // test case number
	int M_cnt = 0; // M count
	int T_cnt = 0; // test case count
	char buffer[SIZE]; // file read line buffer
	int min = 0, t = 0;
	int package[SIZE] = { 0, };
	int index = 0;

	FILE *fp = fopen("input01.txt", "r");

	if (fp == NULL) {
		printf("err00 : file open error!\n");
		return -1;
	}

	T = atoi(fgets(buffer, 1000, fp));

	if (T > 20)
	{
		printf("err01 : Too many test cases!\n");
		return -1;
	}

	while (T_cnt != T) {

		M_cnt = 0;
		index = 0;
		fscanf(fp, "%d %d", &N, &M);

		while (M_cnt < M) {

			fscanf(fp, "%d", &package[index]);
			index++;
			M_cnt++;
		}

		qsort(package, sizeof(package) / sizeof(int), sizeof(int), compare);
		min = package[M - 1] - package[0];
		for (int i = 1; i < N - M + 1; i++)
			min = (min >(t = package[i + M - 1] - package[i]) ? t : min);
		printf("min = %d\n", min);

		T_cnt++;
	}

	fclose(fp);
	return 0;
}