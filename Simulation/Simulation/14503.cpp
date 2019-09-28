#include <iostream>
#include <queue>

using namespace std;

typedef struct {

	int x, y, dir;
}pos;

int N, M, r, c, d;
int map[51][51];
bool visited[51][51];
int dx[] = { -1, 0, 1,0 };
int dy[] = { 0,1,0,-1 };

bool isBoundary(int x, int y) {
	if (x< 0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void print() {

	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << visited[i][j];
		}
		cout << endl;
	}
}

int nextDir(int currentDirection) {

	if (currentDirection == 0) return 3;
	else if (currentDirection == 1) return 0;
	else if (currentDirection == 2) return 1;
	else if (currentDirection == 3) return 2;
	else
		return -1;
}

int backDir(int currentDirection) {
	if (currentDirection == 0) return 2;
	else if (currentDirection == 1) return 3;
	else if (currentDirection == 2) return 0;
	else if (currentDirection == 3) return 1;
	else
		return -1;

}

int solve() {

	int cnt = 1;
	queue <pos> q;
	visited[r][c] = true;
	q.push({ r,c,d });

	while (!q.empty()) {
	//	print();
		int curX = q.front().x;
		int curY = q.front().y;
		int curDir = q.front().dir;

		q.pop();

		for (int i = 0; i < 4; i++) {

			curDir = nextDir(curDir);
				
			int nextX = curX + dx[curDir];
			int nextY = curY + dy[curDir];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				q.push({ nextX, nextY, curDir });
				cnt++;
				break;
			}
			
		}

		if (q.empty()) {

			int nextX = curX + dx[backDir(curDir)];
			int nextY = curY + dy[backDir(curDir)];

			if (map[nextX][nextY] == 0 && isBoundary(nextX,nextY))
				q.push({ nextX, nextY, curDir });

		}
	}
	
	return cnt;
}

int main() {

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	cout << solve();
	return 0;
}