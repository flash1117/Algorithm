#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int x, y, dir, movecnt;
}robot;

typedef struct {
	int x, y, dir;
}pos;

int M, N;
int map[101][101];
int visited[101][101];

pos src, dst;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool isBoundary(int x, int y) {
	if (x<1 || y<1 || x>M || y>N) return false;
	return true;
}

int rotCnt(int curdir, int nextdir) {

	if (curdir == nextdir) return 0;
	else if ((curdir == 0 && nextdir == 1) || (curdir == 1 && nextdir == 0)
		|| (curdir == 2 && nextdir == 3) || (curdir == 3 && nextdir == 2)) return 2;
	else return 1;
}

int solve() {
	int minCnt = M * N + 1;
	queue <robot> q;
	q.push({ src.x, src.y, src.dir, 0 });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int curDir = q.front().dir;
		int moveCnt = q.front().movecnt;

		q.pop();

		if (curX == dst.x && curY == dst.y) {
			moveCnt += rotCnt(curDir, dst.dir);
			minCnt = minCnt > moveCnt ? moveCnt : minCnt;
			continue;
		}

		for (int i = 0; i < 4; i++) {

			for (int j = 1; j <= 3; j++) {

				int nextX = curX + dx[i] * j;
				int nextY = curY + dy[i] * j;
				int nmoveCnt = moveCnt + rotCnt(curDir, i) + 1;

				if (!isBoundary(nextX, nextY) || map[nextX][nextY] == 1) break;
				else if (isBoundary(nextX, nextY) && (visited[nextX][nextY] == 0 || visited[nextX][nextY] > nmoveCnt)
					&& map[nextX][nextY] == 0) {
					q.push({ nextX, nextY, i,nmoveCnt });
					visited[nextX][nextY] = nmoveCnt;
				}

			}
		}

	}

	return minCnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	cin >> src.x >> src.y >> src.dir;
	cin >> dst.x >> dst.y >> dst.dir;
	src.dir--; dst.dir--;

	cout << solve() << "\n";

	return 0;
}