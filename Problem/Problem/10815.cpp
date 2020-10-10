#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> card;

int isExist(int start ,int end, int index) {

	if (start == end) {
		if (card[start] == index) return 1;
		else return 0;
	}
	else if (index < card[start]) return 0;
	else if (card[end] < index) return 0;

	int mid = (start + end) / 2;

	int left = isExist(start, mid, index);
	int right = isExist(mid + 1, end, index);
	
	return left + right;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int input;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		card.push_back(input);
	}
	sort(card.begin(), card.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		cout << isExist(0, card.size() - 1, input) << " ";
	}
	return 0;
}