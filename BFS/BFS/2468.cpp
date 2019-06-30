#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N=0;
int map[101][101];
bool visited[101][101];
int safeZone = 0;
int maxSafe = 1;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1, 0,0 };

bool isBoundary(int x, int y) {

	if (x <0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void BFS(int x, int y, int basePoint) {

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] > basePoint)
			{
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;

			}

		}

	}


}

int main() {
	int max_num = 0;
	memset(map, 0, sizeof(map));
	
	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
			if (map[i][j] > max_num) max_num = map[i][j];
		}
		
	}

	cout << "max number : " << max_num;

	for (int i = 1; i <= max_num; i++) {
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < N; j++) {

			for (int k = 0; j < N; k++) {

				if (!visited[j][k] && map[j][k] > max_num) {
				//	visited[j][k] = true;
					BFS(j, k, max_num);
					safeZone++;
				}
				
			}
		}
		cout << "safezone : " << safeZone << endl;
		if (safeZone > maxSafe) maxSafe = safeZone;
	}

	cout << maxSafe;

	return 0;
}