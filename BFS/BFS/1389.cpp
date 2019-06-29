#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[101];
vector <int> vec[101];

typedef struct {

	int x, y;
}relp; // relationship

void BFS(int people) {

	queue <relp> q;
	q.push({people, 0});
	visited[people] = true;
	
	while (!q.empty()) {
		int cur = q.front().x;
		int ccnt = q.front().y;
		q.pop();

		if (cur == 2)
		{
			cout << "ccnt : " << ccnt << endl;

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

	for (int i = 0; i < M; i++) {

		cin >> r.x >> r.y;
		vec[r.x].push_back(r.y);
		vec[r.y].push_back(r.x);

	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		BFS(i);
	}
	

	return 0;
}