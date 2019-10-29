#include <iostream>

using namespace std;

int N;
int input[1001];
int dp[1001];

void solve() {

	dp[1] = input[1];
	dp[2] = (2 * input[1] > input[2]) ? 2 * input[1] : input[2];

	for (int i = 3; i <= N; i++) {

		for (int j = i; j >= 0; j--) 
			dp[i] = (dp[i - j] + input[j] > dp[i]) ? dp[i - j] + input[j] : dp[i];
		

	}

	cout << dp[N];
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> input[i];

	solve();

	return 0;
}