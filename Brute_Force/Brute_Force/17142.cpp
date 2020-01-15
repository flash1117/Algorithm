#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ret = -1, infectArea;
int map[50][50];
bool visited[50][50];
vector <pair<int,int>> vec;
int pick[10];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {
	int x, y, cnt;
}pos;


bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void initArray() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) visited[i][j] = true;
			else visited[i][j] = false;
		}
	}

}

void solve(int depth, int cnt) {
	if (depth > vec.size()) return;

	if (cnt == M) {
		initArray();
		int maxTime = 0, index =0, infectCnt =0;
		queue <pos> q;
		for (int i = 0; i < M; i++) {
			q.push({ vec[pick[i]].first,vec[pick[i]].second, 0 });
			visited[vec[pick[i]].first][vec[pick[i]].second] = true;
		}

		while (!q.empty()) {
			int curX = q.front().x;
			int curY = q.front().y;
			int ccnt = q.front().cnt;

			q.pop();

			if (map[curX][curY] == 0) {
				maxTime = ccnt > maxTime ? ccnt : maxTime;
				infectCnt++;
			}

			if (infectCnt == infectArea) continue;

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (isBoundary(nextX, nextY) && (map[nextX][nextY] == 0 || map[nextX][nextY] == 2) && !visited[nextX][nextY]) {
					q.push({ nextX, nextY, ccnt + 1 });
					visited[nextX][nextY] = true;
				}
				
			}
		}

		if (infectCnt != infectArea) return;
		else if (ret == -1) ret = maxTime;
		else ret = maxTime > ret ? ret : maxTime;
		return;
	}

	pick[cnt] = depth;
	solve(depth + 1, cnt + 1);
	pick[cnt] = 0;

	solve(depth + 1, cnt);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				vec.push_back({ i,j });
			else if (map[i][j] == 0) infectArea++;
		}
	}

	solve(0, 0);
	cout << ret << "\n";
	return 0;
}