#include <iostream>

using namespace std;

int T, N;
int map[3][100002];
int dp[3][100002];

void init() {

	for (int i = 1; i <= 2; i++) 
		for (int j = 1; j <= N; j++)
			map[i][j] = 0;
	
}

void solve() {

	dp[1][1] = (map[1][2] > map[1][1]) ? map[2][1] : map[1][1];
	dp[1][1] = (map[2][1] > dp[1][1]) ? map[2][1] : dp[1][1];


	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= N; j++) {

			if (i == 1) {
				dp[i][j] = ()

			}
		}
	}

	cout << dp[2][N] << "\n";

}

int main() {

	cin >> T;
	while (T--) {

		cin >> N;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		solve();
		init();

	}

	return 0;
}