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

void DFS(int x, int y) {

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nearX = x + dx[i];
		int nearY = y + dy[i];

		if (map[nearX][nearY] == 0 && map[x][y] > 0 && !visited[nearX][nearY])
			map[x][y] -= 1;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] > 0)
			DFS(nextX, nextY);
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << map[i][j] << " ";
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

		cnt++;
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				if (map[i][j] > 0 && !visited[i][j])
					{
						DFS(i, j);
						area++;
						if (area > 1) {
							cout << cnt-1;
							return 0;
						}
					}
			}
		}
	}

	
	return 0;
}