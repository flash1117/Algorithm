#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1000000

void init(int buffer[], int size) {

	for (int i = 0; i < size; i++) 
		buffer[i] = 0;
}

bool len_check(int cnt[], int K ) {

	for (int i=0; i < 26; i++)
	{
		if (cnt[i] >= K - 1) {

			printf("cnt = %d\n", cnt[i]);
			return false;

		}
			
	}

	return true;
}

int main() { // answer = 9 3 8 20 34 2412 12448 25219 25181 127227

	clock_t start, end;
	int T =0 ; // test case number
	int N =0, K=0;
	int T_count = 0; // test case count
	char buffer[SIZE]; // file read line buffer
	char *p; // use for strtok
	char ch;
	int i = 0;
	int max_len = 0;
	int cnt[26] = {0};
	int	pos_1[26] = { 0 }, pos_2[26] = { 0 };

	start = clock();
	
	FILE *fp = fopen("input08.txt", "r");
	T = atoi(fgets(buffer, SIZE, fp));

	while (!feof(fp)) {

		init(cnt, 26);
		init(pos_1, 26);
		init(pos_2, 26);
		max_len = 0;

		fscanf(fp, "%d %d ", &N, &K);
		
		while (1) {
			
			ch = fgetc(fp);
			if (ch >= 'A' && ch <= 'Z') {
				cnt[ch - 'A']++;
				
				if (cnt[ch - 'A'] == 1)
					pos_1[ch - 'A'] = i;
				else if (cnt[ch - 'A'] == K+1) {
					pos_2[ch - 'A'] = i;

						max_len = (max_len > pos_2[ch - 'A'] - pos_1[ch - 'A']) ? max_len : pos_2[ch - 'A'] - pos_1[ch - 'A'];
				}
				
				i++;
			}
			else
				break;

		}
		if (max_len == 0)
			max_len = N;

		printf("%d %d\n", N, K);
		printf("%d 번째 최대 길이 = %d\n", T_count + 1, max_len);
		T_count++;
	}

	end = clock();
	printf("걸린 시간 = %f초", (double)(end - start) / 1000);

	return 0;
}