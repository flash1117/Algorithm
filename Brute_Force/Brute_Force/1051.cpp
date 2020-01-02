#include <iostream>

using namespace std;

int N, M;
int map[50][50];
int maxSq = 1;

bool isBoundary(int x, int y) {

	if (x< 0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

bool isVertexSame(int x, int y, int width) {

	if (map[x][y] == map[x + width][y] && map[x][y] == map[x][y + width]
		&& map[x][y] == map[x + width][y + width]) return true;
	
	return false;
}

void solve(int x, int y) {


	for (int i = 1; i <= 50; i++) {

		if (isBoundary(x + i, y + i)) {
			if (isVertexSame(x, y, i)) {
				maxSq = maxSq > (i+1) * (i+1) ? maxSq : (i+1) * (i+1);
			}
		}
		else return;
	}

}
int main() {

	string input;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			solve(i, j);
		}
	}

	cout << maxSq << "\n";

	return 0;
}