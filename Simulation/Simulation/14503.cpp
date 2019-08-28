#include <iostream>

using namespace std;

#define Endl "\n"

int N, M, cnt;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int map[51][51];

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void print() {

	cout << Endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << map[i][j] << " ";
		}
		cout << Endl;
	}

}


// 0 -> 3 -> 2 ->1 -> 0
void solve(int x, int y, int dir) {

	if (!isBoundary(x, y) || map[x][y] == 1) return;
	
	print();

	if (map[x][y] == 0) {
		cnt++;
		map[x][y] = cnt;
		
	}

	for (int i = 0; i < 4; i++) {

		int nextDir = dir - 1 < 0 ? 3 : dir - 1;
		int nextX = x + dx[nextDir], nextY = y + dy[nextDir];

		if (map[nextX][nextY] == 0) {

			solve(nextX, nextY, nextDir);
			return;
		}
		else {

			dir = nextDir;
		}

	}


	int nextX = x - dx[dir], nextY = y - dy[dir];
	solve(nextX, nextY, dir);

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