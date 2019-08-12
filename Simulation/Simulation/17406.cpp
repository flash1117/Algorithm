#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int map[101][101];
bool visited[101][101];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1, 0, -1,0 };

typedef struct {

	int x, y, dis;
}pos;

vector <pos> rot;

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {

	queue <pos> q;
	int repo=0;

	for (int i = 0; i < rot.size(); i++)
	{
		memset(visited, false, sizeof(visited));

		int leftX = rot[i].x - rot[i].dis;
		int leftY = rot[i].y - rot[i].dis;
		int rightX = rot[i].x + rot[i].dis;
		int rightY = rot[i].y + rot[i].dis;

		while ((rightX > leftX) && (rightY > leftY)) {
			q.push({ leftX, leftY , 0 });
			repo = map[leftX][leftY];
		
			while (!q.empty()) {

				int curX = q.front().x;
				int curY = q.front().y;
				int dir = q.front().dis;
				q.pop();

				int nextX = curX + dx[dir];
				int nextY = curY + dy[dir];

				if (curX == leftX && curY == leftY && dir == 3) break;

				if (nextX > rightX || nextY > rightY || nextX < leftX || nextY < leftY) {

					if (dir != 3) {
						dir++;
						nextX = curX + dx[dir];
						nextY = curY + dy[dir];
						q.push({ nextX, nextY, dir });
						visited[nextX][nextY] = true;
						int nextValue = map[nextX][nextY];
						map[nextX][nextY] = repo;
						repo = nextValue;
					}

				}
				else {

					if (!visited[nextX][nextY]) {
						visited[nextX][nextY] = true;
						int nextValue = map[nextX][nextY];
						map[nextX][nextY] = repo;
						repo = nextValue;
						q.push({ nextX,nextY,dir });

					}


				}

			}

			leftX++;
			leftY++;
			rightX--;
			rightY--;

		}

	}

}

int main() {

	int x, y, distance;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

		}
	}

	for (int i = 0; i < K; i++) {
		cin >> x >> y >> distance;
		rot.push_back({ x-1,y-1,distance });
	}

	solve();

	int minValue = -1, temp=0;

	for (int i = 0; i < N; i++) {
		
		temp = 0;
		for (int j = 0; j < M; j++) 
			temp += map[i][j];

		if (minValue < 0) minValue = temp;
		else
			if (minValue > temp) minValue = temp;
	}

	cout << minValue;
	return 0;
}