#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int map[256][1001];
int dy[] = { -1,1 };
int ylen;

typedef struct {

	int x, y, left, right;

}pos;

bool isBoundary(int x, int y)
{
	if (x < 0 || y < 0 || x>224 || y>ylen-1) return false;;
	return true;

}
int BFS(int x, int y) {

	queue<pos> q;
	q.push({ x,y,0,0 });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int lcnt = q.front().left;
		int rcnt = q.front().right;

		q.pop();
		if (lcnt == 2 && rcnt == 2)
			return 1;

		for (int i = 0; i < 2; i++) {
			int nextY = curY + dy[i];

			if (isBoundary(curX, nextY) && map[curX][nextY] == 0) {
				if (i == 0)
					q.push({ curX, nextY, lcnt + 1, rcnt });
				else if (i == 1)
					q.push({ curX, nextY, lcnt , rcnt + 1 });
			}
			else if (isBoundary(curX, nextY) && map[curX][nextY] == 1 && lcnt < 2 && rcnt < 2)
				return 0;

		}

	}

	return 0;
}

int main() {
	int cnt = 1;
	int T = 10;
	int temp;

	while (T--) {
		memset(map, 0, sizeof(map));
		int ret = 0;
		cin >> ylen;

		for (int i = 0; i < ylen; i++) {
			cin >> temp;
			if (temp != 0) {
				for (int j = 0; j < temp; j++)
					map[j][i] = 1;

			}
		}

		for (int i = 0; i < 255; i++) {

			for (int j = 0; j < ylen; j++) {
				if (map[i][j] == 1)
					ret += BFS(i, j);
			}
		}


		cout << "#" << cnt++ << " " << ret << endl;
	}
	

	return 0;
}