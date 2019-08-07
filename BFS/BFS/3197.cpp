#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int R, C;
char map[1501][1501];
bool visited[1501][1501];
bool mvisited[1501][1501];

vector <pair<int, int>> vec;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int sx, sy;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool BFS() {

	queue <pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (curX != sx && curY != sy && map[curX][curY] == 'L')
			return true;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]
				&& (map[nextX][nextY] == '.' || map[nextX][nextY] == 'L'))
			{
				q.push(make_pair(nextX, nextY));
				visited[nextX][nextY] = true;

			}
		}

	}

	return false;
}

void meltGlacier(int day) {

	queue <pair<int, int>> q;

	if (day == 0) {

		for (int i = 0; i < R; i++) {

			for (int j = 0; j < C; j++) {
				if ((map[i][j] == '.' || map[i][j] == 'L') && !mvisited[i][j])
				{
					q.push(make_pair(i, j));
					mvisited[i][j] = true;
				}
			}
		}
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			q.push(vec[i]);
			visited[vec[i].first][vec[i].second] = true;
		}
		vec.clear();
	}

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !mvisited[nextX][nextY] && map[nextX][nextY] == 'X') {
				map[nextX][nextY] = '.';
				vec.push_back(make_pair(nextX, nextY));
			}
							
		}

	}
}

int main() {

	bool isMeet = false;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			cin >> map[i][j];
			if (map[i][j] == 'L')
				sx = i, sy = j;
		}
	}

	int day = 0;
	while (1) {
		isMeet =BFS();
		if (isMeet) break;

		meltGlacier(day++);
		memset(visited, false, sizeof(visited));
	}
	cout << day;

}