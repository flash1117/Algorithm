#include <iostream>

using namespace std;

int n, s;
int arr[100001];
const int INF = 987654321;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}

	int sum = 0, left = 0, right = 0;
	int ret = INF;

	while (left <= right) {

		if (sum >= s) {
			ret = ret > (right - left) ? (right - left) : ret;
			sum -= arr[left++];
		}
		else if (sum < s) {
			sum += arr[right++];
		}
		
		if (right == n && sum < s) break;
	}

	if (ret == INF) cout << 0 << "\n";
	else cout << ret << "\n";

	return 0;
}