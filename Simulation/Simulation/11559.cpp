#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[13][7];
bool visited[13][7];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void print() {
	cout << endl;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>11 || y>5) return false;
	return true;
}

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = false;
		}
	}
}

bool BFS(int x, int y) {

	vector <pair<int, int>> footprint;
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	
	int cnt = 1;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		footprint.push_back(make_pair(curX, curY));

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[x][y] == map[nextX][nextY]) {
				q.push(make_pair(nextX, nextY));
				visited[nextX][nextY] = true;
				cnt++;
			}
		}
	}

	if (cnt >= 4) {
	
		for (int i = 0; i < footprint.size(); i++) {
			map[footprint[i].first][footprint[i].second] = '.';
		}
		footprint.clear();
		return true;
	}
	return false;
}

void setMap() {

	for (int i = 0; i < 6; i++) {

		for (int j = 11; j >= 0; j--) {
			if (map[j][i] != '.') {

				for (int k = 11; k > j; k--) {
					if (map[k][i] == '.') {
						map[k][i] = map[j][i];
						map[j][i] = '.';
						break;
					}
				}

			}
		}
	}
}

int main() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	int ret = 0, cnt = 0;
	bool isBreak = false;

	while(1) {
		cnt = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!visited[i][j] && map[i][j] != '.') {
					isBreak = BFS(i, j);
					if (isBreak) cnt++;
					
				}
			}
		}

		if (cnt == 0) break;
		else {
			ret++;
			init();
			setMap();
		}
	}
	
	cout << ret << "\n";
	return 0;
}