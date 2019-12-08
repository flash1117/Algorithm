#include <iostream>

using namespace std;

int L, A, B, C, D;

int solve() {

	while (L--) {

		A -= C;
		B -= D;

		if (A <= 0 && B <= 0) return L;
	}

	return -1;
}

int main() {

	cin >> L >> A >> B >> C >> D;
	cout << solve() << "\n";

	return 0;
}