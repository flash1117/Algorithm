#include <iostream>
#include <algorithm>

using namespace std;

int dp[12];

void DP() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++) {

		if (i - 1 >= 0)
			dp[i] += dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += dp[i - 2];
		if (i - 3 >= 0)
			dp[i] += dp[i - 3];

	}

}

int main() {

	int T, input;
	cin >> T;

	DP();

	while (T--) {
		cin >> input;

		cout << dp[input] << endl;
	}

	return 0;
}