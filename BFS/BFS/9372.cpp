#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, N, M;
bool visited[1001];

vector <int> vec[10001];

int BFS(int pt) {
	int cnt = 1;
	queue <pair<int,int>> q;
	q.push(make_pair(pt, cnt));
	visited[pt] = true;

	while (!q.empty()) {

		int cur = q.front().first;
		int ccnt = q.front().second;
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i];

			if (!visited[next])
			{
				q.push(make_pair(next, ccnt+1));
				visited[next] = true;
			}
		}
		cnt = ccnt;
	}

	return cnt;
}


int main() {

	int input1, input2, area = 0, ret =0;
	cin >> T;

	while (T--) {
		memset(visited, false, sizeof(visited));
		ret = 0;

		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> input1 >> input2;
			vec[input1].push_back(input2);
			vec[input2].push_back(input1);
		}

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i]) {
				ret += BFS(i);
			}
				
		}
		cout << ret << endl;
	}
	return 0;
}