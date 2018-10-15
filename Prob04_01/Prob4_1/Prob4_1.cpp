#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *Input(int *TC, int N) {

	for (int i = 0; i < N; i++)
		TC[i] = i+1;

	return TC;
}

int COMB(int N, int K, int *input, int *select)
{
	if (N == K) {
		int i;
		for (i = 0; i<N; i++) {
			select[i] = 1;
		}
		for (i = 0; i<N; i++) {
			if (select[i] == 1) printf("%d ", input[i]);
		}
		for (i = 0; i<N; i++) {
			select[i] = 0;
		}
		printf("\n");
		return 0;
	}
	if (K == 1) {
		int i, j;
		for (i = 0; i<N; i++) {
			select[i] = 1;
			for (j = 0; j<N; j++) {
				if (select[j] == 1) printf("%d ", input[j]);
			}
			select[i] = 0;
			printf("\n");
		}
		return 0;
	}
	input[N - 1] = 1;
	COMB(N - 1, K - 1, input, select);
	input[N - 1] = 0;
	COMB(N - 1, K, input, select);
}

int main() {

	int N =0 , K=0;
	int *input;
	int *select;
	printf("두 양의 정수를 입력하세요 : ");
	scanf("%d %d", &N, &K);

	if (K > N || N > 20)
	{
		printf("error : wrong value");
		return -1;
	}
	select = (int*)malloc(sizeof(int)*N);
	input = (int*)malloc(sizeof(int)*N);
	input = Input(input, N);
	for (int i = 0; i < N; i++)
		select[i] = 0;

	COMB(N, K, input, select);

	return 0;
}