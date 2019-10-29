#include <iostream>

using namespace std;

#define Endl "\n"

int T, N;
long long dp[101];

void solve() {

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 100; i++) 
		dp[i] = dp[i - 2] + dp[i - 3];

}

int main() {

	cin >> T;
	solve();
	while (T--) {

		cin >> N;
		cout << dp[N] << Endl;
		
	}

	return 0;
}