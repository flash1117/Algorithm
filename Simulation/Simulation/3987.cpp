#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x, y, cnt, dir;
}pos;

int N, M;
char map[501][501];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
pair <int, int> src;

int chgDir(int x, char ch) {

	if (ch == '/') {
		if (x == 0) return 1;
		else if (x == 1) return 0;
		else if (x == 2) return 3;
		else if (x == 3) return 2;
	}
	else { 
		if (x == 0) return 3;
		else if (x == 1) return 2;
		else if (x == 2) return 1;
		else if (x == 3) return 0;
	}
}

bool isBoundary(int x, int y) {
	if (x < 0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int solve(int dir) {

	queue <pos> q;
	q.push({ src.first-1, src.second-1, 0 , dir});
	int cnt = 0;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		cnt = q.front().cnt;
		int dir = q.front().dir;

		q.pop();

		if (cnt > N * M +1) return -1;

		if (map[curX][curY] == 'C') {
			return cnt;
		}
		else if (map[curX][curY] == '.');
		else {
			dir = chgDir(dir, map[curX][curY]);
		}

		int nextX = curX + dx[dir];
		int nextY = curY + dy[dir];

		if (isBoundary(nextX, nextY)) {
			q.push({ nextX , nextY, cnt + 1, dir });
		}

	}
	return cnt+1;
}

int main() {
	pair<char, int> temp = { 0,0 };
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> src.first >> src.second;
	int buf = 0;
	for (int i = 0; i < 4; i++) {
		buf = solve(i);
		if (buf > temp.second) {
			if (i == 0) temp.first = 'U';
			else if (i == 1) temp.first = 'R';
			else if (i == 2) temp.first = 'D';
			else if (i == 3) temp.first = 'L';
			temp.second = buf;
		}
		else if (buf == -1) {
			if (i == 0) temp.first = 'U';
			else if (i == 1) temp.first = 'R';
			else if (i == 2) temp.first = 'D';
			else if (i == 3) temp.first = 'L';
			cout << temp.first << "\n" << "Voyager" << "\n";
			return 0;
		}
	}

	cout << temp.first << "\n" << temp.second << "\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            

	return 0;
}