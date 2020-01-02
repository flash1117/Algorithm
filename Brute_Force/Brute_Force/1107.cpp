#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt;
vector <int> vec;
vector <
void solve() {

	int current = 100, cnt = 0;





}

int main() {
	int tmp;
	cin >> N >> M;

	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		vec[tmp] = 11;
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < M; i++) 
		vec.pop_back();
	
	if (N == 100) cout << 0 << "\n";
	else {
		solve();
		cout << cnt << "\n";
	}
	return 0;
}