#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[501][501][1001];
int N, M, U, V;
vector <pair<int, int>> vec[10001];
vector <int> ret;


int BFS() {

	queue <pair<int, int>> q;
	q.push(make_pair(U, 0));
	visited[U][U][0] = true;

	while (!q.empty()) {

		int cur = q.front().first;
		int distance = q.front().second;
		q.pop();
		
//		cout << cur << " , " << distance << endl;

		if (cur == V) {
			ret.push_back(distance);
		}
			
		for (int i = 0; i < vec[cur].size(); i++) {

			int next = vec[cur][i].first;
			int nextD = vec[cur][i].second;

			if (!visited[cur][next][nextD]) {
				visited[cur][next][nextD] = true;
				q.push(make_pair(next, distance + nextD));

			}

		}
	}

	if (ret.empty() || ret.size() == 1)
		return -1;
	else {
		sort(ret.begin(), ret.end());
		for (int i = 0; i < ret.size(); i++) {
			if (ret[i] != ret[0])
				return ret[i];
		}
		return -1;
	}
		
}

int main() {

	int start, dst, d;
	while (1) {
		memset(visited, false, sizeof(visited));

		cin >> N >> M;
		if (N == 0 && M == 0) break;

		cin >> U >> V;
		for (int i = 0; i < M; i++) {
			cin >> start >> dst >> d;
			vec[start].push_back(make_pair(dst, d));

		}

		cout << BFS() << endl;

		for (int i = 0; i < N; i++)
			vec[i].clear();
		ret.clear();

	}

	return 0;
}