#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
bool visited[101][101];
int map[101][101];
int maxSafe=0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N || y>N) return false;
	return true;

}

void BFS(int basePoint) {

	bool startPoint = false;
	queue <pair<int, int>> q;

	for (int i = 0; i < N; i++) { // queue push
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > basePoint) {
				q.push({ i,j });
				visited[i][j] = true;
				startPoint = true;
				break;
			}
				
		}
		if (startPoint)
			break;
	}

	while (!q.empty()) {

		int safeZone = 0;
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

	int max_height = 0;
	memset(map, 0, sizeof(map));
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] > max_height)
				max_height = map[i][j];
		}
	}

	for (int i = 0; i < max_height; i++) {
		memset(visited, false, sizeof(visited));
		BFS(i);
	}


	return 0;
}