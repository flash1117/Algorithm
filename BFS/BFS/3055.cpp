#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char map[51][51];
bool visited[51][51];
int R, C, ret=0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y;
}pos;

typedef struct {
	int x, y, cnt;

}dir;

pos src, dst;
vector <pair<int, int>> water;
queue <dir> Hedgehog;

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

void posInit(int x, int y) {

	if (map[x][y] == 'D') {
		dst.x = x;
		dst.y = y;
	}

	else if (map[x][y] == 'S') {
		src.x = x;
		src.y = y;

	}

	else if (map[x][y] == '*') 
		water.push_back({ x, y });

}

void moveHedgehog() {
	if (Hedgehog.empty()) {
		cout << "KAKTUS";
		return;
	}
	else {

		int curX = Hedgehog.front().x;
		int curY = Hedgehog.front().y;
		int ccnt = Hedgehog.front().cnt;
		Hedgehog.pop();
		visited[curX][curY] = true;

		if (curX == dst.x && curY == dst.y) {
			ret = ccnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			bool isWater = false;

			if ((map[nextX][nextY] == '.' || map[nextX][nextY] == 'D')&& isBoundary(nextX, nextY) && !visited[nextX][nextY])
			{
				for (int j = 0; j < 4; j++) {
					int nnextX = nextX + dx[i];
					int nnextY = nextY + dy[i];

					if (map[nnextX][nnextY] == '*')
						isWater = true;
				}

				if (!isWater) {
					visited[nextX][nextY] = true;
					Hedgehog.push({ nextX, nextY, ccnt + 1 });
				}
			}
		}

	}
}

void waterSpread() {

	queue <pos> q;
	for (int i = 0; i < water.size(); i++) 
		q.push({ water[i].first, water[i].second });
	
	while (!q.empty()) {

		for (int i = 0; i < water.size(); i++) {
			if (q.empty()) break;

			int curX = q.front().x;
			int curY = q.front().y;

			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (map[nextX][nextY] == '.' && isBoundary(nextX, nextY)) {
					map[nextX][nextY] = '*';
					q.push({ nextX, nextY });
				}
			}
		}
		print();
		moveHedgehog();
		if (ret != 0)
			break;
	}
}


int main() {

	memset(visited, false, sizeof(visited));

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			posInit(i, j);
		}

	}
	Hedgehog.push({ src.x, src.y , 0});
	waterSpread();

	if (ret != 0)
		cout << ret;
	return 0;
}
