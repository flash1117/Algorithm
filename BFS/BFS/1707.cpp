#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int V, E;

vector <int> vec[20001];
bool visited[20001];


void BFS() {

	queue <int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];

			if (!visited[next]) {
				q.push(next);
				visited[next] = 1;
			}

		}
	}

	for (int i = 0; i < V; i++) {

		if (!vec[i].empty()) {
			if (!visited[i])
				cout << "Yes";
		}
	}


}

int main() {

	int T;
	int pt1, pt2;
	cin >> T;

	while (T--) {
		cin >> V >> E;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < E; i++) {
			cin >> pt1 >> pt2;
			vec[pt1].push_back(pt2);
			vec[pt2].push_back(pt1);
			
		}
		
		BFS();
		for (int i = 0; i < V; i++)
			for (int j = 0; j < vec[i].size(); j++)
				vec[i].pop_back();
	}

	return 0;
}