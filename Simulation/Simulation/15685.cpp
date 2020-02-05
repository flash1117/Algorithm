#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int x,y,d,g;
}dragonCurve;

int N;
int map[101][101];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };


// 3 0 1 0 1 2 1 0   1 2 3 2 1 2 1 0


void solve(int x, int y, int d, int g) {
	
	vector <int> dir;
	int nextX = x + dx[d];
	int nextY = y + dy[d];

	map[x][y] = 1;
	map[nextX][nextY] = 1;
	dir.push_back(d);
	while (g--) {
		int bound = dir.size();
		for (int i = bound-1; i >=0; i--) {
			int tmp = dir[i] + 1;
			tmp = tmp > 3 ? 0 : tmp;
			dir.push_back(tmp);
			nextX += dx[tmp];
			nextY += dy[tmp];
			map[nextX][nextY] = 1;
		}
	}

}
int main() {
	int x, y, g, d;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		solve(y, x, d, g);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] && map[i + 1][j + 1]) cnt++;
		}
	}

	if (map[99][99] == 1 && map[100][99] == 1 && map[99][100] && map[100][100]) cnt++;
	cout << cnt << "\n";
	return 0;
}