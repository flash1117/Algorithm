#include <iostream>

using namespace std;

int N, M, ret, cctvNum;
int map[8][8];
int copyMap[8][8];
int pick_[65];

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move(int x, int y, int dir) {

	if (dir == 0) { // north
		for (int i = x - 1; i >= 0; i--)
		{
			if (map[i][y] == 6) break;
			else if (map[i][y] > 0) continue;
			map[i][y] = -1;
		}
	}
	else if (dir == 1) { // east
		for (int i = y + 1; i < M; i++) {
			if (map[x][i] == 6) break;
			else if (map[x][i] > 0) continue;
			map[x][i] = -1;
		}
	}
	else if (dir == 2) { // south
		for (int i = x + 1; i <N; i++)
		{
			if (map[i][y] == 6) break;
			else if (map[i][y] > 0) continue;
			map[i][y] = -1;
		}
	}
	else if (dir == 3) { // west
		for (int i = y - 1; i >=0 ; i--) {
			if (map[x][i] == 6) break;
			else if (map[x][i] > 0) continue;
			map[x][i] = -1;
		}
	}
}

void cntBlindSpot() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) cnt++;
		}
	}
	ret = ret > cnt ? cnt : ret;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			map[i][j] = copyMap[i][j];
	}
}

void solve(int cnt) {

	if (cnt == cctvNum) {
		init();
		int index = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					move(i, j, pick_[index++]-1);
				}
				else if (map[i][j] == 2) {
					if (pick_[index] == 1 || pick_[index] == 3) {
						move(i, j, 0); move(i, j, 2);
					}
					else if (pick_[index] == 2 || pick_[index] == 4) {
						move(i, j, 1); move(i, j, 3);
					}
					index++;
				}
				else if (map[i][j] == 3) {

					int next = pick_[index] % 4;
					move(i, j, pick_[index++] - 1);
					move(i, j, next);
					
				}
				else if (map[i][j] == 4) {
					int next = pick_[index] % 4;
					int nnext = (pick_[index] + 1) % 4;

					move(i, j, pick_[index++] - 1);
					move(i, j, next);
					move(i, j, nnext);
									
				}
				else if (map[i][j] == 5) {
					move(i, j, 0); move(i, j, 1); move(i, j, 2); move(i, j, 3);
					index++;
				}
			}
		}
		
		cntBlindSpot();
		return;
	}


	for (int i = 1; i <= 4; i++) {
		pick_[cnt] = i;
		solve(cnt + 1);
	}

}

int main() {

	cin >> N >> M;
	ret = M * N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			copyMap[i][j] = map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) cctvNum++;
		}
	}

	solve(0);
	cout << ret << "\n";

	return 0;
}