#include <iostream>

using namespace std;

int N;
long long dp[1001][11];

void solve() {

	long long sum = 0, ret =0;
	// 1 1 1 1 1 1 1 1 1 1
	// 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1
	// 55 + 45 + 36 + 28 + 21 +15 + 10 +6 +3 + 1
	// 220 + 165 + 120 + 84 + 56 + 35 + 20 + 10 + 4 +1

	for (int i = 1; i <= 10; i++) {
		dp[1][i] = 1;
		dp[2][i] = i;
	}
		
	for (int i = 3; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= 10; j++) {
			sum += dp[i - 1][j];
			dp[i][j] = sum % 10007;
		}
	}

	for (int i = 1; i <= 10; i++) {
		ret += dp[N][i];
		if (ret > 10007) ret %= 10007;
	}

	cout << ret << "\n";
}

int main() {

	cin >> N;

	solve();


	return 0;
}