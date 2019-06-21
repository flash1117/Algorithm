#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int map[1001][1001];
bool visited[1001][1001];

void BFS(int x) {

	queue <int> q;

	for (int i = 0; i < N; i++) {

		if (map[x][i])
			q.push(i);
	}

	while (!q.empty()) {



	}


}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	int u, v;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {

		cin >> u >> v;
		map[u - 1][v - 1] = 1;

	}

	for (int i = 0; i < N; i++)
		BFS(i);


	return 0;
}