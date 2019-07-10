#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char map[51][51];
bool visited[51][51];
int R, C;
int start_x, start_y;
int water_x, water_y;
int dst_x, dst_y;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <int> ret;
typedef struct {
	int x, y, cnt;

}pos;

bool isBoundary(int x, int y) {

	if (x< 0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

void print() {

	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS() {

	queue <pos> q;
	queue <pair<int, int>> water;
	q.push({ start_x, start_y ,0});
	visited[start_x][start_y] = true;

	water.push({ water_x, water_y });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;

		q.pop();

		int cwaterX = water.front().first;
		int cwaterY = water.front().second;

		water.pop();
		if (curX == dst_x && curY == dst_y)
			ret.push_back(ccnt);

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			int nwaterX = cwaterX + dx[i];
			int nwaterY = cwaterY + dy[i];
			if (isBoundary(nwaterX, nwaterY) && map[nwaterX][nwaterY] == '.') {
				water.push({ nwaterX, nwaterY });
				map[nwaterX][nwaterY] = '*';
			}

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]
				&& (map[nextX][nextY] == '.' || map[nextX][nextY] == 'D')) {
				visited[nextX][nextY] = true;
				q.push({ nextX, nextY, ccnt + 1 });
				map[curX][curY] = '.';
				map[nextX][nextY] = 'S';
			}
		}
		print();
	}
}

int main() {

	memset(visited, false, sizeof(visited));
	memset(map, '0', sizeof(map));

	string input;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {

		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'S')
			{
				start_x = i; start_y = j;
			}
			else if (map[i][j] == '*') {
				water_x = i; water_y = j;
			}
			else if (map[i][j] == 'D') {
				dst_x = i; dst_y = j;
			}
		}
	}

	BFS();

	if (!ret.empty())
	{
		sort(ret.begin(), ret.end());
		cout << ret[0];
	}
	else
		cout << "KAKTUS";
		
	return 0;
}