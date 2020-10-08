#include <iostream>
#include <queue>

using namespace std;

typedef struct {

	int x, y, cnt;
}SafePos;

int N, M;
int map[50][50];
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}


int getSafeDist(int x, int y) {

	bool visited[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	queue<SafePos> q;
	q.push({x,y,0});
	visited[x][y] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (map[curX][curY] == 1) return ccnt;


		for (int i = 0; i < 8; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]) {
				q.push({ nextX, nextY, ccnt + 1 });
				visited[nextX][nextY] = true;
			}

		}


	}

	return -1; // error 
}

int main() {

	int maxSafeDist = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				int dist = getSafeDist(i, j);
				maxSafeDist = maxSafeDist > dist ? maxSafeDist : dist;
			}


				
		}
	}

	cout << maxSafeDist << "\n";

	return 0;
}