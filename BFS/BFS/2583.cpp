#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>


using namespace std;

int M, N, K;
int area = 0;
int map[101][101];
bool visited[101][101];

vector <int> ret;

typedef struct {

	int x, y;
}rect;

typedef struct {

	int x, y, cnt;
}pos;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


void print() {

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {


			cout << map[i][j];
		}
		cout << endl;
	}
}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>M || y>N) return false;
	return true;

}

void BFS(int i, int j) {

	queue <pos> q;

	q.push({ i,j,0 });
	visited[i][j] = true;
	int ccnt;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] ==0) {
				q.push({ nextX, nextY, ccnt+1 });
				visited[nextX][nextY] = true;
			}

		}
	}
	area++;
	ret.push_back(ccnt);
	
}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	cin >> M >> N >> K;
	
	rect left, right;

	for (int k = 0; k < K; k++) {

		cin >> left.x >> left.y >> right.x >> right.y;
		
		for (int i = M - right.y; i < M - left.y; i++) {

			for (int j = N - right.x; j < N - left.x; j++) {

				map[i][j] = 1;
			}
		}

	}

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {

			if (map[i][j] == 0 && visited[i][j] == false) {

				BFS(i,j);
			}

		}
	}

	sort(ret.begin(), ret.end());
	
	cout << area << endl;
	for (int i = 0; i < ret.size(); i++) 
		cout << ret[i] << " ";
		
	return 0;
}