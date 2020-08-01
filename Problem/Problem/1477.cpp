#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(vector<int>& v, int dist) {

	int r = 0;
	for (int i = 1; i < v.size(); ++i) {
		r += (v[i] - v[i - 1] - 1) / dist;
	}
	return r;

}

int main() {

	int n, m, L;
	scanf("%d %d %d", &n, &m, &L);
	vector<int> v = { 0, L };
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int low = 0, high = L;
	while (low <= high) {
		int mid = (high + low) / 2;
		if (count(v, mid) > m) low = mid + 1;
		else high = mid - 1;
	}
	printf("%d", low);
	return 0;
}