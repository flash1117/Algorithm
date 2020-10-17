#include <iostream>

using namespace std;

int N, M;
int map[500][500];
bool visited[500][500];
int maxSum;
bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void solve(int x, int y, int cnt,int sum) {

	if (!isBoundary(x, y)) return;
	else if (visited[x][y]) return;

	if (cnt == 4) {

		maxSum = maxSum > sum ? maxSum : sum;
		return;
	}
	visited[x][y] = true;

	solve(x + 1, y, cnt + 1, map[x + 1][y] + sum);
	solve(x , y+1, cnt + 1, map[x][y+1] + sum);
	solve(x - 1, y, cnt + 1, map[x - 1][y] + sum);
	solve(x , y-1, cnt + 1, map[x][y-1] + sum);

	visited[x][y] = false;
	return;
}

void noDFS(int x ,int y) {

	if (isBoundary(x, y - 1) && isBoundary(x, y + 1) && isBoundary(x + 1, y)) {
		int sum = map[x][y] + map[x][y - 1] + map[x][y + 1] + map[x + 1][y];
		maxSum = maxSum > sum ? maxSum : sum;
	}

	if (isBoundary(x, y - 1) && isBoundary(x, y + 1) && isBoundary(x - 1, y)) {
		int sum = map[x][y] + map[x][y - 1] + map[x][y + 1] + map[x - 1][y];
		maxSum = maxSum > sum ? maxSum : sum;
	}

	if (isBoundary(x, y + 1) && isBoundary(x - 1, y) && isBoundary(x + 1, y)) {
		int sum = map[x][y] + map[x][y + 1] + map[x - 1][y] + map[x + 1][y];
		maxSum = maxSum > sum ? maxSum : sum;
	}

	if (isBoundary(x, y - 1) && isBoundary(x - 1, y) && isBoundary(x + 1, y)) {
		int sum = map[x][y] + map[x][y - 1] + map[x - 1][y] + map[x + 1][y];
		maxSum = maxSum > sum ? maxSum : sum;
	}
	return;
}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			noDFS(i, j);
			solve(i, j, 1, map[i][j]);
		}
	}

	
	cout << maxSum << "\n";
	return 0;
}