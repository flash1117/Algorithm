#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int map[16][16];
bool visited[16][16];
pair<int, int> src, dst;

bool isBoundary(int x, int y) {

	if (x < 0 || y < 0 || x>15 || y>15) return false;
	return true;
}

bool isValid() {

	queue<pair<int, int>> q;
	q.push(src);
	visited[src.first][src.second] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (map[curX][curY] == 3) return true;

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] != 1) {

				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
		}


	}

	return false;
}

void init() {


	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {

	int t = 10;
	
	while (t--) {

		int num;
		cin >> num;

		init();

		for (int i = 0; i < 16; i++) {


			string input;
			cin >> input;
			for (int j = 0; j < 16; j++) {
				map[i][j] = input[j] - '0';
				if (map[i][j] == 2) {
					src.first = i;
					src.second = j;

				}
				else if (map[i][j] == 3) {
					dst.first = i;
					dst.second = j;
				}
			}
		}

		bool state = isValid();
		int ret = 0;
		if (state) ret = 1;
		cout << "#" << num << " " << ret << "\n";
	}


	return 0;
}