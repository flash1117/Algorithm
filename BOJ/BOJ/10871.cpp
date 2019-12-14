#include <iostream>

using namespace std;

int N, X;

int main() {

	int input;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input < X) cout << input << " ";
	}

	return 0;
}