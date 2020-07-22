#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x,y,pipeState;
}Pos;

int N;
int map[17][17];
bool visited[17][17];

int vdx[] = { 0,1 };
int vdy[] = { 1,1 };
int hdx[] = { 1,1 };
int hdy[] = { 0,1 };
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

bool isBoundary(int x, int y) {

	if (x < 1 || y < 1 || x > N || y > N) return false;
	return true;
}

int solve() {

	int ret = 0;
	queue <Pos> q;
	q.push({ 1,2,1 });

	while (!q.empty()) {
		
		int curX = q.front().x;
		int curY = q.front().y;
		int state = q.front().pipeState;

		q.pop();


		if (curX == N && curY == N) {
			ret++;
		}

		if (state == 1) { // 가로
			
			for (int i = 0; i < 2; i++) {
				int nextX = curX + vdx[i];
				int nextY = curY + vdy[i];

				if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && i == 0) q.push({ nextX, nextY,1 });
				else if (isBoundary(nextX, nextY) && i == 1 && map[nextX][nextY] == 0
					&& map[nextX][nextY - 1] == 0 && map[nextX - 1][nextY] == 0)
					q.push({ nextX, nextY, 3 });
				
			}

		}
		else if (state == 2) { // 세로
			for (int i = 0; i < 2; i++) {
				int nextX = curX + hdx[i];
				int nextY = curY + hdy[i];

				if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && i == 0) q.push({ nextX, nextY,2 });
				else if (isBoundary(nextX, nextY) && i == 1 && map[nextX][nextY] == 0
					&& map[nextX][nextY - 1] == 0 && map[nextX - 1][nextY] == 0)
					q.push({ nextX, nextY, 3 });
				
			}
		}
		else if (state == 3) { // 대각선

			for (int i = 0; i < 3; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && i != 2) q.push({ nextX, nextY,i + 1 });
				else if (isBoundary(nextX, nextY) && i == 2 && map[nextX][nextY] == 0
					&& map[nextX][nextY - 1] == 0 && map[nextX - 1][nextY] == 0)
					q.push({ nextX, nextY, 3 });
			}
		}


	}



	return ret;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	cout << solve() << "\n";


	return 0;
}