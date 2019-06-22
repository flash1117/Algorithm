#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define pos pair<int,int>

struct toma {
	int x, y, cnt;
};

using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isRipe = false;
int cnt = 0;
vector <pos> vec;

bool isBoundary(int x, int y) {

	if (x < 0 || y <0 || x>N || y>M) return false;
	return true;
}


int BFS(int x, int y) {
	queue<toma> tq;
	tq.push({ 0,0,0 });

	while (!tq.empty()) {
		int cx = tq.front().x;
		int cy = tq.front().y;
		int ccnt = tq.front().cnt;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (map[nx][ny] == 0) {
				tq.push({ nx,ny,ccnt + 1 });
			}

		}

	}







	queue <pos> q;
	
	if (isRipe == false)
		return 0;

	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && visited[nextX][nextY] == 0 && map[nextX][nextY] == 0)
			{
				q.push({ nextX, nextY });
				visited[nextX][nextY] = 1;
				
			}

		}

	}
}


bool isFullRipe() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (visited[i][j] == 0)
				return false;

		}
	}
	return true;
}

int main() {
	cin >> M >> N;

	if (M < 2 || N < 2 || M >1000 || N>1000)
		return -1;

	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
			if (isRipe == false && map[i][j] == 0)
				isRipe = true;
			if (map[i][j] == 1)
				vec.push_back({ i,j });
			else if (map[i][j] == -1)
				visited[i][j] = 1;

				
		}

	}

	for (int i = 0; i < vec.size(); i++) {
		BFS(vec[i].first, vec[i].second);
	}

	if (!isFullRipe()) {
		cout << "-1";
		return 0;

	}
		
	else if (!isRipe) {
		cout << "0";
		return 0;

	}
		
	else
		cout << "cnt : " <<cnt;

	return 0;
}