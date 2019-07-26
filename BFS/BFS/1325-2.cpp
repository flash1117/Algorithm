#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v[10001];
bool visited[10001];
vector<int> ans[10001];
int maxhack = 0;

int BFS(int n) {
	queue <int> q;
	q.push(n);
	int cnt = 0;
	visited[n] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]]) {
				q.push(v[now][i]);
				visited[v[now][i]]=1;
			}
		}
	}
	return cnt;
}

void Init() {
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}


int main() {
	int c1, c2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2;
		v[c2].push_back(c1);
	}
	for (int i = 1; i <= N; i++) {
		int val = BFS(i);
		ans[val].push_back(i);
		maxhack = max(maxhack, val);
		Init();
	}
	sort(ans[maxhack].begin(), ans[maxhack].end());
	
	for (int i = 0; i < ans[maxhack].size(); i++)
		cout << ans[maxhack][i] << " ";

	return 0;
}