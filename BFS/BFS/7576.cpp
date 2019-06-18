#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int M, N; // 2이상 1000이하
int map[1001][1001];
bool visited[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {
	int x, y;
}pt;

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>M - 1 || y>N - 1) return false;
	return true;
}

queue<pt> q;

int BFS() {

	int cnt = 0;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		q.pop();

		cout << curX << curY << endl;

		for (int j = 0; j < 4; j++) {
			int nextX = curX + dx[j];
			int nextY = curY + dy[j];

			cout << "Boundary Value : " << inBoundary(nextX, nextY) << endl;
			cout << "next map (x,y) : " << map[nextX][nextY] << endl;
			cout << "M : " << M << " N : " << N << endl;
			cout << "nextX : " << nextX << " nextY : " << nextY << endl;
			cout << "!visit : " << !visited[nextX][nextY] << endl;

			if (inBoundary(nextX, nextY) && !map[nextX][nextY] && !visited[nextX][nextY]) {
				q.push({ nextX, nextY });
				cout << "execute queue push" << endl;
				visited[nextX][nextY] = true;
			}
			else if (map[nextX][nextY] == -1)
				continue;

		}
		cnt++;
	}

	return cnt;
}

int main() {

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];

			if (map[i][j] == 1)
				q.push({ i,j });
				
		}
	}

	cout << BFS();

	return 0;
}