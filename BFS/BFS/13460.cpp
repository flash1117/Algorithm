#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[11][11];
pair <int, int> dst, red, blue;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

typedef struct {
	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

bool getPos(int x , int y, int dir, int color) {

	queue <pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {

		pair<int, int> cur = q.front();
		q.pop();

		if (color == 1)
		{
			red.first = cur.first;
			red.second = cur.second;
		}
		else
		{
			blue.first = cur.first;
			blue.second = cur.second;
		}
	
		int nextX = cur.first + dx[dir];
		int nextY = cur.second + dy[dir];

		if (isBoundary(nextX, nextY)) {

			if (map[nextX][nextY] == 'O') return false;
			else if (map[nextX][nextY] == '.') {
				q.push(make_pair(nextX, nextY));

			}
			else;
		}
	}

	return true;
}

int solve() {

	queue <pos> r, b;
	r.push({ red.first, red.second, 0 });
	b.push({ blue.first, blue.second, 0 });

	while (!r.empty && !b.empty()) {

		int rX = r.front().x;
		int rY = r.front().y;
		int rcnt = r.front().cnt;

		int bX = b.front().x;
		int bY = b.front().y;
		
		if (rcnt > 10) break;

		r.pop(); b.pop();
		bool rState = false, bState = false;
		for (int i = 0; i < 4; i++) {

			rState = getPos(rX, rY, i, 1);
			bState = getPos(bX, bY, i, 2);
			if (rState && bState) {
				r.push({ red.first, red.second, rcnt + 1 });
				b.push({ blue.first, blue.second, rcnt + 1 });
			}
			else {
				if (!rState) return rcnt + 1;
			}
		}

	}
	return -1;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				red.first = i;
				red.second = j;
			}
			else if (map[i][j] == 'B') {
				blue.first = i;
				blue.second = j;

			}
		}
	}

	cout << solve();
	return 0;
}