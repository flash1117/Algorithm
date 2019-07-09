#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int map[301][301];
bool visited[301][301];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int area;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void melt(int x,int y) { 
	int cnt = 0;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nearX = x + dx[i];
		int nearY = y + dy[i];
		if (isBoundary(nearX, nearY) && !visited[nearX][nearY] && !map[nearX][nearY]) cnt++;
	}
	map[x][y] -= cnt;
	if (map[x][y] < 0) map[x][y] = 0;
}

void yearLasting() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) melt(i, j);
		}
	}
}

void DFS(int x, int y) {
	if (!isBoundary(x, y) || visited[x][y] || map[x][y] == 0) return;

	visited[x][y] = true;
		
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		DFS(nextX, nextY);
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int cnt = 0;
	memset(map, 0, sizeof(map));

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
		}
	}

	while (1) {
		area = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				if (map[i][j] > 0 && !visited[i][j])
				{
					DFS(i, j);
					area++;
				}
			}
		}
		if (area > 1) {
			cout << cnt;
			break;
		}
		else if (area == 0) {
			cout << 0;
			break;
		}
		memset(visited, false, sizeof(visited));
		yearLasting();
		cnt++;
	}
	
	return 0;
}