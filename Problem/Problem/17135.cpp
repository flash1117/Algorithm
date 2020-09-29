#include <iostream>
#include <queue>

using namespace std;

typedef struct {

	int x, y, cnt;
}Pos;

const int INF = 987654321;

int N, M, D, maxRemoveCnt;
int map[15][15];
int pick[4];

int getDist(int startX, int startY, int endX, int endY) {

	int x = 0, y = 0;

	if (endX > startX) {
		x = endX - startX;
	}
	else x = startX - endX;

	if (endY > startY) {
		y = endY - startY;
	}
	else y = startY - endY;

	return x + y;
}

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void moveMap() {

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M; j++) {

			map[i][j] = map[i - 1][j];
		}
	}

	for (int i = 0; i < M; i++) {
		map[0][i] = 0;
	}

	return;
}

Pos getMinPos(pair<int,int> pos) {

	bool visited[15][15];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	int dx[] = {0,-1,0,1};
	int dy[] = { -1,0,1,0 };

	queue<Pos> q;
	q.push({pos.first, pos.second, 0});

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (ccnt != 0 && map[curX][curY] == 1) {

			return { curX, curY, ccnt };

		}

		for (int i = 0; i < 4; i++) {
			
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]) {

				q.push({ nextX,nextY,ccnt + 1 });
				visited[nextX][nextY] = true;
			}

		}
	}

	return { -1,-1,-1 };
}

int getRemoveEnemy(int index1, int index2, int index3) {

	int ret = 0;
	pair<int, int> pos1 = { N, index1 };
	pair<int, int> pos2 = { N, index2 };
	pair<int, int> pos3 = { N, index3 };
	

	int _map[15][15];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {

		Pos p1, p2, p3;
		p1 = getMinPos(pos1);
		p2 = getMinPos(pos2);
		p3 = getMinPos(pos3);
		
		if (p1.cnt == -1) break;
		else {

			if (map[p1.x][p1.y]) {
				map[p1.x][p1.y] = 0;
				ret++;
			}
			if (map[p2.x][p2.y]) {
				map[p2.x][p2.y] = 0;
				ret++;
			}
			if (map[p3.x][p3.y]) {
				map[p3.x][p3.y] = 0;
				ret++;
			}


		}

		moveMap();

	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			map[i][j] = _map[i][j];
		}
	}


	return ret;
}




void solve(int depth, int cnt) {

	if (cnt == 3) {

		int rmEnemyCnt = getRemoveEnemy(pick[0], pick[1], pick[2]);
		maxRemoveCnt = maxRemoveCnt > rmEnemyCnt ? maxRemoveCnt : rmEnemyCnt;

		return;
	}

	if (depth >= M) return;

	pick[cnt] = depth;
	solve(depth + 1, cnt + 1);
	solve(depth + 1, cnt);

	return;
}

int main() {

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
		}
	}

	solve(0, 0);
	cout << maxRemoveCnt << "\n";

	return 0;
}