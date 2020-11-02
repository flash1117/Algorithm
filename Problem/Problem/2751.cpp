#include <iostream>
#include <cmath>

using namespace std;

const int ARRAY_SIZE = 1000001;
int N;

void arraySwap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

void setArray(int* ary) {

	for (int i = 0; i < ARRAY_SIZE; i++) {
		ary[i] = rand() % 100;
	}

}

void printArray(int* ary) {
	for (int i = 0; i < N; i++) {
		cout << ary[i] << "\n";
	}
}

void insertSort(int* ary) {

	for (int i = 0; i < ARRAY_SIZE; i++) {

		for (int j = i; j > 0; j--) {

			if (ary[j - 1] > ary[j]) {
				arraySwap(&ary[j - 1], &ary[j]);
			}
			else break;

		}
	}

}

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
			arraySwap(&ary[j], &ary[pivotIndex]);
		}
		else {
			arraySwap(&ary[i], &ary[j]);
		}

	}

	quickSort(ary, start, j - 1);
	quickSort(ary, j + 1, end);

}

void bubbleSort(int* ary) {

	for (int i = 0; i < ARRAY_SIZE; i++) {
		bool change = false;

		for (int j = 0; j < ARRAY_SIZE - i; j++) {

			if (ary[j] < ary[j - 1]) {
				change = true;
				arraySwap(&ary[j], &ary[j - 1]);
			}
		}

		if (change == false) {
			cout << i << "\n";
			break;
		}
	}


}

void merge(int* tempArray, int* ary, int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int index = start;

	while (i <= mid && j <= end) {

		if (ary[i] < ary[j]) {
			tempArray[index++] = ary[i++];

		}
		else {
			tempArray[index++] = ary[j++];
		}

	}

	if (i > mid) {

		for (int k = j; k <= end; k++) {
			tempArray[index++] = ary[k];
		}
	}
	else {

		for (int k = i; k <= mid; k++) {
			tempArray[index++] = ary[k];
		}

	}

	for (int k = start; k <= end; k++) {
		ary[k] = tempArray[k];
	}
	return;
}

void mergeSort(int* tempArray, int* ary, int start, int end) {

	if (start < end) {

		int mid = (start + end) / 2;
		mergeSort(tempArray, ary, start, mid);
		mergeSort(tempArray, ary, mid + 1, end);
		merge(tempArray, ary, start, end);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cout.tie(0);

	cin >> N;
	int ary[ARRAY_SIZE];
	int tempArray[ARRAY_SIZE];

	mergeSort(tempArray, ary, 0, N - 1);
	
	printArray(ary);


	return 0;
}