#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char map[11][11];
bool visited[11][11];
int N, M;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <pair<int, int>> Red, Blue, dst;

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void print() {
	cout << endl;
	for (int i = 1; i <= N - 2; i++) {

		for (int j = 1; j <= M - 2; j++) {
			cout << map[i][j];
			
		}
		cout << endl;
	}

}

int BFS() {

	queue <pos> R, B;
	R.push({ Red[0].first, Red[0].second, 0 });
	B.push({ Blue[0].first, Blue[0].second, 0 });

	while (!R.empty()) {

		int rcurX = R.front().x;
		int rcurY = R.front().y;
		int rccnt = R.front().cnt;
		int bcurX = B.front().x;
		int bcurY = B.front().y;
		int bccnt = B.front().cnt;
		R.pop();
		B.pop();

		if (rcurX == dst.front().first && rcurY == dst.front().second)
			return rccnt;
		if (rccnt > 10) return -1;

		for (int i = 0; i < 4; i++) {
			int rnextX = rcurX + dx[i];
			int rnextY = rcurY + dy[i];
			int bnextX = bcurX + dx[i];
			int bnextY = bcurY + dy[i];

			if (isBoundary(rnextX, rnextY) && isBoundary(bnextX, bnextY)) {

				while (1) {
					int nextX = rnextX + dx[i];
					int nextY = rnextY + dy[i];
					if (map[nextX][nextY] == '.' && map[rnextX][rnextY] == '.') {
						rnextX = nextX;
						rnextY = nextY;
					}
					else if (map[nextX][nextY] == 'O' && map[rnextX][rnextY] == '.') {
						rnextX = nextX;
						rnextY = nextY;
						R.push({ rnextX, rnextY, rccnt + 1 });
					}
					else if (map[nextX][nextY] == '#' && map[rnextX][rnextY] == '.') {
						R.push({ rnextX, rnextY, rccnt + 1 });
					}

				}

				
			}


		}

	}
}


int main() {

	memset(visited, false, sizeof(visited));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
			if (map[i][j] == 'R')
				Red.push_back(make_pair(i, j));
			else if (map[i][j] == 'B')
				Blue.push_back(make_pair(i, j));
			else if (map[i][j] == 'O')
				dst.push_back(make_pair(i, j));
		}
	}

	int ret = BFS();
	cout << ret;
	return 0;
}