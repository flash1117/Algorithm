#include <iostream>
#include <vector>

using namespace std;


int N, ret, root, delNode;
vector <int> vec[51];

void solve(int depth) {

	if (vec[depth].empty()) {
		ret++;
		return;
	}

	for (int i = 0; i < vec[depth].size(); i++) {

		if(vec[depth][i] != delNode)
			solve(vec[depth][i]);
	}
}

int main() {

	int input = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input != -1) {
			vec[input].push_back(i);
		}
		else root = i;
	}
	cin >> delNode;

	solve(root);
	vec[delNode].clear();
	cout << ret << "\n";
	return 0;
}