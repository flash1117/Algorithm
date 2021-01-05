#include <iostream>
#include <cmath>

using namespace std;

void quickSort(int* arr, int start, int end) {

	if (start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {

		while (left <= end && arr[left] <= arr[pivot]) left++;
		while (right > start && arr[right] >= arr[pivot]) right--;

		if (left > right) swap(arr[pivot], arr[right]);
		else swap(arr[left], arr[right]);

	}
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);

}


void print(int* arr) {

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
}

int main() {

	const int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++) {

		arr[i] = rand() % 1000;
	}

	quickSort(arr, 0, ARRAY_SIZE - 1);


	print(arr);


	return 0;
}