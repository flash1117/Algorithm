#include <iostream>
#include <algorithm>

using namespace std;

int D[16], T[16], P[16];
int n, ans;

int dp(int day) {

	if (day == n + 1) return 0;
	if (day > n + 1) return -987;
	if (D[day] > 0) return D[day];

	return D[day] = max(dp(day + 1), dp(day + T[day]) + P[day]);
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> T[i] >> P[i];

	cout << dp(1);
	return 0;

}