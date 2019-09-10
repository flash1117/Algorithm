#include <iostream>

using namespace std;

int N;

int searchCreate() {

	int creator = 1;

	while (1) {

		int temp = creator;
		int sum = creator;

		while (temp) {

			sum += temp % 10;
			temp /= 10;
		}

		if (creator == N || sum == N)
			break;

		creator++;

	}
	return creator;

}

int main() {

	cin >> N;
	int result = searchCreate();

	if (result == N)
		cout << 0;
	else
		cout << result;
	return 0;

}