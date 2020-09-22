#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int temp[9];
bool visited[9];

void solve( int cnt) {

	if (cnt == m) {


		for (int i = 0; i < m; i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		else {
			temp[cnt] = arr[i];
			visited[i] = true;
			solve(cnt + 1);
			visited[i] = false;
		}
	}
	
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	solve(0);
	return 0;
}