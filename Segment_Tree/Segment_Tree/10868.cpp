#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1000000001;

ll ary[100001];
ll tree[400004];

ll MIN(ll a, ll b) {
	if (a >= b) return b;
	return a;
}

ll init(ll tree[], ll ary[], int node, int start, int end) {

	if (start == end) return tree[node] = ary[start];

	int mid = (start + end) / 2;

	ll leftNode = init(tree, ary, node * 2, start, mid);
	ll rightNode = init(tree, ary, node * 2 + 1, mid + 1, end);
	
	return tree[node] = MIN(leftNode, rightNode);

}

ll findMin(ll tree[], int node, int start, int end, int left, int right) {

	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	ll leftNode = findMin(tree, node * 2, start, mid, left, right);
	ll rightNode = findMin(tree, node * 2 + 1, mid + 1, end, left, right);
	
	return MIN(leftNode, rightNode);

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> ary[i+1];
	}

	init(tree, ary, 1, 1, N);
	for (int i = 0; i < M; i++) {

		int src, dst;
		cin >> src >> dst;
		cout << findMin(tree, 1, 1, N, src, dst) << "\n";
	}

	return 0;
}