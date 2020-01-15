#include <iostream>

using namespace std;

int N;
int dp[1000001];

// 10 - 10
// 11 - 20
// 12 - 21
// 13 - 30
// 14 - 31
// 15 - 32
// 16 - 

void solve() {

	int index = 1;
	for (int i = 1; i <= 1000000; i++) {

		bool isDecrease = true;
		int temp = i, prev = -1;
		while (temp != 0) {

			if (temp % 10 <= prev) {
				isDecrease = false;
				break;
			}
			prev = temp % 10;
			temp /= 10;

		}

		if (isDecrease) dp[index++] = i;
		if (index == N + 1) return;
	}

}

int main() {

	cin >> N;
	solve();
	cout << dp[N] << "\n";


	return 0;
}