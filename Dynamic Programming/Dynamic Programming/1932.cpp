#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[501][501];
int map[501][501];

int solve() {

	int maxNum = 0;
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= i; j++) {

			if (j == 1) dp[i][j] = dp[i - 1][j] + map[i][j];
			else if (j == i) dp[i][j] = dp[i-1][j-1] + map[i][j];
			else 
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
			if (dp[i][j] > maxNum) maxNum = dp[i][j];
		}
	}	
	return maxNum;
}

int main() {

	
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> map[i][j];
	
	cout << solve();

	return 0;
}