#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define SIZE 20

int graph[SIZE][SIZE];
bool isVisit[SIZE];

void init_graph(int row, int count)
{
	isVisit[row] = false;
	graph[row][0] = count;

}

int Find(int s, int t, int L, int current) {
	int result = 0;

	if (isVisit[s] == true) {
		return 0;
	}

	if (current > L)
		return 0;
	else if (s == t && current <= L) {
		return 1;
	}
	else
		isVisit[s] = true;

	for (int i = 1; i <= graph[s][0]; i++) {
		result += Find(graph[s][i], t, L, current + 1);
	
	}

	isVisit[s] = false;
	
	return result;
}

int main() {
	int T, N, s, t, L;
	int count;
	int temp = 0;
	FILE *fp = fopen("input1.txt", "r");
	
	if (fp == NULL) {
		printf("file open error\n");
		return -1;
	}

	fscanf(fp, "%d", &T);

	while (1) {
		if (T-- == 0)
			break;

		fscanf(fp, "%d", &N);
		if (N > 20) {
			printf("N value too big\n");
			return -1;
		}

		for (int i = 0; i<N; i++) {

			fscanf(fp, "%d", &count);
			init_graph(i, count);

			for (int j = 1; j < count + 1; j++) {
				fscanf(fp, "%d", &temp);
				graph[i][j] = temp;
			}
		}
		fscanf(fp, "%d %d %d", &s, &t, &L);
		if(L>20) {
			printf("L value too big\n");
			return -1;
		}
		
		printf("경로의 갯수 : %d\n", Find(s, t, L, 0) );

	}

	return 0;
}

