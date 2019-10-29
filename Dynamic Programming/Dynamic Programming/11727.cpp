#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[1001];

void solve() {

	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	dp[4] = 11;

	for (int i = 5; i <= n; i++) {
		int index = i / 2;
		if (i % 2 == 0)
			dp[i] = dp[index] * dp[index] + 2 * dp[index - 1] * dp[index - 1];
		else
			dp[i] = dp[index] * dp[index + 1] + 2 * dp[index - 1] * dp[index];

		if (dp[i] > 10007) dp[i] %= 10007;
	}

	cout << dp[n];

}

int main() {

	cin >> n;
	solve();

	return 0;
}
