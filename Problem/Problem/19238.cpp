#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int startX, startY, dstX, dstY;
}Customer;

typedef struct {
	int x, y, dist;
}Pos;

int map[20][20];
int N, M, Oil;
pair<int, int> taxiPos;
vector<Customer> cus;

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

Pos getMinPos() {

	bool visited[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	vector<pair<int, int>> vec;
	queue<Pos> q;
	q.push({ taxiPos.first, taxiPos.second , 0 });
	visited[taxiPos.first][taxiPos.second] = true;
	
	int bound = -1;
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int cnt = q.front().dist;
		q.pop();

		if (map[curX][curY] > 1 && bound == -1) {
			bound = cnt;
			vec.push_back(make_pair(curX, curY));
		}
		else if (bound != -1 && cnt > bound) break;
		else if (bound == cnt && map[curX][curY] > 1) {
			vec.push_back(make_pair(curX, curY));
		}

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] &&map[nextX][nextY] != 1) {
				q.push({ nextX, nextY, cnt + 1 });
				visited[nextX][nextY] = true;
			}

		}

	}


	if (vec.empty()) {
		return { -1,-1,-1 };
	}
	else {

		sort(vec.begin(), vec.end(), compare);
		return { vec.front().first, vec.front().second , bound };
	}
	
}

int customerMove(int srcX, int srcY) {

	bool visited[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	queue<Pos> q;
	int index = map[srcX][srcY] - 2;
	q.push({ srcX, srcY, 0 });
	visited[srcX][srcY] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int cnt = q.front().dist;
		q.pop();

		if (curX == cus[index].dstX && curY == cus[index].dstY) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] &&map[nextX][nextY] != 1) {
				q.push({ nextX, nextY, cnt + 1 });
				visited[nextX][nextY] = true;
			}

		}

	}

	return -1;
}

bool isAllVisit() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] > 1) return false;
		}
	}

	return true;

}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int solve() {

	while (1) {
		
		Pos c = getMinPos();
	//	print();
		if (c.dist == -1) {
			bool allVisit = isAllVisit();
			if (allVisit) return Oil;
			else return -1;
		}
		else {
			if (c.dist > Oil) return -1;
			else Oil -= c.dist;
		}
		

		int cost = customerMove(c.x, c.y);
		if (cost == -1) return -1;

		if (cost > Oil) return -1;
		else {
			Oil += cost;
			int index = map[c.x][c.y] - 2;
			map[c.x][c.y] = 0;
			taxiPos.first = cus[index].dstX;
			taxiPos.second = cus[index].dstY;
		}


	}

}


int main() {

	int index = 2;
	cin >> N >> M >> Oil;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> taxiPos.first >> taxiPos.second;
	taxiPos.first -= 1;
	taxiPos.second -= 1;

	for (int i = 0; i < M; i++) {
		Customer input;
		cin >> input.startX >> input.startY >> input.dstX >> input.dstY;
		input.startX -= 1;
		input.startY -= 1;
		input.dstX -= 1;
		input.dstY -= 1;
		map[input.startX][input.startY] = index++;
		cus.push_back(input);
	}

	cout << solve() << "\n";


	return 0;
}