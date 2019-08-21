#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[100];

void solve() {

	dp[0] = 1; // Á¸Àç X
	dp[1] = 1; // 1
	dp[2] = 1; // 10
	dp[3] = 2; // 100 , 101
	dp[4] = 3;	// 1000 1001 1010 
	dp[5] = 5;	// 10000 10001 10010 10100 10101
	dp[6] = 8;	// 100000 100001 100010 100100 100101 101000 101001 101010
	dp[7] = 13;	// 1000000 1000001 1000010 1000100 1000101 1001000 1001001 1001010 1010000 1010001 1010010 1010100 1010101

	for (int i = 8; i <= N; i++) {

		int sum = 0;
		for (int j = 0; j < i - 1; j++) 
			sum += dp[j];
		
		dp[i] = sum;
	}
}


int main() {

	cin >> N;
	solve();

	cout << dp[N];

	return 0;
}