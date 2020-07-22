#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAX = 100001;
ll ary[MAX];
ll tree[4 * MAX];

ll init(int node, int start, int end) {

	if (start == end) return tree[node] = ary[start];

	int mid = (start + end) / 2;

	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);

}

void update(int node, int start, int end, int index, ll diff) {

	if (!(start <= index && index <= end)) return;

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}

}

ll sum(int node, int start, int end, int left, int right) {

	if (right < start || end < left) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> ary[i];
	}
	init(1, 1, n);
	for (int i = 3; i <= q + 2; i++) {

		ll x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) {
			ll temp = x;
			x = y;
			y = temp;
		}

		cout << sum(1, 1, n, x, y) << "\n";

		ll diff = b - ary[a];
		ary[a] = b;
		update(1, 1, n, a, diff);
		
	}

	return 0;
}