#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Swap(int *src, int *dst) {

	int temp = *src;
	*src = *dst;
	*dst = temp;

}

int *Input(int *TC, int N) {

	for (int i = 0; i < N; i++)
		TC[i] = i + 1;

	return TC;
}

void print_case(int Array[], int p) {
	for (int i = p - 1; i >= 0; i--) {
		printf("%d ", Array[i]);
	}
	printf("\n");
}

void Permutation(int N, int K, int p, int Array[], int *input) {
	if (K == 0) {
		print_case(Array, p);
		return;
	}
	
	for (int i = N - 1; i >= 0; i--) {
		Swap(&input[i], &input[N - 1]); //n-1�� ��� index�� swap�ؼ� �پ��� ������ �����.
		Array[K - 1] = input[N - 1];		  //T�� �ڿ������� ����� ����	
		Permutation(N - 1, K - 1, p, Array, input);		  //����  index�� ���� 	
		Swap(&input[i], &input[N - 1]);
	}
}

int main() {

	int N = 0, K = 0;
	int *input;
	int Array[10];
	printf("�� ���� ������ �Է��ϼ��� : ");
	scanf("%d %d", &N, &K);

	if (K > N || N > 20)
	{
		printf("error : wrong value");
		return -1;
	}

	input = (int*)malloc(sizeof(int)*N);
	input = Input(input, N);
	Permutation(N, K, K, Array, input);

	free(input);
	return 0;
}