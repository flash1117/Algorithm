#include <iostream>

using namespace std;

int N, input[1002], dp[1002];

void print() {

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
}

void solve() {

	int maxNum = 1;
	for (int i = N; i > 0; i--) {

		for (int j = i + 1; j <= N + 1; j++) {

			if (input[i] > input[j])
				dp[i] = (dp[j] + 1 > dp[i]) ? dp[j] + 1 : dp[i];
		}
		maxNum = (dp[i] > maxNum) ? dp[i] : maxNum;
	}
//	print();
	cout << maxNum;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> input[i];

	solve();

	return 0;
}