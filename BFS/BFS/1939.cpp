#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, maxW=0;
int start, dst;
bool visited[10001][10001];

vector <pair<int, int>> vec[10001];

void BFS(int src) {

	queue <pair<int, int>> q;
	for (int i = 0; i < vec[src].size(); i++) {
		q.push({ vec[src][i].first, vec[src][i].second });
		visited[vec[src][i].first][vec[src][i].second] = true;
	}

	while (!q.empty()) {

		int cur = q.front().first;
		int curW = q.front().second;
		q.pop();

		if (cur == dst)
			if (curW > maxW) maxW = curW;

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextW = vec[cur][i].second;

			if (!visited[next][nextW])
			{
				if (curW >= nextW) {
					q.push({ next,nextW });
				}
				else if (curW < nextW)
					q.push({ next, curW });
				
				visited[next][nextW] = true;
			}
		}
	}
}


int main() {
	int n1, n2, weight;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		
		cin >> n1 >> n2 >> weight;
		vec[n1].push_back({ n2,weight });
		vec[n2].push_back({ n1,weight });

	}
	cin >> start >> dst;

	BFS(start);
	cout << maxW;
	return 0;
}