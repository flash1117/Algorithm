#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int x, y, cnt;
}Pos;

int map[20][20];
int N;
pair<int, int> sharkPos;
int sharkSize = 2;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}

Pos getMinPos(int sharkX, int sharkY) {

	int bound = -1;
	vector<pair<int, int>> vec;

	bool visited[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	queue<Pos> q;
	q.push({ sharkX, sharkY, 0 });
	visited[sharkX][sharkY] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int cost = q.front().cnt;

		q.pop();

		if (map[curX][curY] > 0 && map[curX][curY] < 7 && map[curX][curY] < sharkSize && bound == -1) {
			bound = cost;
			vec.push_back({ curX, curY });
	
		}
		else if (bound == cost && map[curX][curY] > 0 &&map[curX][curY] < 7 && map[curX][curY] < sharkSize) {

			vec.push_back({ curX, curY });
		}
		else if (bound != -1 && cost > bound) break;

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] <= sharkSize) {

				q.push({ nextX, nextY, cost + 1 });
				visited[nextX][nextY] = true;
			}
		}



	}

	if (bound == -1) {
		return { -1,-1,-1 };
	}
	else {
		sort(vec.begin(), vec.end(), compare);
		return { vec.front().first , vec.front().second , bound };
	}

}

bool isFishExist() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] < sharkSize) return true;
		}
	}
	return false;
}

int solve() {

	int _time = 0;
	int extraFish = 2;
	while (1) {

		Pos p = getMinPos(sharkPos.first, sharkPos.second);
		if (p.cnt == -1) return _time;
		else {

			_time += p.cnt;
			
			extraFish--;
			map[p.x][p.y] = 0;
			
			if (extraFish == 0) {
				sharkSize++;
				extraFish = sharkSize;
			}

			map[sharkPos.first][sharkPos.second] = 0;
			sharkPos.first = p.x;
			sharkPos.second = p.y;
			map[sharkPos.first][sharkPos.second] = 9;
		}
	}
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkPos.first = i;
				sharkPos.second = j;
			}
		}
	}

	cout << solve() << "\n";


	return 0;
}