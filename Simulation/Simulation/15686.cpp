#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[51][51];
bool visited[51][51];
vector <pair<int, int>> vec;
int ret = 2501;
int arr[13];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {
	int x, y, distance;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;

}

int solve() {

	int temp=0;
	queue <pos> q;

	for (int i = 0; i < M; i++) {
		q.push({ vec[arr[i]].first, vec[arr[i]].second ,0});
		visited[vec[arr[i]].first][vec[arr[i]].second] = true;
	}

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().distance;

		q.pop();
		if (map[curX][curY] == 1)
			temp += ccnt;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]) {

				q.push({ nextX, nextY, ccnt + 1 });
				visited[nextX][nextY] = true;
			}

		}

	}

	return temp;
}

void chickenChoice(int depth , int cnt) {

	if (depth == M) {
		int temp = solve();
		if (ret > temp) ret = temp;
		memset(visited, false, sizeof(visited));
		return;
	}

	for (int i = cnt; i < vec.size(); i++) {

		arr[depth] = i;
		if(i>arr[depth-1] || i==0)
			chickenChoice(depth + 1, cnt + 1);
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				vec.push_back(make_pair(i, j));
				
		}
	}
	
	chickenChoice(0, 0);

	cout << ret;
	return 0;
}