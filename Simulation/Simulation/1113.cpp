#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[51][51];
bool visited[51][51];

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int solve(int x, int y) {

	queue <pair<int, int>> q;
	
	int water = 0;
	
	

	return water;
}


int main() {
	
	string input;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j]- '0';

		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {

		}
	}
	return 0;
}