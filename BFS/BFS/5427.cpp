#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, w, h, tcnt =0;
int sx, sy;
char map[1001][1001];
bool visited[1001][1001];

vector <pair<int, int>> vec;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt;
}pos;

void print() {
	cout << endl;
	for (int i = 0; i < h; i++) {

		for (int j = 0; j < w; j++) {

			cout << visited[i][j] << " ";
		}
		cout << endl;
	}

}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x> h - 1 || y>w - 1) return false;
	return true;
}

int BFS() {

	queue <pos> q;
	queue <pair<int, int>> fire;
	q.push({ sx,sy,1});
	visited[sx][sy] = true;

	for (int i = 0; i < vec.size(); i++) {
		fire.push(make_pair(vec[i].first, vec[i].second));
	}
		
	while (!q.empty()) {
	
		int fireSize = fire.size();
		for (int i = 0; i < fireSize; i++) {
			int fcurX = fire.front().first;
			int fcurY = fire.front().second;

			fire.pop();
			for (int j = 0; j < 4; j++) {
				int fnextX = fcurX + dx[j];
				int fnextY = fcurY + dy[j];

				if (isBoundary(fnextX, fnextY) && map[fnextX][fnextY] == '.') {
					fire.push(make_pair(fnextX, fnextY));
					map[fnextX][fnextY] = '*';

				}
									
			}

		}
	
		int pSize = q.size();
		
		for (int i = 0; i < pSize; i++) {
			int curX = q.front().x;
			int curY = q.front().y;
			int ccnt = q.front().cnt;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nextX = curX + dx[j];
				int nextY = curY + dy[j];

				if (!isBoundary(nextX, nextY))
					return ccnt;

				if (isBoundary(nextX, nextY) && map[nextX][nextY] == '.' && !visited[nextX][nextY]) {
					q.push({ nextX, nextY, ccnt + 1 });
					visited[nextX][nextY] = true;
				}
			}

		}

	//	print();
	}

	return -1;
}


int main() {

	string temp;
	cin >> T;

	while (T--) {
		memset(map, '0', sizeof(map));
		memset(visited, false, sizeof(visited));

		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			
			cin >> temp;
			for (int j = 0; j < w; j++) {
				map[i][j] = temp[j];
				if (map[i][j] == '@') {
					sx = i;
					sy = j;
				}
				else if (map[i][j] == '*') 
					vec.push_back(make_pair(i, j));

			}
		}

		int ret = BFS();

		if (ret == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout <<ret << endl;
		vec.clear();
	}

	return 0;
}