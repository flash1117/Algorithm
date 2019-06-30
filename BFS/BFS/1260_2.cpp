#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector <int> vec[1001];
bool visited[1001];

void BFS() {

	memset(visited, false, sizeof(visited));
	queue <int> q;
	q.push(V);
	visited[V] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < N; i++) {
			int next = vec[cur][i];

			
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		
			if (i == vec[cur].size() - 1)
				break;

		}
	}
}

void DFS(int start) {

	
}

int main() {

	int x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);

	}

	memset(visited, false, sizeof(visited));
	DFS(V);
	BFS();

	return 0;
}