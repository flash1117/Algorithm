#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int R, C;
char map[51][51];
bool visited[51][51];
vector <pair<int, int>> src, dst, w;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

void print() {

	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}

int BFS() {

	queue <pair<int, int>> water;
	queue <pos> Hoghedge;
	Hoghedge.push({ src[0].first, src[0].second, 0 });
	visited[src[0].first][src[0].second] = true;

	for (int i = 0; i < w.size(); i++) {

		water.push(w[i]);
	}
		
	while (!Hoghedge.empty()) {

		for (int i = 0; i < water.size(); i++) {
			int wcurX = water.front().first;
			int wcurY = water.front().second;
			water.pop();
			
			for (int j = 0; j < 4; j++) {
				int wnextX = wcurX + dx[j];
				int wnextY = wcurY + dy[j];

				if (isBoundary(wnextX, wnextY) && map[wnextX][wnextY] == '.')
				{
					map[wnextX][wnextY] = '*';
					water.push(make_pair(wnextX, wnextY));
				}
			}
		}

	//	print();
		for (int j = 0; j < Hoghedge.size(); j++) {
			int curX = Hoghedge.front().x;
			int curY = Hoghedge.front().y;
			int ccnt = Hoghedge.front().cnt;
			Hoghedge.pop();

			if (curX == dst[0].first && curY == dst[0].second)
				return ccnt;

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (isBoundary(nextX, nextY) && !visited[nextX][nextY]
					&& (map[nextX][nextY] == '.' || map[nextX][nextY] == 'D'))
				{
					visited[nextX][nextY] = true;
					Hoghedge.push({ nextX, nextY, ccnt + 1 });

				}

			}

		}

	}

		
	return -1;
}


int main() {

	int ret = 0;
	memset(visited, false, sizeof(visited));
	cin >> R >> C;
	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {

			cin >> map[i][j];
			if (map[i][j] == 'S') {
				src.push_back(make_pair(i, j));
			}
				
			else if (map[i][j] == 'D') {
				dst.push_back(make_pair(i, j));
			}
				
			else if (map[i][j] == '*') {
				w.push_back(make_pair(i, j));
			}
				
		}
	}

	ret = BFS();
	if (ret == -1)
		cout << "KAKTUS";
	else {
		cout << ret;
	}

	return 0;
}