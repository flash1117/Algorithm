#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;
vector<int> selectNumber;
void Comb(int depth, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < selectNumber.size(); i++)
			cout << selectNumber[i] << " ";

		cout << "\n";
		return;
	}
	else if (depth >= vec.size()) return;


	for (int i = 0; i < vec.size(); i++) {
		selectNumber.push_back(vec[i]);
		Comb(depth + 1, cnt + 1);
		selectNumber.pop_back();

	}

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	Comb(0, 0);

	return 0;
}