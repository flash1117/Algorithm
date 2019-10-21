#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];

void solve() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	dp[5] = 8;

	for (int i = 6; i <= n; i++) 
		dp[i] = dp[i - 2] + dp[i - 1];
	
	cout << dp[n] % 10007;
	
}

int main() {

	cin >> n;
	solve();

	return 0;
}
