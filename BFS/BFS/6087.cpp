#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {

	int x, y, dir, cnt;
}laser;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int visited[101][101];
int w, h;
char map[101][101];
vector <pair<int,int>> pos;

bool isBoundary(int x, int y) {

	if (x<0 || x>h || y<0 || y>w) return false;
	return true;
}

void print() {
	cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int solve() {

	queue <laser> q;

	q.push({ pos[0].first,pos[0].second,0,0 });
	visited[pos[0].first][pos[0].second] = 0;

	for (int i = 0; i < 4; i++) {
		int nextX = q.front().x;
		int nextY = q.front().y;
		if (isBoundary(nextX, nextY) && map[nextX][nextY] != '*') {
			q.push({ nextX, nextY , i, 0 });
			visited[nextX][nextY] = 0;
		}
	}
	q.pop();

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int prevDir = q.front().dir;
		int mirrorCnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] != '*' 
				&& visited[nextX][nextY] >= mirrorCnt +1 && prevDir != i) {
					q.push({ nextX, nextY, i, mirrorCnt + 1 });
					visited[nextX][nextY] = mirrorCnt + 1;
				
			}
			else if(isBoundary(nextX, nextY) && map[nextX][nextY] != '*'
				&& visited[nextX][nextY] >= mirrorCnt && prevDir == i) {
				q.push({ nextX, nextY, i, mirrorCnt });
				visited[nextX][nextY] = mirrorCnt;
			}

		}

	}

	return visited[pos[1].first][pos[1].second];
}


int main() {
	cin >> w >> h;
	string input;
	for (int i = 0; i < h; i++) {
		cin >> input;
		for (int j = 0; j < w; j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'C') pos.push_back(make_pair(i, j));
			visited[i][j] = 987654321;
		}
	}
	
	cout << solve() << "\n";
//	print();
	return 0;
}