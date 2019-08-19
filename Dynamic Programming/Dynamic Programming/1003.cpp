#include <iostream>
#include <cstring>

using namespace std;

#define Endl "\n"

pair<int,int> dp[41];
int N;

void solve() {

	dp[0] = make_pair(0,1);
	dp[1] = make_pair(1,0);
	dp[2] = { dp[0].first + dp[1].first , dp[0].second + dp[1].second };

	for (int i = 3; i <= N; i++) {

		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}



}


int main() {

	int T;
	cin >> T;
	while (T--) {

		cin >> N;

		solve();
		cout << dp[N].second << " " << dp[N].first << Endl;
		memset(dp, 0, sizeof(dp));
	}


}