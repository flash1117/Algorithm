#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, maxD;
int d[20001];
vector<int> vec[20001];

void solve() {

	queue <pair<int, int>> q;
	d[1] = -1;
	for (int i = 0; i < vec[1].size(); i++) {

		q.push({ vec[1][i], 1 });
		d[vec[1][i]] = 1;
	}

	while (!q.empty()) {

		int cur = q.front().first;
		int ccnt = q.front().second;
		q.pop();

		maxD = ccnt > maxD ? ccnt : maxD;

		for (int i = 0; i < vec[cur].size(); i++) {

			if (d[vec[cur][i]] == 0 || ccnt+1 < d[vec[cur][i]]) {

				q.push({ vec[cur][i], ccnt + 1 });
				d[vec[cur][i]] = ccnt + 1;
			}
		}

	}
	vector<int> pos;
	for (int i = 1; i <= N; i++) {
		if (maxD == d[i]) pos.push_back(i);
	}

	cout << pos[0] << " " << maxD << " " << pos.size() << "\n";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		vec[input1].push_back(input2);
		vec[input2].push_back(input1);
	}

	solve();

	return 0;
}