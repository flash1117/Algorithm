#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
bool visited[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int stX, stY;
bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>99 || y> 99) return false;
	return true;
}

bool solve() {

	queue <pair<int, int>> q;
	q.push({ stX,stY });
	visited[stX][stY] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		if (map[curX][curY] == 3) return true;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]&& map[nextX][nextY] != 1) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
		}

	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T = 10, num =0;

	while (T--) {
		cin >> num;
		string temp;
		for (int i = 0; i < 100; i++) {
			cin >> temp;
			for (int j = 0; j < 100; j++) {
				map[i][j] = temp[j] - '0';
				if (map[i][j] == 2) {
					stX = i; stY = j;
				}
				visited[i][j] = false;
			}
		}

		bool state = solve();
		if (state) cout << "#" << num << " 1\n";
		else cout << "#" << num << " 0\n";

	}

	return 0;
}