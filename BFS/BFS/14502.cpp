#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, safeCnt=0, virusCnt=0;
int x1 = 0, x2 = 0, p1 = 0, p2 = 0;
int map[8][8];
int copymap[8][8];
bool visited[8][8];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <pair<int, int>> vec;
vector <int> ret;

void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cout << copymap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M- 1) return false;
	return true;
}

void copyMap() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			copymap[i][j] = map[i][j];

		}
	}
}

void makeWall(int cnt) {
	if (cnt == 3) {
		print();
		copymap[x1][p1] = 0;
		copymap[x2][p2] = 0;
	}
	else {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (copymap[i][j] == 0) {
					copymap[i][j] = 1;

					if (cnt == 1) {
						x1 = i;
						p1 = j;

						cout << "x1,y1 : " << x1 << p1 << endl;
					}
					else if (cnt == 2) {
						x2 = i;
						p2 = j;
						cout << "x2, y2 : " << x2 << p2 << endl;
					}

					makeWall(cnt + 1);
				}

			}
		}
	}
}

void BFS() {
	
	queue <pair<int, int>> q;
	int Count = 0;

	for (int i = 0; i < vec.size(); i++) {
		q.push({ vec[i].first, vec[i].second });
//		cout << "vec : " << vec[i].first << "vec 2: "<<vec[i].second << endl;
		visited[vec[i].first][vec[i].second] = true;
	}
		
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && copymap[nextX][nextY] == 0 && !visited[nextX][nextY]) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
				Count++;
			}

		}
	}
	ret.push_back(Count);
}

int main() {
	int wall = 3;

	memset(map, 0, sizeof(map));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				safeCnt++;
			if (map[i][j] == 2) {
				vec.push_back({ i,j });
				virusCnt++;
			}
				
		}
			
	}
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			if (map[i][j] == 0) {
				copyMap();
				memset(visited, false, sizeof(visited));

				copymap[i][j] = 1;
				makeWall(1);
				BFS();
				
				copymap[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	return 0;
}