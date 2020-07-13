#include <iostream>
#include  <queue>

using namespace std;

bool visited[100001];
int prevNode[100001];
vector<int> path;

int n, k;
int dx[] = { -1,1 };

bool isBoundary(int x) {
	if (x < 0 || x>100000) return false;
	return true;
}


void solve() {

	queue <int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();


		if (cur == k) {
			path.push_back(cur);
			while (cur != n) {

				cur = prevNode[cur];
				path.push_back(cur);

			}
			return;
		}


		for (int i = 0; i < 3; i++) {

			int next = 0;
			if (i == 2) next = cur * 2;
			else next = cur + dx[i];

			if (isBoundary(next) && !visited[next]) {

				q.push(next);
				visited[next] = true;
				prevNode[next] = cur;
			}



		}




	}


}


int main() {

	cin >> n >> k;
	
	solve();
	cout << path.size() - 1 << "\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	
	return 0;
}