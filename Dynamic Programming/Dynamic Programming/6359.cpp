#include <iostream>

using namespace std;

int T, N;
int dp[101];
int isOpen[101];

void solve() {

	dp[1] = 1; // 1
	for (int i = 1; i <= 100; i++)
		isOpen[i] = 1;

	for (int i = 2; i <= 100; i++) {

		for (int j = 1; j <= 100 / i; j++) {
			if (isOpen[j * i] == 0) isOpen[j * i] = 1;
			else isOpen[j * i] = 0;
		}
		dp[i] = dp[i - 1] + isOpen[i];
	}

}
int main() {

	cin >> T;
	solve();

	while (T--) {
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}