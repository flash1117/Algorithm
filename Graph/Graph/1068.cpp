#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, delNode, root;
vector <int> vec[51];

int solve() {

	queue <int> q;
	int cnt = 0;
	if (vec[root].empty() || (vec[root].size() == 1 && vec[root][0] == delNode)) cnt++;
	for (int i = 0; i < vec[root].size(); i++) {
		
		if (vec[root][i] != delNode) q.push(vec[root][i]);
	}

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (vec[cur].empty()) {
			cnt++;
			continue;
		}

		for (int i = 0; i < vec[cur].size(); i++) {
			
			if (vec[cur][i] != delNode) q.push(vec[cur][i]);
			
		}
	}
	return cnt;
}


int main() {

	int input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == -1) root = i;
		else vec[input].push_back(i);
	}
	cin >> delNode;
	vec[delNode].clear();

	cout << solve() << "\n";

	return 0;
}