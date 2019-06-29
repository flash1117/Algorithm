#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[101];
vector <int> vec[101];
vector <int> ret[101];

typedef struct {

	int x, y;
}relp; // relationship

int BFS(int people, int goal) {

	queue <relp> q;
	q.push({people, 0});
	visited[people] = true;
	
	while (!q.empty()) {
		int cur = q.front().x;
		int ccnt = q.front().y;
		q.pop();

		if (cur == goal)
		{
			return ccnt;
		}

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];

			if (!visited[next])
			{
				q.push({ next, ccnt + 1 });
				visited[next] = true;
			}

		}

	}

}

int main() {

	cin >> N >> M;
	relp r;
	int sum[101] = {0,}, BOJ;

	for (int i = 0; i < M; i++) {

		cin >> r.x >> r.y;
		vec[r.x].push_back(r.y);
		vec[r.y].push_back(r.x);

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			memset(visited, false, sizeof(visited));
			sum[i] += BFS(i,j);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (sum[i] != 0) {
			if (sum[i - 1] > sum[i])
				BOJ = i;
		}
	}

	cout << BOJ;
	return 0;
}