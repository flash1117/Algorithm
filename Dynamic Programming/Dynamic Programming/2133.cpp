#include <iostream>

using namespace std;

int N;
// 3 x N 크기의 벽을 2 x 1, 1x2 크기의 타일로 채우는 경우의 수
int dp[16];

void solve() {

	if (N % 2 == 1) {
		cout << 0 << "\n";
		return;
	}
	
	dp[1] = 3;
	dp[2] = dp[1] * dp[1] + 2;
	dp[3] = dp[2]*dp[1] + 2 * dp[1] + 2;
	dp[4] = dp[2] * dp[2] + 2 * (dp[1] * dp[1])+ 2;

	for (int i =5; i <= 15; i++) {

		if (i % 2 == 1) {

			dp[i] = dp[i / 2] * dp[i / 2 + 1] + 2 * dp[i/2-1] * dp[i/2] + 2;
		}
		else {

			dp[i] = dp[i/2] * dp[i/2] + 2*dp[i/2 - 1] * dp[i/2 - 1] + 2;
		}
	}
	N /= 2;
	cout << dp[N] << "\n";
}

int main() {

	cin >> N;
	solve();

	return 0;
}