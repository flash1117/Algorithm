#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int arr[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}


	return 0;
}