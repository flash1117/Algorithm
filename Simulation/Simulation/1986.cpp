#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
typedef struct {
	int x, y, dir;
}pos;

vector <pair<int,int>> queen;
vector <pair<int,int>> knight;
vector <pair<int, int>> pawn;
bool visited[1000][1000];
char map[1000][1000];

int qdx[] = { 0,0,-1,1,-1,-1,1,1 };
int qdy[] = { 1,-1,0,0,1,-1,-1,1 };
int kdx[] = { -2,-2,-1,-1,1,1,2,2 };
int kdy[] = { 1,-1,2,-2,2,-2,1,-1 };

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int solve() {

	int cnt = 0;
	queue <pos> q;
	queue <pos> k;

	for (int i = 0; i < queen.size(); i++) {
		for (int j = 0; j < 8; j++) {
			q.push({ queen[i].first - 1, queen[i].second - 1 ,j });
		}
		visited[queen[i].first - 1][queen[i].second - 1] = true;
	}
	for (int i = 0; i < knight.size(); i++) {
		for (int j = 0; j < 8; j++) {
			k.push({ knight[i].first - 1, knight[i].second - 1 ,j});
		}
		visited[knight[i].first - 1][knight[i].second - 1] = true;
	}
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int dir = q.front().dir;
		q.pop();

		int nextX = curX + qdx[dir];
		int nextY = curY + qdy[dir];

		if (isBoundary(nextX, nextY) && map[nextX][nextY] == NULL) {
			q.push({ nextX, nextY ,dir});
			visited[nextX][nextY] = true;
		}
	}

	while (!k.empty()) {

		int curX = k.front().x;
		int curY = k.front().y;
		int dir = k.front().dir;
		k.pop();

		int nextX = curX + kdx[dir];
		int nextY = curY + kdy[dir];

		if (isBoundary(nextX, nextY) && map[nextX][nextY] == NULL) {
			visited[nextX][nextY] = true;
		}
		
	}

	for (int i = 0; i < pawn.size(); i++)
		visited[pawn[i].first - 1][pawn[i].second - 1] = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) cnt++;

		}
	}

	return cnt;
}

int main() {

	int input;
	pair<int, int> pos;
	cin >> N >> M;
	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> pos.first >> pos.second;
		queen.push_back(pos);
		map[pos.first - 1][pos.second - 1] = 'Q';
	}
	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> pos.first >> pos.second;
		knight.push_back(pos);
		map[pos.first - 1][pos.second - 1] = 'K';
	}
	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> pos.first >> pos.second;
		pawn.push_back(pos);
		map[pos.first - 1][pos.second - 1] = 'P';
	}

	cout << solve() << "\n";

	return 0;
}