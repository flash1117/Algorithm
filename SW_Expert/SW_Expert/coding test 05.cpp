#include <iostream>
#include <queue>

using namespace std;

int n, m, minDis;
int dstX, dstY;
int map[25][25];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ret[625];


typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>m || y>n) return false;
	return true;
}

void BFS() {

	queue <pos> q;
	q.push({ 0,0,0 });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;

		q.pop();

		if (curX == dstX && curY == dstY) {
			if (minDis == 0) minDis = ccnt;
			ret[ccnt]++;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0) {
				if (minDis != 0 && ccnt > minDis);
				else q.push({ nextX, nextY, ccnt + 1 });

			}

		}
	}
}

int main(void) {

	cin >> n >> m;
	cin >> dstY >> dstX;

	BFS();

	for (int i = 0; i < 626; i++) {
		if (ret[i] != 0) {
			cout << i << endl;
			cout << ret[i] << endl;
			break;
		}
	}

	return 0;
}