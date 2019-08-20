#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1001];

void solve() {

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3; // 2 x 1 + 1
	dp[3] = 5; // 2x2 + 1
	dp[4] = 8; 
	for (int i = 5; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 10007)
			dp[i] = dp[i] % 10007;
	}

}

int main() {

	cin >> n;
	solve();

	cout << dp[n - 1];

	return 0;
}