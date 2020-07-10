#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[200][200];
int d[200];
vector <int> vec;


void solve() {

	queue <int> q;
	q.push(vec[0]);
	d[vec[0]] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			
			if (map[cur][i] == 1 && d[i] == 0)
			{
				q.push(i);
				d[i] = 1;
			}

		}

	}

	for (int i = 0; i < vec.size(); i++) {
		if (d[vec[i]] == 0) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> input;
		vec.push_back(input-1);
	}

	solve();

	return 0;
}