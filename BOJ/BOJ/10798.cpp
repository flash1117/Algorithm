#include <iostream>

using namespace std;

string input[5];

int main() {
	int maxLen = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
		maxLen = maxLen > input[i].length() ? maxLen : input[i].length();
	}

	for (int i = 0; i < maxLen; i++) {

		for (int j = 0; j < 5; j++) {

			if (i >= input[j].length()) continue;
			cout << input[j][i];
		}
	}
	return 0;
}