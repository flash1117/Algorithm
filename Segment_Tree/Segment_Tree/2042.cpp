#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
// const ll MAX_SIZE = 1000001;

ll init(vector <ll> &tree , vector<ll> &ary, int node, int start, int end) { // seg tree 생성

	if (start == end) return tree[node] = ary[start]; // leaf node

	int mid = (start + end) / 2;

	return tree[node] = init(tree, ary, node * 2, start, mid) + init(tree, ary, node * 2 + 1, mid + 1, end);


}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) { // diff 만큼 다른 걸 seg_tree update

	if (!(start <= index && index <= end)) return; // start 와 end 사이에 바꾸고자 하는 index 번호가 없으면 return


	tree[node] += diff;

	if (start != end) { // leaf node가 아닌 경우
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2+1, mid+1, end, index, diff);
	}

	return;
}

ll sum(vector <ll> &tree, int node , int start ,int end, int left , int right) { // left 부터 right 까지의 부분합

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

	for (int i = 0; i < 4 * (N + 1); i++) tree.push_back(0); // 초기화

	for (int i = 1; i <= N; i++) {
		ll input;
		cin >> input;
		ary.push_back(input);
	}

	init(tree, ary, 1, 1, N); // seg tree 생성

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) //  b번째 수를 c로 update
		{
			ll diff = c - ary[b];
			ary[b] = c;
			update(tree, 1, 1, N, b, diff);
		}
		else { // b번째부터 c번째까지 부분합 출력 
			cout << sum(tree, 1, 1, N, b, c) << "\n";
		}
	}
	
	return 0;
}