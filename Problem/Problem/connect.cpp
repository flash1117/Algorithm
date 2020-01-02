#pragma warning(disable:4996)

#include <stdio.h>

int arr[200000];
int cntarr[200000];

int buf[5];
int point, cnt, head;

void init() {

	point = 0;
	cnt = 0;
	head = 0;

}

void push(int n) {

	cntarr[n] = ++cnt;

	if (!point) head = n;

	buf[point++ % 5] = n;

	if (point > 5) head = buf[point % 5];
}

int cal(int n) {

	int sum = 0;

	for (int i = 0; i < 5 && i < point; i++) {
		sum += (n - buf[i]);
		cntarr[buf[i]] = cntarr[head];
	}

	cnt = cntarr[head];
	return sum;
}

int main() {

	int TC, N;
	int now;

	scanf("%d", &TC);

	for (int k = 1; k <= TC; k++) {

		init();
		int sum = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);

			if (arr[i]) {   // �Է��� 1�϶�
				if (!point) cntarr[i] = ++cnt;
				else sum += cal(i);
			}
			else     // �Է��� 0�϶�
				push(i);

		}
		printf("#%d %d %d\n", k, sum, cnt);

	}

	return 0;
}