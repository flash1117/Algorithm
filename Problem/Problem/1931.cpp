#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<pair<int, int>> vec(N);
	for (int i = 0; i < N; i++) {

		cin >> vec[i].first >> vec[i].second;

	}

	sort(vec.begin(), vec.end(), compare);

	int lastIndex = 0, ans = 0;

	for (int i = 0; i < vec.size(); i++) {

		if (lastIndex <= vec[i].first) {
			lastIndex = vec[i].second;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}