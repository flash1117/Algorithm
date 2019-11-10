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

	dp[1][1] = map[1][1];
	dp[2][1] = map[2][1];

	for (int j = 2; j <= N; j++) {
		for (int i = 1; i <= 2; i++) {

			if (i == 1) 
				dp[i][j] = (dp[i + 1][j - 1] + map[i][j] > dp[i][j - 1]) ? dp[i + 1][j - 1] + map[i][j] : dp[i][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + map[i][j] > dp[i][j - 1]) ? dp[i - 1][j - 1] + map[i][j] : dp[i][j - 1];
			
		}
	}
	int ret = (dp[1][1] > dp[2][1]) ? dp[1][1] : dp[2][1];
	if (N == 1)
		cout << ret << "\n";
	else {
		ret = (dp[1][N] > dp[2][N]) ? dp[1][N] : dp[2][N];
		cout << ret << "\n";
	}
	
}

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
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