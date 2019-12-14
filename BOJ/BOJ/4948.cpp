#include <iostream>

using namespace std;

bool primeNum[248000];

void pNum() {

	primeNum[0] = true;
	primeNum[1] = true;

	for (int i = 2; i < 248000; i++) {

		if (!primeNum[i]) {

			for (int j = 2; j <= 248000 / i; j++) {
				primeNum[i * j] = true;
			}
		}
	}
}

int main() {

	int input = 1;
	pNum();
	while (1) {

		cin >> input;
		if (input == 0) break;
		int cnt = 0;
		for (int i = input + 1; i <= 2 * input; i++) {
			if (!primeNum[i]) cnt++;
		}
		cout << cnt << "\n";
	}



	return 0;
}