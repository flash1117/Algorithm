#include <iostream>

using namespace std;

int N;

int dp[100001][3];

void solve() {

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {

		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];

		if (dp[i][0] > 9901) dp[i][0] %= 9901;
		else if (dp[i][1] > 9901) dp[i][1] %= 9901;
		else if (dp[i][2] > 9901) dp[i][2] %= 9901;
	}

	if (dp[N][0] + dp[N][1] + dp[N][2] > 9901) {
		dp[N][0] = (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
		cout << dp[N][0] << "\n";
	}
	else
		cout << dp[N][0] + dp[N][1] + dp[N][2] << "\n";
}

int main() {
	cin >> N;
	solve();
	
	return 0;
}