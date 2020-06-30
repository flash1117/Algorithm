#include <iostream>

using namespace std;

bool isPalindrome(string &input) {

	for (int i = 0; i < input.length()/2+1; i++) {

		if (input[i] == input[input.length() - 1 - i]);
		else return false;
	}

	return true;
}

int main() {

	string input;
	cin >> input;

	if (isPalindrome(input)) cout << 1 << "\n";
	else cout << 0 << "\n";

	return 0;
}