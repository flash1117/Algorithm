#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int minR=0;
vector <int> v[101];
bool visited[101];
vector<int> ans;

int BFS(int start) {
	queue<pair<int,int>> q;
	q.push({ start,1 });
	visited[start] = 1;
	int total_cnt = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]]) {
				q.push({ v[now][i],cnt + 1 });
				visited[v[now][i]] = 1;
				total_cnt += cnt;
			}
		}
	}
	return total_cnt;
}

void Init() {
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}

int main() {
	int f1, f2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> f1 >> f2;
		v[f1].push_back(f2);
		v[f2].push_back(f1);
	}
	for (int i = 1; i <= N; i++) {
		ans.push_back(BFS(i));
		Init();
	}
	for (int i = 1; i < N; i++)
		if (ans[minR] > ans[i]) minR = i;
	cout << minR+1;

	return 0;
}