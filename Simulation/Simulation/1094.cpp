#include <iostream>

using namespace std;

int main() {

	int input, q, r, cnt=0;
	cin >> input;

	while (1) {

		r = input % 2;
		if (r == 1) cnt++;
		if (input <= 1) break;

		input /= 2;

	}
	cout << cnt;
	return 0;
}