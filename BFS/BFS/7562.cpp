#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, N;
int map[301][301];
bool isFound = false;

int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,2,-2,2,-2,1,-1 };

vector <int> ret;

typedef struct {

	int x, y;

}pos;

typedef struct {

	int x, y, cnt;

}process;


bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N || y>N) return false;
	return true;

}

void BFS(int sx, int sy, int dstx, int dsty) {

	queue <process> q;
	q.push({ sx, sy, 0 });
	map[sx][sy] = 1;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (curX == dstx && curY == dsty && isFound == false) {
				ret.push_back(ccnt);
				isFound = true;
			}
				
			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && isFound == false) {
				q.push({ nextX, nextY , ccnt + 1 });
				map[nextX][nextY] = 1;
			
			}

		}
	}
}

int main() {

	cin >> T;

	pos src, dst;

	while (T--) {
		memset(map, 0, sizeof(map));
		isFound = false;

		cin >> N;
		cin >> src.x >> src.y >> dst.x >> dst.y;

		if (src.x == dst.x && src.y == dst.y)
			ret.push_back(0);
		else
			BFS(src.x, src.y, dst.x, dst.y);

	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}