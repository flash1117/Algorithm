#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector <int> vec[100001];
int parent_node[100001];
bool visited[100001];

void findParent() {

	queue <int> q;
	for (int i = 0; i < vec[1].size(); i++) {
		parent_node[vec[1][i]] = 1;
		q.push(vec[1][i]);
		visited[1] = true;
	}

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {

			if (!visited[vec[cur][i]]) {
				q.push(vec[cur][i]);
				visited[vec[cur][i]] = true;
				parent_node[vec[cur][i]] = cur;
			}
		}

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int src, dst;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> src >> dst;
		vec[src].push_back(dst);
		vec[dst].push_back(src);

	}

	findParent();

	for (int i = 2; i < n; i++) {
		cout << parent_node[i] << "\n";
	}

	return 0;
}