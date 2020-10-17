#include <iostream>

using namespace std;

int arr[1000];
int N;

int getMax(int index1, int index2, int index3, int index4) {

	int _max = index1;
	if (index2 > _max) _max = index2;
	if (index3 > _max) _max = index3;
	if (index4 > _max) _max = index4;

	return _max;
}


int solve() {
	int sum = 0;
	for (int i = 0; i < N; i++) {

		if (i == 0 || i == 1 || i == N - 1 || i == N - 2) continue;
		else {

			int cur = arr[i];
			int compareResult = getMax(arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2]);

			if (cur > compareResult) {

				sum += cur - compareResult;
			}


		}

	}

	return sum;
}


int main() {

	int t = 10, num =0;

	while (t--) {
		num++;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		cout << "#" << num << " " << solve() << "\n";
	}



	return 0;
}