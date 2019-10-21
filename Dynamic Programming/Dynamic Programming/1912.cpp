#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[100001];
int dp[100001];

void solve() {

	int isSumMinus = num[0];
	dp[0] = num[0];

	for (int i = 1; i < n; i++) {

		isSumMinus += num[i];
	
		if(num[i] > isSumMinus && isSumMinus <0) dp[i] = max(dp[i - 1], num[i]);
		else dp[i] = max(dp[i - 1], isSumMinus);
		if (isSumMinus < 0) isSumMinus = 0;
		
	}

	cout << dp[n - 1];
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	
	solve();

	return 0;
}