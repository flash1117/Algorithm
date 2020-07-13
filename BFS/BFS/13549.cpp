#include <iostream>
#include <queue>

using namespace std;

int n, k;
int dx[] = { -1,1 };
bool visited[100001];

bool isBoundary(int x) {
	if (x < 0 || x>100000) return false;
	return true;
}

int solve() {

	queue<pair<int, int>> q;
	q.push({ n,0 });

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k) return cnt;

		int next = cur * 2;
		int ncnt = cnt;
	
		if (isBoundary(next) && !visited[next]) {
			q.push({ next, ncnt });
			visited[next] = true;
		}
		
		for (int i = 0; i < 2; i++) {

			next = cur + dx[i];
			ncnt = cnt + 1;

			if (isBoundary(next) && !visited[next]) {

				q.push({ next, ncnt });
				visited[next] = true;
			}

		}

	}

	return -1;
}

int main() {

	cin >> n >> k;
	if (n == k) {
		cout << 0 << "\n";
		return 0;
	}
	cout << solve() << "\n";
	

	return 0;
}