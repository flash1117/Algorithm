#include <iostream>

using namespace std;

int N;
int dp[100001];

void solve() {

	dp[1] = 1;

	for (int i = 1; i <= N; i++) {
		
		for (int j = i/2; j > 0; j--) {
			int temp = j * j;
			if (i >= temp && temp >0)
			{
				if (dp[i] == 0) dp[i] = dp[i - temp] + 1;
				else dp[i] = (dp[i - temp] + 1 > dp[i]) ? dp[i] : dp[i - temp] + 1;
			}
		}
	}
	cout << dp[N] << "\n";
}

int main() {
	cin >> N;
	solve();
	return 0;
}