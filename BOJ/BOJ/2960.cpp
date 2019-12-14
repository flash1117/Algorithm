#include <iostream>

using namespace std;
int N, K;

bool dp[1001];
void solve() {
	int cnt = 0;
	for (int i = 2; i <= N; i++) {

		if (!dp[i]) {
			for (int j = 1; j <= N / i; j++) {
				if (dp[i * j]) continue;
				cnt++;
				dp[i * j] = true;
				if (cnt == K) {
					cout << i * j << "\n";
					return;
				}
			}
		}
		
	}
}
int main() {
	
	cin >> N >> K;
	solve();
	return 0;
}