#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, w, h, tcnt =0;
int sx, sy;
char map[1001][1001];
bool visited[1001][1001];

vector <pair<int, int>> vec[101];

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x> h - 1 || y>w - 1) return false;
	return true;
}

int BFS() {

	queue <pos> q;
	queue <pair<int, int>> fire;
	q.push({ sx,sy,0 });
	for (int i = 0; i < vec[tcnt].size(); i++) {
		fire.push(make_pair(vec[tcnt][i].first, vec[tcnt][i].second));

	}

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		
		q.pop();
		for (int i = 0; i < fire.size(); i++) {


		}




	}


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
					vec[i].push_back(make_pair(i, j));

			}
		}

		int ret = BFS();
		tcnt++;
	}


}