#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

vector <int> vec[1001];
bool visited[1001];

void DFS(int pt) {

	if (visited[pt]) return;
	else {
		if (pt == 0) return;
		else {
			cout << pt << " ";
			visited[pt] = true;
			for (int i = 0; i < vec[pt].size(); i++) {
				DFS(vec[pt][i]);

			}
				
		}
		
	}
}

void BFS(int pt) {

	queue <int> q;
	q.push(pt);
	visited[pt] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
			
		}

	}
}

int main() {

	memset(visited, false, sizeof(visited));
	int start, end;
	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {

		cin >> start >> end;
		vec[start].push_back(end);
		vec[end].push_back(start);

	}

	for (int i = 1; i <= N; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	DFS(V);
	cout << endl;
	memset(visited, false, sizeof(visited));
	BFS(V);

	return 0;
	
}