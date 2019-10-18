#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[1001][4];
int dp[1001][4];

int solve() {

	for (int i = 1; i <= N; i++) {

		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + map[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + map[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][3];
		
	}

	int temp = min(dp[N][1], dp[N][2]);
	temp = min(temp, dp[N][3]);

	return temp;
}


int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 3; j++)
			cin >> map[i][j];

	cout << solve();

	return 0;
}