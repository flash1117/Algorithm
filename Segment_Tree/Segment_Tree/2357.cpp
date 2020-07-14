#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MAX_VALUE = 1000000001;
const ll MIN_VALUE = 0;

ll minTree(vector<ll>& min_tree, vector<ll>& ary, int node, int start, int end) {

	if (start == end) return min_tree[node] = ary[start];

	int mid = (start + end) / 2;

	ll leftNode = minTree(min_tree, ary, node * 2, start, mid);
	ll rightNode = minTree(min_tree, ary, node * 2 + 1, mid + 1, end);

	return min_tree[node] = leftNode >= rightNode ? rightNode : leftNode;
		
}

ll maxTree(vector<ll>& max_tree, vector<ll>& ary, int node, int start, int end) {

	if (start == end) return max_tree[node] = ary[start];

	int mid = (start + end) / 2;

	ll leftNode = maxTree(max_tree, ary, node * 2, start, mid);
	ll rightNode = maxTree(max_tree, ary, node * 2 + 1, mid + 1, end);

	return max_tree[node] = leftNode >= rightNode ? leftNode : rightNode;

}

ll findMin(vector<ll>& tree, int node, int start, int end, int left, int right) {

	if (start > right || end < left) return MAX_VALUE;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	ll leftNode = findMin(tree, node * 2, start, mid, left, right);
	ll rightNode = findMin(tree, node * 2 + 1, mid + 1, end, left, right);
	ll ret = leftNode >= rightNode ? rightNode : leftNode;
	return ret;

}

ll findMax(vector<ll>& tree, int node, int start, int end, int left, int right) {

	if (start > right || end < left) return MIN_VALUE;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	ll leftNode = findMax(tree, node * 2, start, mid, left, right);
	ll rightNode = findMax(tree, node * 2 + 1, mid + 1, end, left, right);
	ll ret = leftNode >= rightNode ? leftNode : rightNode;
	return ret;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	vector <ll> tree, tree2 ,ary;
	ary.reserve(N + 1);
	tree.reserve(4 * (N + 1));
	tree2.reserve(4 * (N + 1));

	ary.push_back(0);
	for (int i = 0; i < 4 * (N + 1); i++) {
		tree.push_back(0);
		tree2.push_back(0);
	}

	for (int i = 0; i < N; i++) {
		ll input;
		cin >> input;
		ary.push_back(input);
	}

	minTree(tree, ary, 1, 1, N);
	maxTree(tree2, ary, 1, 1, N);

	for (int i = 0; i < M; i++) {
		int left, right;
		cin >> left >> right;

		cout << findMin(tree, 1, 1, N, left, right) <<" "<< findMax(tree2, 1,1,N,left,right) << "\n";
	}


	return 0;
}