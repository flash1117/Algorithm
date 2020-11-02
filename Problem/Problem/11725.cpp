#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector <int> graph[100001];
int _tree[100001];

void makeTree() {

	queue<int> q;
	q.push(1);
	_tree[1] = -1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int nextNode = graph[cur][i];

			if (_tree[nextNode] == 0) {
				q.push(nextNode);
				_tree[nextNode] = cur;
			}

		}

	}

}


void printTree() {

	for (int i = 2; i <= N; i++) {

		cout << _tree[i] << "\n";

	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N-1; i++) {

		int src, dst;
		cin >> src >> dst;
		
		graph[src].push_back(dst);
		graph[dst].push_back(src);

	}
	makeTree();
	printTree();

	return 0;
}