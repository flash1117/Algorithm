#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	long long fac = 1;
	for (int i = N; i > 0; i--) {
		fac *= i;
	}
	cout << fac;
	return 0;
}