#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[1001][1001];
bool visited[1001][1001];
vector<int> ret;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, breakable, cnt;
}pos;

void print() {

	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";

		}
		cout << endl;
	}
}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void BFS() {

	queue <pos> q;
	q.push({ 0,0,0,1 });
	visited[0][0] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int breakWall = q.front().breakable;
		int ccnt = q.front().cnt;

		q.pop();
		if (curX == N - 1 && curY == M - 1)
			ret.push_back(ccnt);

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 0) {
				visited[nextX][nextY] = true;
				q.push({ nextX, nextY, breakWall, ccnt + 1 });
			}
			else if (isBoundary(nextX, nextY) && map[nextX][nextY] == 1 && breakWall == 0) {
			//	visited[nextX][nextY] = true;
				q.push({ nextX, nextY, breakWall + 1, ccnt + 1 });
			}

		}
	}

}


int main() {

	string temp;
	int minD = 10000;
	memset(visited, false, sizeof(visited));
	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> temp;
		for (int j = 0; j < M; j++) {

			map[i][j] = temp[j] - '0';
		}
	}
	
	BFS();
	//print();
	if (ret.empty())
		cout << "-1";
	else {

		for (int i = 0; i < ret.size(); i++)
			if (minD > ret[i]) minD = ret[i];
		cout << minD;
	}

	
	return 0;
}