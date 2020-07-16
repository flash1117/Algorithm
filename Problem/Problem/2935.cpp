#include <iostream>

using namespace std;

int main() {

	string input1, input2;
	char ch;

	cin >> input1 >> ch >> input2;

	if (ch == '*') {

		cout << input1;
		for (int i = 0; i < input2.length() - 1; i++) cout << 0;

	}
	else {

		if (input1.length() == input2.length()) {
			cout << 2;
			for (int i = 0; i < input1.length() - 1; i++) cout << 0;
		}
		else if (input1.length() > input2.length()) {
			cout << 1;
			for (int i = 1; i < input1.length() - input2.length(); i++)
				cout << 0;
			cout << 1;
			for (int i = 1; i < input2.length(); i++) cout << 0;
		}
		else {
			cout << 1;
			for (int i = 1; i < input2.length() - input1.length(); i++)
				cout << 0;
			cout << 1;
			for (int i = 1; i < input1.length(); i++) cout << 0;
		}

	}


	return 0;
}