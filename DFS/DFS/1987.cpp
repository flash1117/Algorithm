#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int R, C;
char map[21][21];
bool visited[30];

int maxCnt = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {

	if (x < 0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

int DFS(int x, int y, int cnt) {

	int curChar = map[x][y] - 'A';
	visited[curChar] = true;

	if (maxCnt < cnt) maxCnt = cnt;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		int nChar = map[nextX][nextY] - 'A';

		if (isBoundary(nextX, nextY) && !visited[nChar]) {

			DFS(nextX, nextY, cnt + 1);

		}

	}

	visited[curChar] = false;
	return cnt;

}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			cin >> map[i][j];
		
	DFS(0, 0, 0);
	cout << maxCnt+1;
	return 0;
}