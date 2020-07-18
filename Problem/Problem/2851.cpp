#include <iostream>

using namespace std;

int mushroom[10];

int getDiff(int x) {

	if (x >= 100) return x - 100;
	else return 100 - x;

}

int main() {

	int input;

	for (int i = 0; i < 10; i++)
	{
		cin >> input;
		mushroom[i] = input;
	}

	int sum = 0, prev = 0;
	
	for (int i = 0; i < 10; i++) {

		prev = sum;
		sum += mushroom[i];

		if (getDiff(prev) < getDiff(sum)) {
			cout << prev;
			return 0;
		}

	}

	cout << sum << "\n";
	return 0;
}