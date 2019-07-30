#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int R, C, sx, sy;
char map[1001][1001];
bool visited[1001][1001];
vector <pair<int, int>> vec;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

int BFS() {

	queue <pos> q;
	visited[sx][sy] = true;
	q.push({ sx, sy, 0 });
	queue <pair<int, int>> fire;

	for (int i = 0; i < vec.size(); i++)
		fire.push(make_pair(vec[i].first, vec[i].second));

	while (!q.empty()) {

		int fSize = fire.size();
		for (int i = 0; i < fSize; i++) {

			int fcurX = fire.front().first;
			int fcurY = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; j++) {
				int nextX = fcurX + dx[j];
				int nextY = fcurY + dy[j];

				if ((map[nextX][nextY] == '.' || map[nextX][nextY] == 'J') && isBoundary(nextX, nextY)) {
					map[nextX][nextY] = 'F';
					fire.push(make_pair(nextX, nextY));

				}
			}

		}

		int jSize = q.size();
		for (int k = 0; k < jSize; k++) {
			int curX = q.front().x;
			int curY = q.front().y;
			int ccnt = q.front().cnt;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == '.') {

					visited[nextX][nextY] = true;
					q.push({ nextX, nextY, ccnt + 1 });
				}

				else if (!isBoundary(nextX, nextY))
					return ccnt + 1;
			}

		}

	}

	return -1;
}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			cin >> map[i][j];
			if (map[i][j] == 'F')
				vec.push_back(make_pair(i, j));
			else if (map[i][j] == 'J')
			{
				sx = i;
				sy = j;
			}

		}
	}

	int ret = BFS();
	if (ret == -1) cout << "IMPOSSIBLE";
	else cout << ret;

	return 0;
}