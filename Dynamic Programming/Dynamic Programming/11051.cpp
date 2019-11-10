#include <iostream>

using namespace std;
int N, K;

// 이항 계수를 구하는 문제. (조합)
int dp[1001][1001];


void solve() {

	if (K == 1 || N == K) {
		cout << 1 << "\n";
		return;
	}
	
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;

		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] > 10007) dp[i][j] %= 10007;
		}
	}

	cout << dp[N][K] << "\n";
}

int main() {

	cin >> N >> K;

	solve();
	return 0;
}