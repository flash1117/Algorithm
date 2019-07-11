#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, max_cnt =0;
bool visited[10001];

vector <int> relp[10001];
vector <int> ret;

void BFS(int pt) {
	
	queue <pair<int,int>> q;
	q.push({ pt, 0 });
	visited[pt] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int ccnt = q.front().second;
		q.pop();

		if (ccnt > max_cnt) max_cnt = ccnt;

		for (int i = 0; i < relp[cur].size(); i++) {

			int next = relp[cur][i];
			if (!visited[next]) {
				q.push({ next, ccnt + 1 });
				visited[next] = true;
			}
			
		}

	}
}

int main() {

	int victim, host;
	int temp = max_cnt;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {

		cin >> victim >> host;
		relp[host].push_back(victim);
	}


	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (max_cnt > temp)temp = max_cnt;
		max_cnt = 0;
		BFS(i);
		if (max_cnt > temp) {

			while (!ret.empty()) 
				ret.pop_back();
			ret.push_back(i);
		}
		else if (max_cnt == temp) {
			ret.push_back(i);
		}

	}

	sort(ret.begin(), ret.end());

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}

	return 0;
}