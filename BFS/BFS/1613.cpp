#include <iostream>

using namespace std;

int n, k;
int map[401][401];

void solve() {

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			for (int k = 1; k <= n; k++) {
				if (map[j][i] == 1 && map[i][k] == 1) map[j][k] = 1;

			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	pair <int, int> input;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> input.first >> input.second;
		map[input.first][input.second] = 1;
	}

	solve();
	
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> input.first >> input.second;
		if (map[input.first][input.second] == 0 && map[input.second][input.first] == 0)
			cout << 0 << "\n";
		else if (map[input.first][input.second] == 0 && map[input.second][input.first] == 1)
			cout << 1 << "\n";
		else if (map[input.first][input.second] == 1) cout << -1 << "\n";
	
	}

	return 0;
}