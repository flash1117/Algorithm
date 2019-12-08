#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
int map[20000][20000];
int visited[20000][20000];

int solve(int src, int dst) {

	if (src == dst) return 0;

	int ret = 0;
	queue <pair<int,int>> q;
	
	for (int i = 0; i < V; i++) {
		if (map[src][i] != 0) {
			q.push({ i,map[src][i] });
			visited[src][i] = map[src][i];
		}
	}
	while (!q.empty()) {

		int cur = q.front().first;
		int sum = q.front().second;
		q.pop();

		if (cur == dst) {
			if (ret == 0) ret = sum;
			else ret = ret > sum ? sum : ret;
		}

		for (int i = 0; i < V; i++) {

			if (map[cur][i] != 0 && (visited[cur][i] == 0 || visited[cur][i] > sum+map[cur][i])) {
				q.push({ i,sum + map[cur][i] });
				visited[cur][i] = sum + map[cur][i];
			}
		}


	}

	if (ret == 0) return -1;
	else return ret;
}

int main() {
	
	int u, v, w;

	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		if (map[u-1][v-1] == 0) map[u-1][v-1] = w;
		else map[u-1][v-1] = map[u-1][v-1] > w ? w : map[u-1][v-1];
	}

	for (int i = 0; i < V; i++) {
		int temp = solve(K-1, i);
		if (temp == -1) cout << "INF\n";
		else cout << temp << "\n";
	}

	return 0;
}
