#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int visited[1001];
vector<int> vert[1001];	// 간선의 존재여부를 확인하기위한 벡터

void BFS(int u) {

	queue<int> q;
	q.push(u);
	visited[u] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < vert[cur].size(); i++) {
			int nextPoint = vert[cur][i];
			if (!visited[nextPoint]) {
				q.push(nextPoint);
				visited[nextPoint] = 1;
			}
		}			
		
	}
}


int main() {
	cin >> N >> M;
	int u, v, cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		vert[u].push_back(v);
		vert[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}