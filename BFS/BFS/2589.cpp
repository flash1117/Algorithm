#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char map[50][50];
int N, M;
bool visited[50][50];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt;

}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N || y>M) return false;
	return true;
}

int BFS(int x, int y) {

	queue <pos> q;
	q.push({ x,y,0 });
	visited[x][y] = 1;
	int ccnt = 0;

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			
			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 'L') {
				q.push({ nextX, nextY, ccnt + 1 });
				visited[nextX][nextY] = true;

			}

		}


	}

	return ccnt;
}



int main() {

	string temp;
	memset(map, '0', sizeof(map));
	int ret =0, max_ret=0;

	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j];

		}

	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			if (map[i][j] == 'L') {

				memset(visited, false, sizeof(visited));
				ret = BFS(i, j);
				if (ret > max_ret) max_ret = ret;
			}
			
		}
	}
	
	cout << max_ret << endl;
	return 0;
}