#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, maxW=0;
int start, dst;
int visited[10001];

vector <pair<int, int>> vec[100001];

void BFS(int src) {

	queue <pair<int, int>> q;
	for (int i = 0; i < vec[src].size(); i++) {
		q.push({ vec[src][i].first, vec[src][i].second });
		visited[vec[src][i].first] = vec[src][i].second;
	}

	while (!q.empty()) {

		int cur = q.front().first;
		int curW = q.front().second;
		q.pop();

		if (cur == dst) {
			if (curW > maxW) maxW = curW;
		}
		else
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextW = vec[cur][i].second;

			if (visited[next]<curW)
			{
				int mm = min(nextW, curW);
				q.push({ next,mm });
				visited[next] = curW;
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