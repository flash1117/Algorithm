#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int parent[101];
int child[101];
bool visited[101];
vector <int> ret;

void isUnion(int src, int dst) {

	bool cycle[101];
	for (int i = 1; i <= N; i++) cycle[i] = false;
	vector<int> footPrint;
	queue <int> q;
	q.push(src);
	footPrint.push_back(src);
	cycle[src] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		int next = child[cur];

		if (next == src) {
			for (int i = 0; i < footPrint.size(); i++) {
				visited[footPrint[i]] = true;
				ret.push_back(footPrint[i]);
			}
		}

		if (!cycle[next]) {
			q.push(next);
			cycle[next] = true;
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		child[i] = input;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) isUnion(i, child[i]);
	}

	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int i = 0; i < ret.size(); i++) cout << ret[i] << "\n";

	return 0;
}