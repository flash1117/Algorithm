#include <iostream>

using namespace std;

// 사칙연산을 넣어서 최댓값과 최소값의 출력

#define MAX 1000000001
#define Endl "\n"

int N, minNum = MAX, maxNum = -MAX;
int An[11];
int sign[4]; // + , - , x , /

void Cal(int depth , int value) {

	if (depth == N-1) {

		if (value > maxNum) maxNum = value;
		if (value < minNum) minNum = value;

		return;
	}

	if (sign[0] > 0) {
		sign[0]--;
		Cal(depth + 1, value + An[depth+1]);
		sign[0]++;
	}

	if (sign[1] > 0) {
		sign[1]--;
		Cal(depth + 1, value - An[depth+1]);
		sign[1]++;

	}

	if (sign[2] > 0) {
		sign[2]--;
		Cal(depth + 1, value * An[depth+1]);
		sign[2]++;
	}

	if (sign[3]>0) {
		sign[3]--;
		Cal(depth + 1, value / An[depth+1]);
		sign[3]++;
	}
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> An[i];

	for (int i = 0; i < 4; i++)
		cin >> sign[i]; 

	Cal(0, An[0]);

	cout << maxNum << Endl;
	cout << minNum << Endl;

	return 0;
}