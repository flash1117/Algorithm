#include <iostream>

using namespace std;

#define Endl "\n"

int N, M, cnt;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int map[51][51];
int visited[51][51];

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;

}

void print() {
	cout << Endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
			
		}
		cout << Endl;
	}

}

// 0 -> 3 -> 2 ->1 -> 0
void solve(int x, int y, int dir) {

	if (!isBoundary(x, y) || visited[x][y] || map[x][y] == 1) return;
	visited[x][y] = true;
	cnt++;

	print();
	bool isContinue = true;
	int checkCnt = 0;

	while (1) {
		
		if (map[x + dx[dir]][y + dy[dir]] == 0)
			solve(x + dx[dir], y + dy[dir], dir);
		else {

			if (dir == 0)
				solve(x + dx[dir + 3], y + dy[dir + 3], dir + 3);
			else
				solve(x + dx[dir - 1], y + dy[dir - 1], dir - 1);
		}

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (map[nextX][nextY] == 1 || visited[nextX][nextY])
				cnt++;
			if (cnt == 3)
				isContinue = false;
		}

		if (!isContinue) break;

	}

	
}

int main() {

	int loc1, loc2, d, input;
	cin >> N >> M;

	cin >> loc1 >> loc2 >> d;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i][j] = input;
		}
	}

	solve(loc1, loc2, d);

	cout << cnt;
	return 0;
}