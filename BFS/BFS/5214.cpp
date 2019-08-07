#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M, K;
vector <int> vec[100001];
bool visited[100001];

int BFS() {

	queue <pair<int,int>> q;
	q.push(make_pair(1,0));
	visited[1] = true;

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == N)
			return cnt + 1;

		for (int i = 0; i < vec[cur].size(); i++) {

			int next = vec[cur][i];
			
				if (!visited[next]) {

					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
		}
	}

	return -1;
}


int main() {

	int input[1001];
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {

		for (int j = 0; j < K; j++) {
			cin >> input[j];
		}
	
		for (int j = 0; j < K; j++) {
			for (int k = j+1; k < K; k++) {
				vec[input[j]].push_back(input[k]);
			}
		}
	
	}

	cout << BFS();
	return 0;
}