#include <iostream>

using namespace std;

int N, a, b;

int solve() {

	int round = 1;

	while (N) {

		if (b > a && b - a == 1 && b % 2 == 0) return round;
		else if (a > b && a - b == 1 && a % 2 == 0) return round;
		else round++;

		a = a / 2 + a % 2;
		b = b / 2 + b % 2;

		N /= 2;
	}

	return -1;
}

int main() {

	cin >> N >> a >> b;

	cout << solve();

	return 0;
}