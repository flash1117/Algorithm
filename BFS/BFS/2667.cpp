#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int map[26][26];
int visited[26][26];
int cnt[600];
int add = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N || y>N) return false;
	return true;

}

void BFS(int x, int y) {

	cout << "in BFS";
	queue <pair<int, int>> q;
	q.push({x,y});
	visited[x][y] = 1;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY])
			{
				visited[nextX][nextY] = 1;
				q.push({ nextX, nextY });
				cnt[add]++;
			}

		}

	}
	add++;
}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	cin >> N;
	if (N < 5 || N > 25)
		return -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j]) {
				BFS(i, j);
				cout << "test";
			}
				
		}
	}

	sort(cnt, cnt + add);
	for (int i = 0; i < add; i++)
		cout << cnt[i] << endl;

	return 0;
}