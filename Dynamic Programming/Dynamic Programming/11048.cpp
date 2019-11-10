#include <iostream>

using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001];

void solve() {

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j]+map[i][j] : dp[i][j - 1]+map[i][j];
		
	cout << dp[N][M] << "\n";

}

int main() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> map[i][j];
	
	solve();
	return 0;
}