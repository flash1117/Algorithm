#include <iostream>
#include <vector>

using namespace std;

void solve(vector<pair<int, int>>& input) {

	vector <int> ret;
	for (int i = 0; i < input.size(); i++)
		ret.push_back(1);

	for (int i = 0; i < input.size(); i++) {

		for (int j = i + 1; j < input.size(); j++) {
			if (input[i].first > input[j].first && input[i].second > input[j].second) ret[j]++;
			else if (input[i].first < input[j].first && input[i].second < input[j].second) ret[i]++;
			else continue;
		}
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
}

int main() {

	int N;
	pair<int, int> temp;
	vector <pair<int, int>> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		vec.push_back(temp);
	}
	solve(vec);
	return 0;
}