#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {

	int srcX, srcY, dstX, dstY;
}Customer;

typedef struct {
	int x, y, cnt;
}Pos;

pair <int, int> taxi;
int map[21][21]; // map
bool visited[21][21]; // check already visited for BFS
int cost[21][21]; // cost for pickup customer
int N, M, oil;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <Customer> ct;

void print() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}

}

bool isBoundary(int x, int y) {

	if (x<1 || x>N || y<1 || y>N) return false;
	return true;
}

void initVisited() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}
}

void setCostMap(int taxiX, int taxiY) { // 현재 택시의 x,y를 기준으로 각 맵에 이동 cost 계산

	initVisited();

	queue <Pos> q;
	q.push({ taxiX , taxiY, 0 });
	visited[taxiX][taxiY] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		cost[curX][curY] = ccnt;

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 0) {

				q.push({ nextX, nextY, ccnt + 1 });
				visited[nextX][nextY] = true;
			}
		}

	}
	return;
}

bool compare(const Customer &a, Customer &b) {
	// stack을 이용할 것이라서 비용이 작은사람이 제일 끝에 위치하도록 할 것임
	if (cost[a.srcX][a.srcY] == cost[b.srcX][b.srcY]) {

		if (a.srcX == b.srcX) return a.srcY > b.srcY;
		else return a.srcX >= b.srcX;

	}
	else return cost[a.srcX][a.srcY] > cost[b.srcX][b.srcY]; // cost가 큰쪽이 오도록 정렬
}

bool isArrive() {

	setCostMap(taxi.first, taxi.second);
	sort(ct.begin(), ct.end(), compare);

	int curX = ct[ct.size() - 1].srcX;
	int curY = ct[ct.size() - 1].srcY;
	int dstX = ct[ct.size() - 1].dstX;
	int dstY = ct[ct.size() - 1].dstY;

	ct.pop_back();

	if (cost[curX][curY] > oil) return false;
	else if (cost[curX][curY] == 0 && curX != taxi.first && curY != taxi.second) return false;
	initVisited();
	oil -= cost[curX][curY];


	queue<Pos> q;
	q.push({ curX, curY, 0 });
	visited[curX][curY] = true;

	while (!q.empty()) {

		curX = q.front().x;
		curY = q.front().y;
		int cnt = q.front().cnt;

		q.pop();

		if (curX == dstX && curY == dstY) {

			oil += cnt;
			taxi.first = dstX;
			taxi.second = dstY;
			return true;
		}

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (cnt + 1 > oil) return false;
			else if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 0) {
				
				q.push({ nextX, nextY, cnt + 1 });
				visited[nextX][nextY] = true;
			}
		}

	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> oil;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> taxi.first >> taxi.second;
	for (int i = 0; i < M; i++) {
			
		Customer pos; // customer position
		cin >> pos.srcX >> pos.srcY >> pos.dstX >> pos.dstY;
		ct.push_back(pos);
		
	}

	while (!ct.empty()) {

		bool state = isArrive();

		if (!state) {
			oil = -1;
			break;
		}
		
	}

	cout << oil << "\n";
	return 0;
}