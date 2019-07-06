#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int M, N, K;
int map[51][51];
bool visited[51][51];
int area;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

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
void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 1)
			DFS(nextX, nextY);
	}


}

int main() {

	int T = 0;
	int pt1, pt2;
	cin >> T;
	while (T--) {

		area = 0;				// init	
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));


		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {

			cin >> pt1 >> pt2;
			map[pt2][pt1] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (!visited[i][j] && map[i][j] == 1) {
					DFS(i, j);
					area++;
				}
					
			}
		}

		cout << area << endl;
	}

	return 0;
}