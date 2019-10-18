#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wine[10001];
int dp[10001];

void solve()
{
	dp[1] = wine[1];
	dp[2] = wine[2] + dp[1];

	for (int i = 3; i <= n; i++) {

		dp[i] = max(wine[i] + dp[i - 2], dp[i - 1]);
	}
	
	cout << dp[n];

}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	solve();
	return 0;
}