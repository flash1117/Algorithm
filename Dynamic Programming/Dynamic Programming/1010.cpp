#include <iostream>

using namespace std;

#define Endl "\n"

int T, src, dst;
int dp[31][31];

void print() {

	for (int i = 0; i <= 30; i++) {

		for (int j = 0; j <= i; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {

	for (int i = 0; i <= 30; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i/2+1; j++) {

			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][i - j] = dp[i][j];

		}
	}
		

}

int main() {

	cin >> T;
	solve();
	while (T--) {

		cin >> src >> dst;
		printf("%d\n", dp[dst][src]);
	}


	return 0;
}