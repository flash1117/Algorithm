#include <iostream>

using namespace std;

int head = 1;

int getDigit(int n) {

	int cnt = 0;
	
	while (n) {
		n /= 10;
		cnt++;
		if(n != 0) head *= 10;
	}

	return cnt;
}

int main() {

	int N, digit, ret =0, numDigit = 9;
	cin >> N;

	digit = getDigit(N);

	for (int i = 1; i < digit; i++) {
		ret += i * numDigit;
		numDigit *= 10;
	}

	ret += (N - head + 1) * digit;
	cout << ret << "\n";

	return 0;
}