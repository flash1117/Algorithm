#include <iostream>
#include <queue>

using namespace std;

int M, N;
int map[501][501];
int dp[501][501];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool isBoundary(int x, int y) {
	if (x<1 || y<1 || x>N || y>N) return false;
	return true;
}

void solve() {

	queue <pair<int, int>> q;
	q.push(make_pair(1, 1));
	int cnt = 0;
	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		if (curX == M && curY == N) {
			cnt++;
			continue;
		}
			
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] < map[curX][curY]) {
				q.push(make_pair(nextX, nextY));
			}
		}
	}

	cout << cnt << "\n";

}

int main() {

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];

		}
	}

	solve();
	return 0;
}