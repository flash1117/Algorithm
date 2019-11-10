#include <iostream>

using namespace std;

long long N, K;
long long dp[201];

void solve() {

	dp[1] = 1;
	dp[2] = N+1;
	
	for (int i = 3; i <= K; i++) {
		dp[i] = 2 * dp[i - 1];
		if (dp[i] > 1000000000) dp[i] %= 1000000000;
	}
	cout << dp[K];
}

int main() {
	cin >> N >> K;
	solve();

	return 0;
}