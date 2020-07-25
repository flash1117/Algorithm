#include <iostream>

using namespace std;

int N, M, D;
int map[15][15], copyMap[15][15];
int pick[4];


void removeEnemy(int x, int y, int z) {

	pair<int, int> archer1 = { 6,x };
	pair<int, int> archer2 = { 6,y };
	pair<int, int> archer3 = { 6,z };

	for (int i = 0; i < N; i++) {




	}



}

int getDist(int r1 , int c1, int r2, int c2) {

	int ret = 0;

	if (r1 >= r2) ret += r1 - r2;
	else ret += r2 - r1;

	if (c1 >= c2) ret += c1 - c2;
	else ret += c2 - c1;

	return ret;
}

void comb(int depth, int cnt) {

	if (depth > M) return;

	if (cnt == 3) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copyMap[i][j] = map[i][j];
			}
		}
		removeEnemy(pick[0], pick[1], pick[2]);

	}

	pick[cnt] = depth;
	comb(depth + 1, cnt + 1);
	comb(depth + 1, cnt);
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