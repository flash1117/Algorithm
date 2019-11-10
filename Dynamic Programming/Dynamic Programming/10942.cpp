#pragma warning (disable:4996)
#include <iostream>

using namespace std;

#define Endl "\n"

int N, M;
int map[2001];
pair <int,int> question[1000001];
bool dp[2001][2001];

void solve() {

	for (int i = 1; i <= N; i++) {

		for (int j = i; j > 0; j--) {

		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> map[i];
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> question[i].first >> question[i].second;
	
	solve();

	return 0;
}