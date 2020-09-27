#include <iostream>
#include <queue>

using namespace std;

int N, M, D;
int map[15][15];
int pick[4];


int getDist(int startX, int startY, int endX, int endY) {

	int x = 0, y = 0;

	if (endX > startX) {
		x = endX - startX;
	}
	else x = startX - endX;

	if (endY > startY) {
		y = endY - startY;
	}
	else y = startY - endY;

	return x + y;
}

int getRemoveEnemy(int index1, int index2, int index3) {

	pair<int, int> pos1 = { N, index1 };
	pair<int, int> pos2 = { N , index2 };
	pair<int, int> pos3 = { N, index3 };

	int _map[15][15];
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {


		for (int j = N - 1; j >= 0; j--) {


		}



	}



}


void solve(int depth, int cnt) {

	if (cnt == 3) {



		return;
	}

	if (depth >= M) return;

	pick[cnt] = depth;
	solve(depth + 1, cnt + 1);
	solve(depth + 1, cnt);

	return;
}

int main() {

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
		}
	}


	return 0;
}