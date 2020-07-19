#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> vec[101];
bool visited[101];

int solve() {

	queue<int> q;
	int ret = 0;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {

			int next = vec[cur][i];

			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				ret++;

			}
		}

	}

	return ret;
}


int main() {

	int num, conn;
	cin >> num;
	cin >> conn;
	for (int i = 0; i < conn; i++) {

		int src, dst;
		cin >> src >> dst;
		vec[src].push_back(dst);
		vec[dst].push_back(src);

	}

	cout << solve() << "\n";

	return 0;
}