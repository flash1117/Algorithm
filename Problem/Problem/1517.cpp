#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int, int>> vec;
int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {

		pair<int, int> input;
		cin >> input.first;
		input.second = i;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());
	int _sum = 0;
	for (int i = 0; i < N; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
		_sum += abs(vec[i].second - i);
	}

	cout << _sum / 2 + 1 << "\n";

	return 0;
}