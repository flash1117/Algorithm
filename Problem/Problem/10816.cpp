#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cardCount;
vector<int> src, dst;

void bSearchTree(int start, int end, int goal) {

	if (start > end) return;
	else if (src[start] == src[end] && src[start] == goal) {

		cardCount += end - start + 1;
		return;
	}

	if (goal < src[start]) return;
	if (src[end] < goal) return;

	int mid = (start + end) / 2;

	bSearchTree(start, mid, goal);
	bSearchTree(mid + 1, end, goal);

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		src.push_back(input);
	}

	sort(src.begin(), src.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		cardCount = 0;

		bSearchTree(0, src.size() - 1, input);
		cout << cardCount << " ";
	}
	cout << "\n";

	return 0;
}