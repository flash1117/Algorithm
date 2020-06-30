#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret = 987654321;
int map[21][21];

bool isBoundary(int x, int y) {
	if (x<1 || y<1 || x>N || y>N) return false;
	return true;
}

int solve(int x, int y) {

	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) {

			for (int i = 1; i < x + d1; i++) {
				for (int j = 1; j <= y; j++) {


				}
			}


		}
	}

	return -1;
}
int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int 1 = 0; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N-2; i++) {
		for (int j = 1; j <= N-1; j++) {
			solve(i, j);
		}
		

	}


	return 0;
}