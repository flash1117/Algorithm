#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int pick[8];
void solve(int depth, int cnt) {

	if (depth > n) return;
	else if (cnt == m) {

		for (int i = 0; i < cnt; i++) {
			cout << pick[i] << " ";
		}
		cout << "\n";

		return;
	}

	pick[cnt] = arr[depth];
	solve(depth + 1, cnt + 1);
	solve(depth + 1, cnt);

	return;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	solve(0, 0);

	return 0;
}