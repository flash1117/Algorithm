#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int map[50][50];
int spread[50][50];
vector <pair<int, int>> airCleaner;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

int solve() {

	while (T--) {

		for (int i = 0; i < R; i++) { // 미세먼지 확산
			for (int j = 0; j < C; j++) {
				int cnt = 0;

				for (int k = 0; k < 4; k++) {

					int nextX = i + dx[k];
					int nextY = j + dy[k];

					if (isBoundary(nextX, nextY) && map[nextX][nextY] != -1) {
						spread[nextX][nextY] += map[i][j] / 5;
						cnt++;
					}
				}

				map[i][j] -= cnt * (map[i][j] / 5);
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] += spread[i][j];
				spread[i][j] = 0;
			}
		}

		for (int i = airCleaner[0].first - 1; i > 0; i--) 
			map[i][0] = map[i - 1][0];
		
		for (int i = 0; i < C-1; i++) 
			map[0][i] = map[0][i + 1];
		
		for (int i = 0; i < airCleaner[0].first ; i++) 
			map[i][C - 1] = map[i + 1][C - 1];
		
		for (int i = C - 1; i > 1; i--) 
			map[airCleaner[0].first][i] = map[airCleaner[0].first][i - 1];
		
		map[airCleaner[0].first][1] = 0;

		for (int i = airCleaner[1].first + 1; i < R-1; i++) 
			map[i][0] = map[i + 1][0];
		
		for (int i = 0; i < C - 1; i++)
			map[R-1][i] = map[R-1][i + 1];

		for (int i = R - 1; i > airCleaner[1].first; i--) 
			map[i][C - 1] = map[i - 1][C - 1];
		
		for (int i = C - 1; i > 1; i--) {
			map[airCleaner[1].first][i] = map[airCleaner[1].first][i - 1];
		}

		map[airCleaner[1].first][1] = 0;
	}

	int ret = 0;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			ret += map[i][j];
	

	return ret+2;
}

int main() {

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				airCleaner.push_back(make_pair(i, j));
			}
		}
	}

	cout << solve() << "\n";
	return 0;
}