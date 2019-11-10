#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
long long dp[102][102];
int N;

bool isBoundary(int x, int y) {
	if (x<1 || y<1 || x>N || y>N) return false;
	return true;
}


void solve() {

	if(isBoundary(1+map[1][1], 1))
		dp[1 + map[1][1]][1] = 1;
	if(isBoundary(1, 1+map[1][1]))
		dp[1][1 + map[1][1]] = 1;

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {

			if (dp[i][j] != 0) {
				int temp = map[i][j];
				if (temp != 0) {
					if (isBoundary(i + temp, j))
						dp[i + temp][j] += dp[i][j];
					if (isBoundary(i, j + temp))
						dp[i][j + temp] += dp[i][j];
				}
			}
		}
	}
	cout << dp[N][N] << "\n";
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	solve();

	return 0;
}