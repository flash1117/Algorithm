#include <iostream>
#include <queue>

using namespace std;

int n, k, path, minTime;
int dx[] = { -1,1 };
int d[100001];

bool isBoundary(int x) {

	if (x < 0 || x>100000) return false;
	return true;
}

void solve() {

	queue<pair<int, int>> q;
	q.push({ n,0 });

	while (!q.empty()) {


		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k) {

			minTime = cnt;
			path++;
		}

		for (int i = 0; i < 3; i++) {
			int next = 0;
			if (i == 2) next = cur * 2;
			else next = cur + dx[i];

			if (isBoundary(next) && (d[next] == 0 || d[next] >= cnt+1)) {
				q.push({ next, cnt + 1 });
				d[next] = cnt + 1;
			}


		}

	}


	return;
}

int main() {

	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n" << 1 << "\n";
		return 0;
	}

	solve();

	cout << minTime << "\n" << path << "\n";

	return 0;
}