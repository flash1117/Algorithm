#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
 
int N, M;
int map[1001][1001];
bool visited[1001][1001];
vector <int> vec;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void BFS() {

	queue <pos> q;
	q.push({ 0,0,1 });
	visited[0][0] = true;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (curX == N - 1 && curY == M - 1) {
			vec.push_back(ccnt);
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 0) {
				q.push({ nextX, nextY, ccnt + 1 });
				visited[nextX][nextY] = true;
			}

		}

	}


}

int main() {
	int min_d =2000;
	string temp;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> temp;
		for (int j = 0; j < M; j++) {
			
			map[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (map[i][j] == 1) {
				memset(visited, false, sizeof(visited));
				map[i][j] = 0;
				BFS();
				map[i][j] = 1;
			}
		}
	}

	if (vec.empty())
		cout << "-1";
	else {
		for (int i = 0; i < vec.size(); i++)
			if (min_d > vec[i]) min_d = vec[i];

		cout << min_d;
	}
	
	return 0;
}