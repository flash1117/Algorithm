#include <iostream>

using namespace std;

int main() {

	int T, num=1;
	cin >> T;
	long long input;
	while (T--) {

		ios::sync_with_stdio(false);
		cin >> input;

		long long temp = input / 2;
		cout << "#" << num++ << " " << temp * temp << "\n";

	}

	return 0;
}