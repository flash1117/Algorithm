#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;

}

void landCheck(int area, int x, int y) {

	queue <pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		map[curX][curY] = area;

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 1) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;

			}
		}

	}
}

void print() {

	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}


}
int main() {

	int area = 1;

	memset(visited, false, sizeof(visited));
	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == 1)
			{
				landCheck(area, i, j);
				area++;
			}
		}
	}

	print();
	return 0;
}