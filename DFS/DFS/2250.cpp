#include <iostream>
#include <vector>

using namespace std;

int N, cnt =0;
int maxDepth;
bool visited[10001];
vector <int> vec[10001];
vector <int> relp[10001];

void DFS(int node,  int depth) {

	if (node == -1) return;

	for (int i = 0; i < 2; i++) {

		DFS(vec[node][i], depth + 1);
		if (!visited[node]) {
			if (maxDepth < depth) maxDepth = depth;
			relp[cnt++].push_back(depth);
			visited[node] = true;
		}
	}
}

int main() {

	int parent, l, r, depth=0, wide =0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent >> l >> r;
		vec[parent].push_back(l);
		vec[parent].push_back(r);

	}
	DFS(1, 1);

	for (int i = 2; i <= maxDepth; i++) {
		int start = 0, dst = 0;
		bool isCheck = false;
		for (int j = 0; j < cnt; j++) {

			if (!isCheck && relp[j][0] == i) {
				isCheck = true;
				start = j;
			}
			else if (relp[j][0] == i)
				dst = j;
		}
		if ((dst - start) > wide) { 
			wide = (dst - start); 
			depth = i;
		}
	}

	cout << depth << " " << wide+1;
	return 0;
}
