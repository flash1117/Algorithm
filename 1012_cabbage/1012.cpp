#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

int cnt;
int T, M, N, K;

int map[51][51];
bool visited[51][51];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

queue<pos> q;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int BFS() {

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY]) {

				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
				cnt++;

			}
		}
	}

	return cnt;

}

int main() {
	pos p1;

	cin >> T;
	for (int i = 0; i < T; i++) {

		cin >> M >> N >> K;
		cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		for (int j = 0; j < K; j++) {

			cin >> p1.x >> p1.y;
			map[p1.y][p1.x] = 1;
			q.push({p1.y, p1.x});
		}

		cout << K - BFS() << endl;
	}

	return 0;
}