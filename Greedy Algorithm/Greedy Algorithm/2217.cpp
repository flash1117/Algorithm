#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, maxWeight;
vector <int> vec;

void solve() {

	sort(vec.rbegin(), vec.rend());

	for (int i = 1; i <= vec.size(); i++) {
		int buf = i * vec[i - 1];
		if (maxWeight < buf) maxWeight = buf;

	}
}

int main() {

	int input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}

	solve();
	cout << maxWeight;
	return 0;
}