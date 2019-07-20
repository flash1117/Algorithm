#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[51][51];
int dx[] = { 0,0,-1,1 }; // 0 -> west 1 -> east 2 ->north 3 ->south
int dy[] = { -1,1,0,0 };
bool visited[51][51];

typedef struct {
	int x, y, cnt;

}pos;
 
bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>m - 1 || y>n - 1) return false;
	return true;

}

bool isWall(int value) {

	string temp = "";
	int q = value;
	if (value == 15) return false;
	else if (value == 0) return true;
	else {
		for (int i = 0; i < 4; i++) {
			q = q / 2;
			if (q == 0 && q % 2 == 0) break;
			temp += q % 2;
		}
		
	}

	cout << temp << endl;
	return false;
}

int BFS(int x, int y) {

	queue <pos> q;
	visited[x][y] = true;
	q.push({ x,y,1 });

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;

		for (int i = 0; i < 4; i++) {
			
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if(isBoundary(nextX, nextY) && !visited[nextX][nextY])
		}

	}



}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
				BFS(i, j);
		}
	}


	return 0;
}