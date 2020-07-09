#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int hTubeSize = 100000 + 1001;

int n, k, m;
vector<int> hTube[hTubeSize];
int d[100001];

int solve() {

	int ret = 0;

	queue <int> q;
	q.push(1);
	d[1] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (cur == n) return d[n];

		for (int i = 0; i < hTube[cur].size(); i++) {

			// htube 번호 참조
			int nextHTube = hTube[cur][i];
			for (int j = 0; j < hTube[nextHTube].size(); j++) {

				if (d[hTube[nextHTube][j]] == 0) {
					d[hTube[nextHTube][j]] = d[cur] + 1;
					q.push(hTube[nextHTube][j]);

				}

			}

		}

	}

	return -1;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < k; j++) {
			int input;
			cin >> input;
			hTube[i + n + 1].push_back(input);
			hTube[input].push_back(i + n + 1);

		}

	}

	cout << solve() << "\n";

	return 0;
}