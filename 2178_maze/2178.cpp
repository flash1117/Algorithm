#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
bool visited[101][101];
bool map[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct pt {
	int x, y, len;
};

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int BFS() {
	queue<pt> q;
	q.push({ 0,0,1 });
	visited[0][0] = true;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int len = q.front().len;
		q.pop();

		if (curX == N - 1 && curY == M - 1) return len;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (inBoundary(nextX, nextY) && map[nextX][nextY] && !visited[nextX][nextY]) {
				q.push({ nextX,nextY,len + 1 });
				visited[nextX][nextY] = true;
			}
		}
	}
}


int main() {
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	cout << BFS();

	return 0;
}