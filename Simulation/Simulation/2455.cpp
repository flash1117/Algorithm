#include <iostream>

using namespace std;

int main() {

	int input, output, max=0, temp=0;
	for (int i = 0; i < 4; i++) {
		cin >> output >> input;
		temp -= output;
		temp += input;
		if (temp > max) max = temp;
	}
	cout << max;
	return 0;
}