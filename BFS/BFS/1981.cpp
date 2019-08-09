#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101];
int n;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return false;
	return true;
}
int BFS() {

	int ret;
	int maxNum = 0, minNum = 101;
	queue <pair<int,int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		if (map[curX][curY] > maxNum) maxNum = map[curX][curY];
		if (map[curX][curY] < minNum) minNum = map[curX][curY];

		ret = 
		if (curX == n - 1 && curY == n - 1)
			continue;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) & !visited[nextX][nextY]) {
				q.push(make_pair(nextX, nextY));
				visited[nextX][nextY] = true;
			}
		}

	}
	return 0;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	return 0;
}