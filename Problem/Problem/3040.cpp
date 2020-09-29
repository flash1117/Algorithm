#include <iostream>

using namespace std;
int arr[10];

bool isCorrect(int index1, int index2) {

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		if (i == index1 || i == index2) continue;
		sum += arr[i];
	}

	if (sum == 100) {

		return true;
	}
		
	return false;
}

void print(int index1, int index2) {

	for (int i = 0; i < 9; i++) {
		if (i == index1 || i == index2) continue;
		cout << arr[i] << "\n";
	}
	return;

}
int main() {

	for (int i = 0; i < 9; i++) {

		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {

		for (int j = i + 1; j < 9; j++) {

			bool state = isCorrect(i, j);
			if (state) {
				print(i, j);
				return 0;
			}
		}
	}

	return 0;
}