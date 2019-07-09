#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, area =1;
int map[101][101];
bool visited[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <int> ret;

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void BFS(int x, int y) {

	queue <pos> q;
	q.push({ x,y,0 });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (map[nextX][nextY] == 0 && isBoundary(nextX, nextY))
			{
				q.push({ nextX, nextY, ccnt+1 });
				
			}
		}
	}
}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
			if (map[i][j] == 1)
				visited[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			
			if (map[i][j] == 1 && !visited[i][j]) {
				BFS(i, j);
			}			
		}
	}

	return 0;
}