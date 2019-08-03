#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int N, M;
int sx, sy, dir;
int map[51][51];
bool visited[51][51];

typedef struct {

	int x, y, direct;

}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int BFS() {

	int cnt = 0;
	queue <pos> q;
	q.push({ sx,sy, dir });
	visited[sx][sy] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int direction = q.front().direct;
		q.pop();

		int nextX = curX + dx[direction];
		int nextY = curY + dy[direction];
		if (isBoundary(nextX, nextY)) {

		}

	}



}

int main() {

	cin >> N >> M;
	cin >> sx >> sy >> dir;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	BFS();

	return 0;
}