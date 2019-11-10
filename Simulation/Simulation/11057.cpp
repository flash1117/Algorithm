#include <iostream>

using namespace std;

int N;
long long dp[1001];

void solve() {

	dp[1] = 10;
	dp[2] = 55; // 1 ~ 9
	dp[3] = 220; // 8 ~ 1 + 7~ 1 +

	// 7 +6 + 5+ ... + 1 , 6+ 5+ 4+ 1..
	// 1 2 3 6

	int temp = 0;
	for (int i = 0; i <= 20; i++) {
		temp += i;

	}
	cout << temp;
}

int main() {

	cin >> N;

	solve();

	return 0;
}