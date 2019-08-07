#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int L, R, C, sx, sy, sz;
char map[31][31][31];
bool visited[31][31][31];

int dx[] = { 0,0,0,0,-1,1 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { -1,1,0,0,0,0 };

typedef struct {

	int z, x, y, cnt;
}pos;

void print() {

	for (int k = 0; k < L; k++) {

		for (int i = 0; i < R; i++) {

			for (int j = 0; j < C; j++)
				cout << map[k][i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
}

bool isBoundary(int x, int y, int z) {

	if (x < 0 || y < 0 || z < 0 || x> R - 1 || y > C - 1 || z >L - 1) return false;
	return true;
}

int BFS() {

	queue <pos> q;
	q.push({ sz, sx, sy ,0});
	visited[sz][sx][sy] = true;

	while (!q.empty()) {

		int curZ = q.front().z;
		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;

		q.pop();

		if (map[curZ][curX][curY] == 'E')
			return ccnt;

		for (int i = 0; i < 6; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			int nextZ = curZ + dz[i];

			if (isBoundary(nextX, nextY, nextZ) && !visited[nextZ][nextX][nextY]
				&& (map[nextZ][nextX][nextY] == '.' || map[nextZ][nextX][nextY] == 'E')) {

				q.push({ nextZ, nextX, nextY, ccnt + 1 });
				visited[nextZ][nextX][nextY] = true;
			}

		}
	
	}
	return -1;
}

int main() {

	while (cin >> L >> R >> C )
	{
		if (L == 0 & R == 0 && C == 0) break;
		for (int k = 0; k < L; k++) {

			for (int i = 0; i < R; i++) {
				for (int j = 0; j< C; j++) {
					cin >> map[k][i][j];
					if (map[k][i][j] == 'S')
						sz = k, sx = i, sy = j;
				}
			}
		}

		int ret = BFS();
		if (ret == -1) cout << "Trapped!"<<endl;
		else cout << "Escaped in " << ret << " minute(s)." << endl;
		memset(visited, false, sizeof(visited));
	
	}

	return 0;
}