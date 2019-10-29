#include <iostream>
#include <algorithm>

using namespace std;

int n;
int input[1001];
int dp[1001];
int maxLen;

void solve() {

	dp[1] = 1;
	dp[2] = (input[2] > input[1]) ? 2 : 1;

	maxLen = (n >= 2) ? dp[2] : dp[1];

	for (int i = 3; i <= n; i++) {

		for (int j = i - 1; j >= 0; j--) {

			if (input[i] > input[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		maxLen = (dp[i] > maxLen) ? dp[i] : maxLen;
	}

	cout << maxLen;

}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> input[i];

	solve();


	return 0;
}