#include <iostream>
#include <queue>

using namespace std;

int w, h;
int map[51][51];

int dx[] = { -1,0,1,0 ,1,1,-1,-1};
int dy[] = { 0,1,0,-1 ,-1,1,1,-1};

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>h - 1 || y>w - 1) return false;
	return true;
}

void solve(int x, int y) {

	queue <pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 1) {
				q.push({ nextX, nextY });
				map[nextX][nextY] = 2;
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin >> w >> h;
	while (w !=0 && h !=0) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					solve(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		
		cin >> w >> h;
	}

	return 0;
}