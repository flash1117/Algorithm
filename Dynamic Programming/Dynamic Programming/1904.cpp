#include <iostream>

using namespace std;

int N;
int dp[1000001];

void solve() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = dp[2] + dp[3];
	for (int i = 5; i <= N; i++) {

		dp[i] = dp[i - 2] + dp[i - 1];
		if (dp[i] > 15746) dp[i] %= 15746;
	}
	cout << dp[N];
}

int main() {

	cin >> N;
	solve();

	return 0;
}