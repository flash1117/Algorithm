#include <iostream>

using namespace std;

int N, sum;
long long dp[91];

long long solve() {

	dp[1] = 1;
	dp[2] = 1; 
	dp[3] = 2; 
	dp[4] = 3; 
	dp[5] = 5; 

	long long sum = 7;
	for (int i = 6; i <= N; i++) {
		
		dp[i] = sum + 1;
		sum += dp[i - 1];
	}

	return dp[N];
}

int main() {

	cin >> N;
	cout << solve();

	return 0;
}