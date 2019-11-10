#include <iostream>
#include <string>

using namespace std;

string input1, input2;
int dp[1001][1001];

void solve() {

	int input1Len = input1.length();
	int input2Len = input2.length();

	for (int i = 0; i < input1Len; i++) {
		if (input1[i] == input2[0])
			dp[i][0] = 1;
	}

	for (int i = 0; i < input2Len; i++) {
		if (input2[i] == input1[0])
			dp[0][i] = 1;
	}

	for (int i = 1; i < input1Len; i++) {
		for (int j = 1; j < input2Len; j++) {
			dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
			if (input1[i] == input2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1 > dp[i][j] ? dp[i - 1][j - 1] + 1: dp[i][j];
				continue;
			}
			
		}
	}
	
	cout << dp[input1Len - 1][input2Len - 1]+1 << "\n";
}

int main() {

	cin >> input1 >> input2;
	solve();

	return 0;
}