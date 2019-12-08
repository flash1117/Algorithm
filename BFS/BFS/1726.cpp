#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101][101];
bool visited[101][101];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

typedef struct {
	int x, y, dir, cnt;
}pos;

pos src, dst;

bool isBoundary(int x, int y) {
	if (x<1 || y<1 || x>N || y>M) return false;
	return true;
}

int dirCnt(int src, int dst) {

	if (src == 0) {
		if (dst == 1) return 2;
		else if (dst == 0) return 0;
	}
	else if (src == 1)
	{
		if (dst == 0) return 2;
		else if (dst == 1) return 0;
	}
	else if (src == 2) {
		if (dst == 3) return 2;
		else if (dst == 2) return 0;
	}
	else{
		if (dst == 2) return 2;
		else if (dst == 3) return 0;
	}
	return 1;
}

int solve() {

	queue <pos> q;
	q.push({ src.x, src.y, src.dir - 1, 0 });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int cnt = q.front().cnt;
		int dir = q.front().dir;

		q.pop();

		if (curX == dst.x && curY == dst.y) {
			return cnt + dirCnt(dir, dst.dir - 1);
		}

		cout << curX << " , " << curY << " " << dir+1 << " " << cnt << endl;

		for (int i = 0; i < 4; i++) {
			int nextX = curX;
			int nextY = curY;
			int nextCnt = cnt + dirCnt(dir,i);

			for (int j = 0; j < 3; j++) {
				nextX += dx[i];
				nextY += dy[i];
				if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && !visited[nextX][nextY])
				{
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY, i, nextCnt+1 });
				}
			}
		}
	}
	return -1;
}

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	cin >> src.x >> src.y >> src.dir;
	cin >> dst.x >> dst.y >> dst.dir;
	solve();
	return 0;
}