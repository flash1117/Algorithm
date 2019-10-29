#include <iostream>

using namespace std;

int N, input[1001], dp[1001];

void solve() {
	int sum = 0;

	for (int i = 1; i <= N; i++) {

		for (int j = i - 1; j >= 0; j--) {

			if (input[i] > input[j]) 
				dp[i] = (input[i] + dp[j]>dp[i])? input[i] + dp[j] : dp[i];

		}
		sum = (dp[i] > sum) ? dp[i] : sum;
	}

	cout << sum;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> input[i];
	solve();

	return 0;
}