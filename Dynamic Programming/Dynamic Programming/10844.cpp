#include <iostream>
#include <algorithm>

#define MAX_BOUND 1000000000

using namespace std;

int N;
long long dp[101];

void solve() {

	bool state = false;
	long long tmp = 0;
	dp[1] = 9;
	dp[2] = 17;

	for (int i = 3; i <= N; i++) {

		if(!state)
			dp[i] = 2 * (dp[i - 1] - dp[i - 2]) - 1 + dp[i - 1];
		else {
			dp[i] = 2 * (tmp - dp[i - 2]) - 1 + tmp;
			state = false;
		}

		if (dp[i] > MAX_BOUND) {
			tmp = dp[i];
			dp[i] %= MAX_BOUND;
			state = true;
		}
	}

	cout << dp[N];
}

int main() {

	cin >> N;
	solve();

	return 0;
}