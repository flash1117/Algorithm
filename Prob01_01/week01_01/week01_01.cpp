#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Swap(int *src, int *dst) {

	int temp;

	temp = *src;
	*src = *dst;
	*dst = temp;
}

int blank_count(char *buffer) {

	int count = 0;

	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ')
			count++;
	}

	return count;
}

int find_min(char *buffer, char *p, int M) {

	int packet[100000];
	int pos = 1;
	int count = 0;
	int min;

	p = strtok(buffer, " ");
	packet[0] = atoi(p);
	while (p != NULL) { // input packet

		p = strtok(NULL, " ");
		packet[pos++] = atoi(p);

	}

	for (int i = 0; i < pos; i++) {

		for (int j = 0; j < pos - count - 1; j++) {

			if (packet[j] > packet[j + 1])
				Swap(&packet[j], &packet[j + 1]);

		}
		count++;
	}

	count = 0;
	min = packet[1] - packet[0];
	for (int i = 0; i < M; i++) {
		if (packet[i + 1] - packet[i] < min)
			min = packet[i + 1] - packet[i];
	}
	
	return min;
}

int main() {

	int N; // chocolate number in packet
	int M; // student number and always N>=M
	int T; // test case number
	int T_count=0; // test case count
	char buffer[1000]; // file read line buffer
	char *p; // use for strtok

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

	while (1) {

		fgets(buffer, 1000, fp);
		if (blank_count(buffer) == 1) { // input N, M
			
			p = strtok(buffer, " ");
			N = atoi(p);
			p = strtok(NULL, " ");
			M = atoi(p);

			if (M > N) {
				printf("err02 : There is a student who does not have chocolate!\n");
				return -1;
			}
			T_count++;
		}
		else {// packet array
		
			printf("min = %d\n", find_min(buffer, p, M));
		
		} 	
		
		if (T_count == T+1) break;
	}

	fclose(fp);
	return 0;
}