#include <iostream>

using namespace std;

#define Endl "\n"

typedef struct {

	int x, y;
}Point;

Point src, dst;
int N, M, K;
int map[302][302];
int dp[302][302];

void solve() {
	
	if (src.x == dst.x && src.y == dst.y)
	{
		cout << map[dst.x][dst.y] << Endl;
		return;
	}
	else {
		cout << dp[dst.x][dst.y] - dp[src.x-1][dst.y] - dp[dst.x][src.y-1] + dp[src.x-1][src.y-1] << Endl;
	}
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + map[i][j];
		}
	}
	
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> src.x >> src.y >> dst.x >> dst.y;
		solve();
	}
	return 0;
}