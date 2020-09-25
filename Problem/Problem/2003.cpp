#include <iostream>

using namespace std;

int arr[10000];

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int left = 0, right = 0;
	int sum = 0;
	int ret = 0;

	while (left <= right) {

		if (sum >= m) sum -= arr[left++];
		else sum += arr[right++];

		if (sum == m) ret++;
		if (right == n && sum <= m) break;
	}

	cout << ret << "\n";
	return 0;
}