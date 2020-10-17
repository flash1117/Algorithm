#include <set>
#include <iostream>

using namespace std;

int map[4][4];
set <int> s;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>3 || y>3) return false;
	return true;
}

void solve(int x, int y,  int cnt, int sum) {

	if (cnt == 6) {

		s.insert(sum);

		return;
	}

	for (int i = 0; i < 4; i++) {

		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (isBoundary(nextX, nextY)) {

			solve(nextX, nextY, cnt + 1, sum * 10 + map[nextX][nextY]);

		}

	}

	return;

}

int main() {

	int t;
	cin >> t;
	int num = 0;
	while (t--) {

		num++;
		s.clear();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}


		for (int i = 0; i < 4; i++) {
			for(int j=0; j<4; j++) {
				solve(i, j, 0, map[i][j]);
			}
		}

		cout << "#" << num << " " << s.size() << "\n";
	}


	return 0;
}