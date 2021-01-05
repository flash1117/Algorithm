#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

void quickSort(int* ary, int start, int end) {

	if (start >= end) return;

	int i = start + 1, j = end;
	int pivotIndex = start;

	while (i <= j) {

		while (i <= end && ary[i] <= ary[pivotIndex]) {
			i++;
		}

		while (j > start && ary[j] >= ary[pivotIndex]) {

			j--;
		}

		if (i > j) {
			int temp = ary[j];
			ary[j] = ary[pivotIndex];
			ary[pivotIndex] = temp;
			
		}
		else {
			int temp = ary[j];
			ary[j] = ary[i];
			ary[i] = temp;
		}

	}

	quickSort(ary, start, j - 1);
	quickSort(ary, j + 1, end);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}


	return 0;
}