#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1000000001;
ll ary[100001];
ll tree[100001];

ll init(ll tree[], ll ary[], int node, int start, int end) {

	if (start == end) tree[node] = ary[start];

	int mid = (start + end) / 2;

	ll leftNode = init(tree, ary, node * 2, start, mid);
	ll rightNode = init(tree, ary, node * 2 + 1, mid + 1, end);

	return tree[node] = leftNode >= rightNode ? rightNode : leftNode;
}

ll getMin(ll tree[], int node, int start, int end, int left, int right) {

	if (right < start || left < end) return INF;

	if (left <= start && end <= right) return tree[node];

	if (start != end) {

		int mid = (start + end) / 2;
		ll leftNode = getMin(tree, node * 2, start, mid, left, right);
		ll rightNode = getMin(tree, node * 2 + 1, mid + 1, end, left, right);
		ll ret = leftNode >= rightNode ? rightNode : leftNode;
		return ret;
	}
}

int main() {

	int n = 1;

	while (n) {

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ary[i];
		}



	}


	return 0;
}