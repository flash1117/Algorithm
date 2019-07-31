#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
bool visited[101][101][2];
char map[101][101];
vector <pair<int, int>> vec;
vector <pair<int, int>> start;
vector <int > ret;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt, isFind;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>h - 1 || y>w - 1) return false;
	return true;

}

int BFS() {

	int minD = 10001;
	queue <pos> q;
	for (int i = 0; i < start.size(); i++) {

		if (map[start[i].first][start[i].second] == '.')
			q.push({ start[i].first, start[i].second, 0,0 });
		else if (map[start[i].first][start[i].second] == '#')
			q.push({ start[i].first, start[i].second, 1,0 });

		cout << "start : " << start[i].first << " , " << start[i].second << endl;
		visited[start[i].first][start[i].second][0] = true;
	}
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		int Find = q.front().isFind;

		q.pop();
		if ((curX == vec[0].first && curY == vec[0].second) ||
			(curX == vec[1].first && curY == vec[1].second)) {
			Find++;
			visited[curX][curY][Find] = true;
			if (Find == 2) { 
				if (minD > ccnt) minD = ccnt;
				continue;
			}
		}

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY][Find]) {
			
				if (map[nextX][nextY] == '.')
				{
					q.push({ nextX, nextY, ccnt , Find });
					visited[nextX][nextY][Find] = true;
				}
				else if (map[nextX][nextY] == '#') {
					visited[nextX][nextY][Find] = true;
					q.push({ nextX, nextY, ccnt+1 , Find });
				}
			}

		}

	}

	return minD;

}


void findStart() {

	while (1) {

		for (int i = 0; i < w; i++) {
			if (map[0][i] == '.')
				start.push_back(make_pair(0, i));
			else if (map[h - 1][i] == '.')
				start.push_back(make_pair(h - 1, i));
		}

		for (int i = 0; i < h; i++) {

			if(map[i][0] == '.')
				start.push_back(make_pair(i, 0));
			else if(map[i][w-1] == '.')
				start.push_back(make_pair(i, h-1));
		}

		if (!start.empty()) break;

		for (int i = 0; i < w; i++) {
			if (map[0][i] == '#')
				start.push_back(make_pair(0, i));
			else if (map[h - 1][i] == '.')
				start.push_back(make_pair(h - 1, i));
		}

		for (int i = 0; i < h; i++) {

			if (map[i][0] == '#')
				start.push_back(make_pair(i, 0));
			else if (map[i][w - 1] == '.')
				start.push_back(make_pair(i, h - 1));
		}

		break;
	}

}
int main() {

	int T;
	cin >> T;
	while (T--) {
		memset(visited, false, sizeof(visited));
		cin >> h >> w;
		for (int i = 0; i < h; i++) {

			for (int j = 0; j < w; j++) {

				cin >> map[i][j];
				if (map[i][j] == '$')
					vec.push_back(make_pair(i, j));
			}
		}

		findStart();

		

		cout << BFS() << endl;

		vec.clear();
		start.clear();
	}


	return 0;
}