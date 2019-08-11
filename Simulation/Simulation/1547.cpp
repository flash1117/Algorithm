#include <iostream>

using namespace std;

int M;
int cup[4];

void swap(int* a, int* b) {

	int temp =0 ;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main() {

	int input1, input2;
	cin >> M;
	cup[1] = 1;
	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;

		swap(cup[input1], cup[input2]);

	}

	for (int i = 0; i < 4; i++) {
		if (cup[i] == 1) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}