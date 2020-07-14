#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
// const ll MAX_SIZE = 1000001;

ll init(vector <ll> &tree , vector<ll> &ary, int node, int start, int end) { // seg tree ����

	if (start == end) return tree[node] = ary[start]; // leaf node

	int mid = (start + end) / 2;

	return tree[node] = init(tree, ary, node * 2, start, mid) + init(tree, ary, node * 2 + 1, mid + 1, end);


}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) { // diff ��ŭ �ٸ� �� seg_tree update

	if (!(start <= index && index <= end)) return; // start �� end ���̿� �ٲٰ��� �ϴ� index ��ȣ�� ������ return


	tree[node] += diff;

	if (start != end) { // leaf node�� �ƴ� ���
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2+1, mid+1, end, index, diff);
	}

	return;
}

ll sum(vector <ll> &tree, int node , int start ,int end, int left , int right) { // left ���� right ������ �κ���

	if (right < start || end < left) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<ll> ary, tree;
	ary.reserve(N+1);
	tree.reserve(4*(N + 1));
	ary.push_back(0);

	for (int i = 0; i < 4 * (N + 1); i++) tree.push_back(0); // �ʱ�ȭ

	for (int i = 1; i <= N; i++) {
		ll input;
		cin >> input;
		ary.push_back(input);
	}

	init(tree, ary, 1, 1, N); // seg tree ����

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) //  b��° ���� c�� update
		{
			ll diff = c - ary[b];
			ary[b] = c;
			update(tree, 1, 1, N, b, diff);
		}
		else { // b��°���� c��°���� �κ��� ��� 
			cout << sum(tree, 1, 1, N, b, c) << "\n";
		}
	}
	
	return 0;
}