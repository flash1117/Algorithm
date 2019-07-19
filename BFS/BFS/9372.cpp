#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
bool visited[1001];

vector <int> vec[1001];

int BFS(int pt) {
	int cnt = 0;
	queue <int> q;
	//q.push(make_pair(pt, cnt));
	q.push(pt);
	visited[pt] = true;

	while (!q.empty()) {

		int cur = q.front();
		//int ccnt = q.front().second;
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];

			if (!visited[next])
			{
				q.push(next);
				//q.push(make_pair(next, ccnt+1));
				visited[next] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

void Init(int n) {
	for (int i = 1; i <= n; i++) {
		vec[i].clear();
		visited[i] = 0;
	}
}


int main() {

	int input1, input2, ret =0;
	cin >> T;

	while (T--) {
		//memset(visited, false, sizeof(visited));
		ret = 0;
		int airplane = 0;

		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> input1 >> input2;
			vec[input1].push_back(input2);
			vec[input2].push_back(input1);
		}

		cout << BFS(1) << endl;
		Init(N);
	}
	return 0;
}