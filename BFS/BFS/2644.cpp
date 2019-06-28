#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int src, dst;
int parent, child;
bool visited[101];
int cnt = 0;

vector <int> vec[101];

void BFS() {

	queue <pair<int,int>> q;
	q.push({ src, 0 });
	visited[src] = true;

	for (int i = 0; i < N; i++) {
		int cur = q.front().first;
		int ccnt = q.front().second;
		q.pop();

		if (cur == dst)
			cnt = ccnt;

		for (int j = 0; j < vec[cur].size(); j++) {
			int next = vec[cur][j];
			if (!visited[next]) {
				q.push({ next, ccnt + 1 });
				visited[cur] = true;
			}
				
		}

	}

}

int main() {

	memset(visited, 0, sizeof(visited));
	cin >> N;
	cin >> src >> dst;
	cin >> M;

	for (int i = 0; i < M; i++) {

		cin >> parent >> child;
		vec[parent].push_back(child);
		vec[child].push_back(parent);

	}

	BFS();

	if (cnt == 0)
		cout << "-1";
	else
		cout << cnt;

	return 0;
}