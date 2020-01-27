#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, K;
int add[10][10];
int map[10][10];
int isSpread[10][10];
int summerAdd[10][10];
deque <int> input[10][10];

int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { -1,1,0,0,-1,1,-1,1 };

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
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

	while (K--) {
		for (int i = 0; i < N; i++) { // spring
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				for (int k = 0; k < input[i][j].size(); k++) {
					
					if (input[i][j][k] <= map[i][j]) {
						map[i][j] -= input[i][j][k];
						input[i][j][k]++;
						if (input[i][j][k] % 5 == 0) {
							isSpread[i][j]++;
						}
					}
					else {
						summerAdd[i][j] += input[i][j][k] / 2;
						cnt++;
					}
				}
				for (int k = 0; k < cnt; k++) input[i][j].pop_back();
			}
		}
		for (int i = 0; i < N; i++) { 
			for (int j = 0; j < N; j++) {
				map[i][j] += summerAdd[i][j];
				summerAdd[i][j] = 0;

				if (isSpread[i][j] == 0) continue;
				while (isSpread[i][j]) {
					for (int k = 0; k < 8; k++) {
						int nextX = i + dx[k];
						int nextY = j + dy[k];
						if (isBoundary(nextX, nextY))
							input[nextX][nextY].push_front(1);
					}
					isSpread[i][j]--;
				}
				
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] += add[i][j];
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += input[i][j].size();
		}
	}
	return ret;
}

int main() {

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> add[i][j];
			map[i][j] = 5;

		}
	}
	int x, y, age;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> age;
		input[x - 1][y - 1].push_back(age);
	}

	cout << solve() << "\n";
	return 0;
}