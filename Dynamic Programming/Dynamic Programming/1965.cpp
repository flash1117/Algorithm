#include <iostream>

using namespace std;

int N, maxNum;
int input[1001];
int dp[1001];

void solve() {

	for (int i = 1; i <= N; i++) {
		for (int j = i-1; j >= 0; j--) {

			if (input[i] > input[j])
				dp[i] = (dp[j] + 1 > dp[i]) ? dp[j] + 1 : dp[i];

		}
		maxNum = (dp[i] > maxNum) ? dp[i] : maxNum;
	}
	cout << maxNum << "\n";
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	solve();

	return 0;
}