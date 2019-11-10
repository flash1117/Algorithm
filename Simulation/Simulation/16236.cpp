#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x, y, killCnt, move;
}pos;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,-1 };

int N;
int map[21][21];
bool visited[21][21];
pos shark;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void init() {

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			visited[i][j] = false;
}
int solve() {

	int time = 0, sharkSize = 2;
	queue <pos> q;
	q.push({ shark.x, shark.y ,0, 0});
	
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int kCnt = q.front().killCnt;
		int sharkMove = q.front().move;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] < sharkSize && !visited[nextX][nextY]) {

				visited[nextX][nextY] = true;
				if (map[nextX][nextY] != 0) {
					init();
					if (kCnt + 1 == sharkSize) {
						sharkSize++;
						q.push({ nextX, nextY, 0 ,0 });
					}
					else
						q.push({ nextX, nextY, kCnt + 1 , 0 });
					time += sharkMove;
				}
				else
					q.push({ nextX, nextY, kCnt , sharkMove + 1 });
			}
			else if (isBoundary(nextX, nextY) && map[nextX][nextY] == sharkSize && !visited[nextX][nextY]) {
				q.push({ nextX, nextY, kCnt , sharkMove + 1 });
				visited[nextX][nextY] = true;
			}
		}

	}

	return time;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = i;
				shark.y = j;
			}
		}
	}

	cout << solve();

	return 0;
}