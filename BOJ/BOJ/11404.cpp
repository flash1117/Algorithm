#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int x, y, sum;
}pos;
int n, m;
int cost[100][100];

void solve() {

	for (int mid = 0; mid < n; mid++) {
		for (int i = 0; i < n; i++) {

			if (cost[i][mid] == 0) continue;

			for (int j = 0; j < n; j++) {

				if (cost[mid][j] == 0 || i == j) continue;

				if (cost[i][j] == 0) cost[i][j] = cost[i][mid] + cost[mid][j];
				else cost[i][j] = cost[i][j] > cost[i][mid] + cost[mid][j] ? cost[i][mid] + cost[mid][j] : cost[i][j];
			}
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	int src = 0, dst = 0, busCost = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {

		cin >> src >> dst >> busCost;
		if(cost[src-1][dst-1] == 0)
			cost[src - 1][dst - 1] = busCost;
		else
			cost[src - 1][dst - 1] = cost[src - 1][dst - 1] > busCost ? busCost : cost[src - 1][dst - 1];

	}
	solve();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cost[i][j] << " ";

		}
		cout << "\n";
	}
	

	return 0;
}
