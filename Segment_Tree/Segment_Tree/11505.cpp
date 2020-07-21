#include <iostream>

using namespace std;

typedef long long ll;

ll ary[100000];
ll tree[400000];

ll init(int node, int start, int end) {
	if (start == end) return tree[node] = ary[start];

	int mid = (start + end) / 2;

	return tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end);

}

void update(int node, int start, int end, int index, double diff) {

	if (!(start <= index && index <= end)) return;

	tree[node] *= diff;


	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);

	}
	
}

ll mul(int node, int start, int end, int left, int right) {

	if (right < start && end < left) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	
	return mul(node * 2, start, mid, left, right) * mul(node * 2 + 1, mid + 1, end, left, right);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> ary[i];
	}

	init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		int od, src, dst;
		cin >> od >> src >> dst;

		if (od == 1) { // update

			double diff = dst / src;
			ary[src] = dst;
			update(1, 1, N, src, diff);

		}
		else {

			cout << mul(1, 1, N, src, dst) % 1000000007 << "\n";
		}

	}
	return 0;
}