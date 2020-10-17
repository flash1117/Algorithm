#include <iostream>
#include <queue>

using namespace std;

typedef struct {

	int x, y, cnt;
}Pos;


int N;
int map[100][100];
int cost[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };



void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cost[i][j] = -1;
		}
	}
}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void solve() {

	queue<Pos> q;
	q.push({ 0,0,map[0][0] });
	cost[0][0] = map[0][0];

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int sum = q.front().cnt;
		q.pop();


		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) ) {
				if (cost[nextX][nextY] == -1) {
					cost[nextX][nextY] = sum + map[nextX][nextY];
					q.push({ nextX, nextY, sum + map[nextX][nextY] });
				}
				else if (cost[nextX][nextY] > sum + map[nextX][nextY]) {
					cost[nextX][nextY] = sum + map[nextX][nextY];
					q.push({ nextX, nextY, sum + map[nextX][nextY] });
				}
			}
			
		}


	}


	return;
}

int main() {

	int t, num =0;
	cin >> t;
	while (t--) {
		num++;
		cin >> N;
		for (int i = 0; i < N; i++) {

			string input;
			cin >> input;
			for (int j = 0; j < N; j++) {
				map[i][j] = input[j] - '0';

			}
		}

		init();
		solve();

		cout << "#" << num << " " << cost[N - 1][N - 1] << "\n";
		

	}


	return 0;
}