#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int n, m;
vector<int> fri[501]; // friend
bool visited[501];

int solve() {

	int ret = 0;

	queue<pair<int, int>> q;

	visited[1] = true;
	for (int i = 0; i < fri[1].size(); i++) {
		q.push({ fri[1][i], 1 });
		visited[fri[1][i]] = true;
	
	}

	while (!q.empty()) {

		int cur = q.front().first;
		int ccnt = q.front().second;
		q.pop();

		if (ccnt < 3) ret++;

		for (int i = 0; i < fri[cur].size(); i++) {

			if (!visited[fri[cur][i]] && ccnt <= 1) {
				q.push({ fri[cur][i], ccnt + 1 });
				visited[fri[cur][i]] = true;
			}

		}

	}
	return ret;
}

int main() {

	
	int input1, input2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> input1 >> input2;
		fri[input1].push_back(input2);
		fri[input2].push_back(input1);

	}

	cout << solve() << "\n";

	return 0;
}